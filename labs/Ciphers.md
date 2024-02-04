# Ciphers

In this lab,  you'll get practice working with arrays.  You'll use the fact that
strings are essentially arrays of characters to write three simple cryptographic
programs and a character counting program for the game of Scrabble.

All of these programs  read their input as strings, one line at a time, and stop
when there's no more input to read. By far the best way to do this is to use the
`std::getline()` function  as the condition of  a `while` loop.  This function's
return value is "truthy" when it's able  to read a line, so it will keep looping
as long as there's input, then break out of the loop.

```cpp
std::string line;
while(std::getline(std::cin, line)) {
  // do stuff
}
```

To manually send an "end of input" signal while testing, use `Ctrl`+`D` on Linux
and Mac (Ubuntu in WSL counts as Linux),  and use `Ctrl`+`Z` followed by `Enter`
on Windows.


## Caesar

Create a file named `caesar.cpp`.  In this file, write a program that implements
a [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher).

Your program should expect  two command line arguments.  The first argument must
be either  `-e` (for encryption) or  `-d` (for decryption).  The second argument
must be a non-negative integer. If the user provides the wrong number of command
line arguments, if the first argument is not expected, or if the second argument
is  not composed entirely of the digits  `0` through `9`,  print a usage message
and exit with exit code 1 to indicate that there was an error:

```
[julius@gallia lab4]$ ./caesar
USAGE: caesar [-ed] [key]
```

If the user provides valid command line arguments,  your program should read its
standard input one line at a time.  It should then either encrypt or decrypt the
line and print the result. When encrypting, all English letters (`a` through `z`
and `A` through `Z`) should be "rotated right" by the user-supplied key  (an `a`
rotated right 3 would become a `d`,  and a `y` rotated right by 3 would become a
`b`).  Capitalization should be preserved,  and all non-letter characters should
be left unchanged.

```
[julius@gallia lab4]$ ./caesar -e 3
abcdefghijklmnopqrstuvwxyz
defghijklmnopqrstuvwxyzabc
Veni, vidi, vici.
Yhql, ylgl, ylfl.
```

When decrypting, all letters should be rotated left.

```
[julius@gallia lab4]$ ./caesar -d 5
Frtw Anshny Trsnf
Amor Vincit Omnia
```

The key may be greater than twenty-six.  Note that when the key is a multiple of
26, the input should be unchanged.


## Scytale

Create a file named `scytale.cpp`. In this file, write a program that implements
a [scytale](https://en.wikipedia.org/wiki/Scytale) cipher.

Your program  should expect the  same two  command line arguments as  the Caesar
cipher,  but with the additional requirement that the second argument be greater
that zero.  If it is given  invalid arguments,  the program should print a usage
message and exit with exit code 1:

```
[julius@gallia lab4]$ ./scytale
USAGE: scytale [-ed] [key]
```

If given valid arguments, your program should read its input one line at a time,
encrypt or decrypt each line  as if on a scytale  with the user-specified key as
its circumference, and then print the result.  These examples use the middle dot
character (`·`) to mark trailing spaces, but this is just for readability;  your
program should print normal spaces.

```
[julius@gallia lab4]$ ./scytale -e 3
'Twas brillig, and the slithy toves
'glT,iw taahsny d b trtoihvleel sis·
Did gyre and gimble in the wabe;
Dd i tdgh iegm ybwrlaeeb  eai;nn·
```

You can think of a scytale as a grid. The height of the grid is the key provided
by the user, and the width should be as small as possible while still containing
the entire message.  To encrypt, write a message in the grid from left to right,
top to bottom, like English, then read it top to bottom, left to right.

If the length of the message  isn't a multiple of the height of the grid, pad it
with spaces until it is (and thus fills the entire grid); these spaces should be
included in the output.

The first line of the example above corresponds to this grid:

```
'Twas brilli
g, and the s
lithy toves·
```

To decrypt, write the message top to bottom, left to right, then read it left to
right, top to bottom.

```
[julius@gallia lab4]$ ./scytale -d 7
Aiwtov lmehre lsreos  ye g, m  bo
All mimsy were the borogoves,······
Atm huanhorstbdema ge  etor.
And the mome raths outgrabe.
```

The first line of this example corresponds to this grid:

```
All m
imsy·
were·
the b
orogo
ves,·
·····
```

Note that when the key is one, or when it is greater than or equal to the length
of the message,  the input will be unchanged  (although some padding spaces will
be added if the key is greater than the length of the message).


## Scrabble

Create a file named  `scrabble.cpp`.  In this file, write a program that takes a
collection of letters on the command line, then reads in words from the user and
determines whether or not you can make each word from the given letters, like in
the game of [Scrabble](https://en.wikipedia.org/wiki/Scrabble).

Your program should take one command line argument: some letters.  If you run it
with  the wrong number of arguments,  or if the argument contains any non-letter
characters, it should print a usage message and exit with exit code 1:

```
[julius@gallia lab4]$ ./scrabble
USAGE: scrabble [letters]
```

When run with valid arguments, your program should read user input one line at a
time.  Each line should contain exactly one word;  if a line contains non-letter
characters, you should print `Invalid word.` and move on to the next line.  If a
line is valid,  your program should print whether or not you can write that word
using only the characters given on the command line.

```
[julius@gallia lab4]$ ./scrabble Gyroscope
goop
goop: Yes
poses
poses: No
Hello?
Invalid word.
SCP
SCP: Yes
```

You can use any letter as many times as it appears in the command line argument.
In the example above,  you can make `goop` from `gyroscope`, but not `poses`, as
that would require two `s`s and `gyroscope` only has one.

All letters can be input as upper or lower case interchangeably.  You can use an
`a` as an `A` and vice versa.  When printing words, print them as the user typed
them.


## Substitution

Create a file named `substitution.cpp`.  In this file, write a program that uses
a   [substitution cipher](https://en.wikipedia.org/wiki/Substitution_cipher)  to
encrypt or decrypt its input.

Your program should take two command line arguments:  the first argument must be
either `-e` (for encryption) or `-d` (for decryption).  The second argument must
be a twenty-six-character string  containing each letter of the alphabet exactly
once.  If  you run  the program  with the  wrong number of arguments,  or if any
argument is invalid, it should print a usage message and exit with exit code 1:

```
[julius@gallia lab4]$ ./substitution
USAGE: substitution [-ed] [key]
```

If the command line arguments are valid,  your program should read its input one
line at a time, encrypting or decrypting each line and then printing the result.
When encrypting, the letter `A` should be replaced with the first letter of the
key, the letter `B` with the second, `C` with the third, and so on.

```
[julius@gallia lab4]$ ./substitution -e egjhvakrzxpsynbtudmqiclfow
Outside of a dog, a book is man's best friend.
Biqmzhv ba e hbk, e gbbp zm yen'm gvmq adzvnh.
Inside of a dog, it's too dark to read.
Znmzhv ba e hbk, zq'm qbb hedp qb dveh.
```

To make it easier to see what happened in the example above, you can line up the
key with the unmodified alphabet. Each letter in the alphabet maps to the letter
in the key at the same index:

```
abcdefghijklmnopqrstuvwxyz
egjhvakrzxpsynbtudmqiclfow
```

When decrypting,  the first letter  of the key  should be replaced with `A`, the
second letter with `B`, the third with `C`, and so on.

```
[julius@gallia lab4]$ ./substitution -d rptxnfhewgzdkicmbujsavloqy
Leq jecadx ln ervn r jsrixwih rukq?
Why should we have a standing army?
Pntrajn sers lrq ln jrvn kcinq ci terwuj.
Because that way we save money on chairs.
```

The letters of the key can be either upper or lower case (or mixed),  as long as
every  letter of the alphabet is present.  When encrypting and decrypting, match
the case of the input. The key `abcdefghijklmnopqrstuvwxyz` will leave the input
unchanged.


## Submission

The autograder is (intentionally) slow, so test locally as much as possible.

You can submit your programs one at a time to test them on Gradescope, but make
sure you submit all of them together in your final submission!


## Hints

- The `std::getline()`  function consumes  -- but doesn't return --  the newline
  character at the end of each line. The output is expected to end in a newline,
  though, so you'll have to add this yourself.
- The best way to exit with a specific exit code  is to `return` that value from
  `main()`.  The next best way is using `exit()` from the `cstdlib` header.
- The `cctype` header has some useful functions in it, but beware: these are old
  C functions that don't return `bool`s! They return zero for false and non-zero
  for true.
- C++ treats `char`s as signed integers, so watch out for integer overflow.  You
  only need to add 6 to `'z'`  before it wraps around to -128.  Consider storing
  characters as `int`s while doing math on them, then converting back to `char`s
  afterwards.
- The `==` operator doesn't compare C strings  like you probably want it to:  it
  compares  _pointers_,  not the  characters they're  pointing at.  To compare C
  strings,  either use `strcmp()` from the `cstring` header  or convert at least
  one of them to C++ `std::string`s and use the `==` operator on those.
- The `std::string`'s `length()` function  returns an unsigned integral type  (a
  `size_t`).  The compiler doesn't like it when you  compare unsigned and signed
  integers, so make your loop indices  `unsigned int`s or `size_t`s  when you're
  looping over strings.
- Encrypting and then decrypting any message  with the same key  should give you
  back the original message (maybe plus some padding, in the case of Scytale).
- How many of these ciphers  actually need separate functions for encryption and
  decryption?
