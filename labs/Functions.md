# Functions

In this lab,  you'll write three programs.  Factors  is more practice with loops
and conditionals.  Conflict  is about using functions to make tedious tasks like
getting user input and printing  easier and more consistent.  Bit Math  is about
implementing arithmetic using only bit-wise operations;  you'll probably want to
work out some examples on paper before you start coding this one.

Unless stated otherwise,  you can assume that your programs will always be given
valid input.


## Factors

Create a new file called `factors.cpp`.  In this file, write a program that asks
the user for a number, and then prints the prime factors of that number, one per
line, from smallest to largest.

```
[wendy@neverland lab3]$ ./factors
Enter a number:
60
The prime factors of 60 are:
2^2
3
5
```

If the number is divisible by a power of one of its factors, print that power to
the right of the factor, separated by a `^` character.  In the example above, 60
is divisible by two _twice_, so this factor prints as `2^2`.  Just remember that
the `^` operator does _not_ perform exponentiation in C++ programs!

The input  will always fit  in an `int`.  The user may enter a  negative number,
but the prime factors will always be positive.  If the user enters a number with
absolute value less than two,  don't attempt to factor it.  Instead, print `This
number has no prime factors.` and exit.


## Conflict

Create a new file called `conflict.cpp`. In this file, write a program that asks
the user for the start and end times of two classes.  It then prints the times
that it receives, and tells the user whether or not the two classes conflict.

```
[wendy@neverland lab3]$ ./conflict
Class 1 start time:
8:30
Class 1 end time:
9:45
Class 2 start time:
13:00
Class 2 end time:
14:00
Class 1 runs from 08:30 to 09:45.
Class 2 runs from 13:00 to 14:00.
No conflict.
```

The user will enter  all times as they would appear on a  24-hour digital clock:
1:00 PM would be entered as 13:00.  If the classes overlap at all,  your program
should report a conflict by printing `Conflict!` Otherwise, print `No conflict.`
Two classes must overlap for  at least one minute in order to conflict:  a class
that ends at 15:00 doesn't conflict with a class that starts at 15:00.

The user will always input an integer followed by a non-digit character followed
by another integer.  The integers may or may not contain  leading zeros:  `09:7`
should be read the same as `9:07`.  The time entered may not be valid; a time is
invalid if:

- The hour is not between 0 and 23 (inclusive).
- The minute is not between 0 and 59 (inclusive).
- The separator is not a colon (`:`, ASCII code 0x3a).

If the user enters an invalid time, your program should say so and prompt again.
This could happen at any of the four time prompts.

```
[wendy@neverland lab3]$ ./conflict
Class 1 start time:
87:00
Invalid time; try again.
Class 1 start time:

```

The user might also enter an end time that  isn't later than the start time.  In
this case,  your program should  note the error  and have the user re-enter both
times.  This could happen for either of the classes.

```
[wendy@neverland lab3]$ ./conflict
Class 1 start time:
11:30
Class 1 end time:
11:30
Start time must be later than end time; try again.
Class 1 start time:

```

### Hints

- You'll be reading a lot of times.  Write a function to do this!
- You'll also be printing a lot of times.  Write a function to do this too.
- Your program should always print times with  two hour digits.  Midnight should
  print as `00:00`,  1:00 AM should print as `01:00`,  1:00 PM as `13:00`,  etc.
  The `std::setw` and `std::setfill` helpers from the `iomanip` header will make
  this easier.
- Life will be much better if can represent a time in a single variable.  Pick a
  smart representation that lets you do this.  Don't use global variables!
- Classes may start or end at midnight, but they'll never cross it.
- If the user enters an invalid time, they should only need to re-enter that one
  time.  If the user enters an invalid class,  they should only need to re-enter
  the start and end times for that one class.


## Bit Math

Create a new file called `bitmath.cpp`.  In this file, write a program that asks
the user for an operation,  collects its arguments  (which are `unsigned int`s),
then computes the result and prints  all the numbers in binary, hexadecimal, and
decimal.

```
[wendy@neverland lab3]$ ./bitmath
Operation:
add
First operand:
32
Second operand:
57
0b00000000000000000000000000100000  0x00000020  32
0b00000000000000000000000000111001  0x00000039  57
0b00000000000000000000000001011001  0x00000059  89
```

You'll need to support four operations:

- `see` This operation takes one operand, and simply prints it (example below).
- `add` This operation takes two operands, prints both operands, then prints the
  result of adding the two operands together.
- `sub` This operation behaves the same as `add`, but performs subtraction.
- `mul` This operation behaves the same as `add`, but performs multiplication.

Sounds easy?  There's a catch:  **You may not use any of the standard arithmetic
operators.**  The characters `+`, `-`, `*`, `/`, and `%` may not appear anywhere
in your program, and you can only use functions from the  `iostream`, `iomanip`,
and `string` headers.  Implement your own arithmetic functions using the bitwise
operators:  `~`, `&`, `|`, `^`, `<<`, and `>>` (comparison operators are allowed
as well).  All of the inputs are `unsigned int`s (32-bit unsigned integers), and
the output should be  exactly the same as if you had used  the `+`, `-`, and `*`
operators on these `unsigned int`s.

When printing, print leading zeros on your binary and hexadecimal numbers (these
should always have 32 and 8 digits, respectively). Print two spaces between each
representation of a number.  The decimal representation should be left-aligned.

```
[wendy@neverland lab3]$ ./bitmath
Operation:
see
First operand:
283476581
0b00010000111001011000001001100101  0x10e58265  283476581
```

### Hints

- You'll want to implement a print function first,  then add the `see` operation
  and use that to test your print function.  Then write an add function - you'll
  want to use it in all three of the arithmetic operations.
- You can use  `std::hex`,  `std::setw`  and  `std::setfill`  from the `iomanip`
  header to print  hexadecimal numbers with leading zeros.  You'll have to write
  your own binary printing, though.
- You'll need to find replacements for standard loops. You can't use the typical
  `for(int i = 0; i < N; ++i)`  because that uses the  `+` character.  Maybe you
  can use `x <<= 1` where you would normally use `x += 1`?
- Subtraction is tricky,  but there's a clever solution  that uses the fact that
  unsigned integers "wrap around" to zero when they overflow.  Two hints:
  - What time is it  seven hours after four o'clock?  What time is is five hours
    before four o'clock?
  - What is `x + ~x`?  Try this with some "few-bit" unsigned integers  (three or
    four bits is a good place to start) and extrapolate.
- Since the  `*` and `/` characters are banned,  you can't use comments!  But if
  you use good function and variable names, you won't need to.


## Submission

The autograder is (intentionally) slow, so test locally as much as possible.

You can submit your programs one at a time to test them on Gradescope, but make
sure you submit all three together in your final submission!
