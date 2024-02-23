# Library Examples

People were asking for examples of  how the XPS functions work,  so I wrote some
up.  Note that the strings in these examples are  all XP strings, and should all
be stored in memory in the XP string format.

Remember that all lengths,  indices,  etc. that are passed as arguments refer to
the  _characters_  stored in the XP strings.  The users who call these functions
don't need  (or want)  to understand the XP string memory format; they just want
to perform some  string operations.  You,  the library author,  are making their
lives easier by taking care of the memory format for them.

### Compare

```cpp
xps_compare("aaa", "zzz")   => -1
xps_compare("zzz", "aaa")   =>  1
xps_compare("abc", "abc")   =>  0
xps_compare("ant", "a")     =>  1
xps_compare("ABC", "abc")   => -1
xps_compare("",    "hello") => -1
xps_compare("",    "")      =>  0
```

### Concat

```cpp
xps_concat("",    "")    => ""
xps_concat("",    "abc") => "abc"
xps_concat("ABC", "")    => "ABC"
xps_concat("abc", "def") => "abcdef"
```

### Find 1

```cpp
xps_find("bananas", "")         => 0
xps_find("bananas", "na")       => 2
xps_find("bananas", "B")        => XPS_NPOS
xps_find("bananas", "bananas")  => 0
```

### Find 2

```cpp
xps_find("bananas", "",   0) => 0
xps_find("bananas", "na", 0) => 2
xps_find("bananas", "na", 3) => 4
xps_find("bananas", "",   5) => 5
xps_find("bananas", "ba", 1) => XPS_NPOS
```

### Get Char

```cpp
xps_getchar("The Cretaceous Period",  0) => 'T'
xps_getchar("The Cretaceous Period",  1) => 'h'
xps_getchar("The Cretaceous Period",  3) => ' '
xps_getchar("The Cretaceous Period", 16) => 'e'
xps_getchar("The Cretaceous Period", 20) => 'd'
xps_getchar("The Cretaceous Period", 21) => ???
```

### Length

```cpp
xps_length("")               => 0
xps_length("@")              => 1
xps_length("goodbye")        => 7
xps_length("Poor Yorick...") => 14
```

### Slice 1

```cpp
xps_slice("Hello!",  0) => "Hello!"
xps_slice("bananas", 2) => "nanas"
xps_slice("bananas", 5) => "as"
xps_slice("OOPS",    7) => ""
xps_slice("",        0) => ""
```

### Slice 2

```cpp
xps_slice("Hello!",   0, 4) => "Hell"
xps_slice("Hello!",   0, 6) => "Hello!"
xps_slice("Hello!",   0, 9) => "Hello!"
xps_slice("falconry", 3, 6) => "con"
xps_slice("gazebo",   5, 2) => ""
xps_slice("gazebo",   7, 9) => ""
```


## Other Functions

### Free

This releases  the memory used to store an XP string.  It's probably a one-liner
that just calls `delete []`.


### From C String

This takes a C string as an argument  (and is the _only_ function in the library
to do so).  It creates a new XP string and returns it. This XP string stores the
same characters that were in the C string, but in the XP string memory layout.


### Set Char

This doesn't return anything.  Instead, it modifies a character in the XS string
that was passed to it.  Indices work exactly as they do in `xps_getchar()`.
