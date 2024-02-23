# Valgrind

Valgrind is a memory checker.  It runs your program in a special virtual machine
and watches what it does with its memory. It detects a wide variety of problems,
from memory leaks to the use of uninitialized variables.

To run your program in Valgrind, compile it with the `-g` flag and then run:

```sh
valgrind --leak-check=full -- path/to/your/executable [arg1, arg2, ...]
```

Valgrind is unfortunately Linux-only, but it is available on the CSIL computers.
I believe it runs in WSL as well.


## Valgrind Errors

This is an incomplete list of  the errors Valgrind can detect,  and their common
causes.

- [Uninitialized Value](#uninitialized-value)
- [Invalid Read or Write](#invalid-read-or-write)
- [Mismatched Allocator and Deallocator](#mismatched-allocator-and-deallocator)
- [Memory Leak](#memory-leak)


### Uninitialized Value

You get this when you use a variable  that you haven't initialized.  When you do
this, you end up using whatever value was stored in that memory previously. This
could be anything, and can cause some very confusing bugs.

Valgrind will tell you the line number where you use the uninitialized variable.
This example is from code that tries to iterate over a linked list  whose `head`
pointer was never initialized.

```
Conditional jump or move depends on uninitialised value(s)
   at 0x10A837: List::count() const (List.cpp:24)
   by 0x10B1A8: main (grader.cpp:57)
```

If the error doesn't happen in a condition, you get a more general uninitialized
value error.  This example is from code that  returned an uninitialized `double`
to the `main()` function;  the error happened when `main()`  tried to print that
value.

```
Use of uninitialised value of size 8
   at 0x4BE4EDC: __mpn_rshift (rshift.S:62)
   by 0x4BED160: __printf_fp_l (printf_fp.c:808)
   by 0x4C069AC: __printf_fp_spec (vfprintf-internal.c:354)
   by 0x4C069AC: __vfprintf_internal (vfprintf-internal.c:1558)
   by 0x4C18519: __vsnprintf_internal (vsnprintf.c:114)
   by 0x495A1FF: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
   by 0x498CBD2: std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_float<double>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, char, double) const (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
   by 0x499CCFD: std::ostream& std::ostream::_M_insert<double>(double) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.30)
   by 0x10E283: main (dict-grader.cpp:103)
```


### Invalid Read or Write

You get this when you access memory  other than a block you allocated.  It often
means that you have an array, and that you used an invalid index to access it --
typically caused by an off-by-one error in a loop.

Valgrind will tell you where this happened,  what size of access it was, how far
outside of the block it was, and where the block was allocated.  This example is
from some code that made a bad read  on line 35 of `FibVec.cpp` (FibVec.cpp:35).
It read an `int`  (size 4)  one index past  (0 bytes after)  the end of an array
that was allocated on line 45 of `FibVec.cpp` (FibVec.cpp:45).

```
Invalid read of size 4
   at 0x10A8CE: FibVec::insert(int, unsigned long) (FibVec.cpp:35)
   by 0x10B709: main (grader.cpp:102)
 Address 0x4dd1d14 is 0 bytes after a block of size 4 alloc'd
   at 0x484A2F3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10A956: FibVec::insert(int, unsigned long) (FibVec.cpp:45)
   by 0x10B709: main (grader.cpp:102)
```

You will also get this error if you use a block of memory after deallocating it.
In this case,  Valgrind will tell you  where the block of  memory was allocated,
where it was deallocated, and where you accessed it afterwards.

```
Invalid read of size 8
   at 0x10BB9D: List::count() const (List.cpp:66)
   by 0x10BB55: List::~List() (List.cpp:57)
   by 0x10D3BC: main (grader.cpp:130)
 Address 0x4dd1da0 is 32 bytes inside a block of size 40 free'd
   at 0x484BB6F: operator delete(void*, unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10C06E: List::remove[abi:cxx11](unsigned long) (List.cpp:114)
   by 0x10BB38: List::~List() (List.cpp:58)
   by 0x10D3BC: main (grader.cpp:130)
 Block was alloc'd at
   at 0x4849013: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10B948: List::insert(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) (List.cpp:17)
   by 0x10CE46: main (grader.cpp:74)
```


### Mismatched Allocator and Deallocator

You get this when you deallocate memory with a method that doesn't correspond to
the method you used to allocate it.

- If you allocate one item with `p = new T(...)`, deallocate it with `delete p`.
- If you allocate an array of items with `p = new T[...]`, deallocate it with `delete [] p`.
- If you allocate raw memory with `p = malloc()` or `p = calloc()`, deallocate it with `free(p)`.

Valgrind  will tell you  both where  the memory  was allocated and  where it was
deallocated, which makes this error pretty easy to track down.  In this example,
memory was allocated with `new[]` on line 7 of `FibVec.cpp` and deallocated with
`delete` on line 11 of the same file.

```
Mismatched free() / delete / delete []
   at 0x484BB6F: operator delete(void*, unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10A7D3: FibVec::~FibVec() (FibVec.cpp:11)
   by 0x10B8BC: main (grader.cpp:152)
 Address 0x4dd0c80 is 0 bytes inside a block of size 4 alloc'd
   at 0x484A2F3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10A79A: FibVec::FibVec() (FibVec.cpp:7)
   by 0x10B295: main (grader.cpp:75)
```


### Memory Leak

You get this when still have allocated memory when your program exits.  It means
you either forgot to clean up a block that you longer needed or that you wrote a
buggy destructor that doesn't deallocate everything it should.

Valgrind can tell you how big the blocks are, and where they were allocated, but
that's  about all,  so this can be tricky to track down.  This example is from a
vector class that doesn't always clean up its old storage space when it resizes.
There were four blocks lost;  Valgrind groups them into "loss records"  based on
where they were allocated.

```
HEAP SUMMARY:
    in use at exit: 188 bytes in 4 blocks
  total heap usage: 31 allocs, 27 frees, 81,528 bytes allocated

84 bytes in 1 blocks are definitely lost in loss record 1 of 2
   at 0x484A2F3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10A8F9: FibVec::insert(int, unsigned long) (FibVec.cpp:36)
   by 0x10AB6A: FibVec::push(int) (FibVec.cpp:63)
   by 0x10B779: main (grader.cpp:118)

104 bytes in 3 blocks are definitely lost in loss record 2 of 2
   at 0x484A2F3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
   by 0x10ACE9: FibVec::remove(unsigned long) (FibVec.cpp:86)
   by 0x10AB19: FibVec::pop() (FibVec.cpp:59)
   by 0x10B26F: pop(FibVec&, unsigned long) (grader.cpp:57)
   by 0x10B70D: main (grader.cpp:110)

LEAK SUMMARY:
   definitely lost: 188 bytes in 4 blocks
   indirectly lost: 0 bytes in 0 blocks
     possibly lost: 0 bytes in 0 blocks
   still reachable: 0 bytes in 0 blocks
        suppressed: 0 bytes in 0 blocks
```
