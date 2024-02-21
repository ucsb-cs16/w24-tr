# Library

In this lab, you'll write your first library: a collection of functions that can
be used in multiple programs.  These functions  all work with "XP strings" --- a
not-very-efficient string storage format that I made up. You can find the format
specification in the next section.

This lab has three parts:

1. Understand the XP string storage format.
2. Implement a library of XP string functions.
3. Use your library functions to solve problems.


## XP Strings

An XP string is a way to store text in memory. Like a C string, it's an array of
characters  (and passed around  as a `char*`),  but unlike a C string,  it isn't
terminated with a  null character.  Instead,  it stores its data  as a series of
"chunks," and each chunk is prefixed with its length.

One chunk can be  at most  sixteen bytes.  The first byte of a chunk  stores the
number of characters stored in that chunk, and the following bytes contain those
characters. If the chunk is not full (the first byte is less than 0x0f), then it
is the final chunk in the XP string.  If the chunk is full,  there is guaranteed
to be another chunk after it.

A chunk can store  zero characters;  this is how you represent the empty string,
or the final chunk of a string whose length is a multiple of fifteen.

Here are some examples. The top lines are character values, and the bottom lines
are the characters they represent (or `##` to indicate block length values). For
readability,  each chunk is shown  on its own line,  but in memory these are all
simply long arrays of bytes.

- The empty string:
  ```
  00
  ##
  ```

- A short string that fits in a single chunk:
  ```
  06 48 65 6c 6c 6f 21
  ## H  e  l  l  o  !
  ```

- A longer string that needs two chunks to store it:
  ```
  0f 41 72 73 20 6c 6f 6e 67 61 2c 20 76 69 74 61
  ## A  r  s     l  o  n  g  a  ,     v  i  t  a
  08 20 62 72 65 76 69 73 2e
  ##    b  r  e  v  i  s  .

  ```

- A fifteen-character string with an empty chunk to mark the end:
  ```
  0f 41 43 43 6f 6d 70 6c 69 73 68 6d 65 6e 74 73
  ## A  c  c  o  m  p  l  i  s  h  m  e  n  t  s
  00
  ##
  ```


## Library

The XP string format isn't super intuitive,  so we'll want some helper functions
to make working with XP strings easier.  I've provided function declarations for
these functions in a file called `xps.h`; **this is the only header file you may
include.**  The functions themselves are fairly straightforward:  they're common
operations that you would want to perform on strings.

You can download  `xps.h`  from GitHub:  follow [this link](files/xps.h) and use
the Download Raw File button.

Four of the functions are  input/output (IO)  functions.  These can't be written
without using additional headers, so I've written them for you. You can find the
implementations in a file called `xpsio.cpp`; you can download it from GitHub at
[this link](files/xpsio.cpp).

```cpp
// Input/Output Functions
void   xps_debug(const char* str);
char*  xps_readline();
void   xps_write(const char* str);
void   xps_writeline(const char* str);
```

The remaining functions  perform string operations, and it's up to you  to write
them.  Implement these in a file  called `xps.cpp`.  A more detailed description
of each function can be found in `xps.h`.

```cpp
// String Manipulation Functions
int    xps_compare(const char* lhs, const char* rhs);
char*  xps_concat(const char* lhs, const char* rhs);
size_t xps_find(const char* str, const char* pattern);
size_t xps_find(const char* str, const char* pattern, size_t start);
void   xps_free(char* str);
char*  xps_from_cstr(const char* cstr);
char   xps_getchar(const char* str, size_t index);
size_t xps_length(const char* str);
void   xps_setchar(char* str, size_t index, char c);
char*  xps_slice(const char* str, size_t start);
char*  xps_slice(const char* str, size_t start, size_t stop);
```

Some notes:

- All indices and lengths  refer to the string,  not to the character array used
  to store  the string.  For  example,  the character  at `str[0]`  is stored at
  `data[1]`, because `data[0]` is used to store the length of the first chunk.
- All functions that return a  `char*`  create a new  XP string.  It's up to the
  caller  of those functions to make sure that  memory is released when  it's no
  longer needed.
- With the exception  of the argument to  `xps_from_cstr()`,  all of the `char*`
  arguments  will be XP strings.  You may assume that these functions  will only
  be passed valid XP strings.
- Feel free to add helper functions at the top of `xps.cpp`.

Gradescope has test cases for each individual library function,  so you can test
your library as soon as you've finished it. Or at least you will be able to once
I have the autograder up...


## Programs

Now that you have  a library of functions built,  it's time to use them  in some
programs.  Use your XPS functions to implement the functions described below. To
ensure that you're using your new functions, **the only header file that you may
include is `xps.h`**.

When compiling these programs, you'll need code from three files:  the `xps.cpp`
file you wrote,  the `xpsio.cpp` file  I provided,  and the `.cpp` file that has
your `main()` function (and perhaps some helper functions) in it. To compile all
of these from scratch, you can run:

```sh
g++ -Wall -Wextra -Werror -std=c++17 xps.cpp xpsio.cpp whatever.cpp
```


### Truncate

Create the file `truncate.cpp`. In this file, write a program that reads its
standard input one line at a time, and then:

- If the line is 20 characters or fewer, it prints the line unchanged.
- If the line is longer than 20 characters, it prints the first 10 characters of
  the line, followed by three dots (`...`), followed by the last 7 characters of
  the line.

```
[]$ ./truncate
Hello.
Hello.
O brave new string, that has such letters in it!
O brave ne... in it!
Juust over the limit.
Juust over... limit.
```


### Find & Replace

Create the file `replace.cpp`.  In this file, write a program that takes exactly
two command line arguments.  If given a different number of arguments, it should
print a usage message and exit with exit code one:

```
[]$ ./replace
USAGE: replace [old] [new]
```

If given two command line arguments, it should read standard input one line at a
time,  printing each input line to standard output,  but with all occurrences of
argument  `old`  replaced with argument  `new`.  When it reaches  the end of its
input, it should exit.

```
[]$ ./replace I you
I ate a tomato.
you ate a tomato.
I'm Henry VIII I am I am!
you'm Henry Vyouyouyou you am you am!
Nothing to see here...
Nothing to see here...
```

Note that  characters from  `new`  are not candidates  for replacement.  This is
partly to make the problem easier, and partly to prevent infinite blowup:

```
[]$ ./replace o oo
boots
boooots
```


### Match

Create the file  `match.cpp`.  In this file,  write a program that takes exactly
one command line argument.  If given a different number of arguments,  it should
print a usage message and exit with exit code one:

```
[]$ ./match
USAGE: match [pattern]
```

When given one command line argument,  it should read standard input one line at
a time, and report whether or not that line matched `pattern`.  If the pattern
doesn't contain the character `*`, a line matches exactly when the pattern is a
substring of that line:

```
[]$ ./match the
the
Match!
Atheism
Match!
Theology
No match.
```

If the pattern does contain `*` characters, these have a special behavior: a `*`
can match any number of characters (including zero):

```
[]$ ./match me*and*you
One for me and one for you.
Match!
If you meander you may become stranded.
Match!
```

When testing  patterns that contain `*`,  you may need to put  quotes around the
pattern on the command line.  These quotes won't appear in the argument received
by your program: they're essentially "escape characters" that prevent your shell
from treating them as  [globs](https://en.wikipedia.org/wiki/Glob_(programming))
(which behave almost exactly like they do in this program).


## Submission

When submitting to Gradescope,  you should always upload `xps.h`, `xps.cpp`, and
the `.cpp` files containing any program(s) you want to test. Gradescope will use
its own copy of `xpsio.cpp`.


## Hints

- The library functions are listed alphabetically in the header file, but that's
  not necessarily the best order to implement them in. I recommend starting with
  `xps_getchar()` and `xps_setchar()` (and maybe `xps_from_cstr()`).  Then write
  a `main()` function in `test.cpp` (or whatever) and use  `xps_debug()` to make
  sure everything's working as expected.
- Don't repeat yourself!  If you have a function that does something,  you don't
  need to write code for that thing ever again.  Just call the function.
- You're not being graded on performance, and the test cases aren't too complex.
  Simple, readable code is far better than highly-efficient spaghetti code.
- The  original inspiration for the  XPS format  was the length-prefixed strings
  used by  (many implementations of) the language Pascal.  That's where the name
  came from: eXtended Pascal Strings.  No relation to Windows XP.
- Remember to release your heap memory when you're not using any more!
