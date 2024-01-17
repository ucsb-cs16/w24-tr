# Control Flow

This lab is a set of five programs. They'll give you practice reading user input
and working with basic control flow:  conditionals (`if`, `else if`, and `else`)
and loops (`while` and `for`).

Unless it's stated otherwise,  you can assume that  your programs will always be
given valid input.


## Hello v2.0

Create a new file named  `hello2.cpp`.  In this file, write a program that first
prompts the user  for his or her name,  then prints a  custom greeting  for that
user.  The prompt should be `What's your name?` (followed by a newline), and the
greeting should be `Hello NAME!` followed by a newline, where `NAME` is the name
entered by the user.

Here's one example of what running this program could produce (note that program
output and user input are mixed together in the terminal):

```
[alice@wonderland lab2]$ ./hello2
What's your name?
Alice
Hello Alice!
```

To read input form the terminal,  use the `>>` operator to extract data from the
"input pipe" `std::cin`.  This operator uses  the type  of the variable it reads
into to determine what to read.  For example:

```cpp
int i;
float f;
std::string s;

std::cin >> i; // reads an integer
std::cin >> f; // reads a decimal number
std::cin >> s; // reads a string (one word)
```


## Convert

Create a new file named `convert.cpp`.  In this file,  write a program that asks
the user for a temperature, then converts that temperature to four (semi-)common
temperature units.

The prompt  should be  `Enter a temperature:`  (followed by a newline),  and the
user will enter a number, followed by a space, followed by a capital letter. The
letter specifies a unit.  Supported units are as follows, and the results should
always print in this order, with exactly two digits after the decimal point:

- `C` for Celsius
- `F` for Fahrenheit
- `K` for Kelvin
- `R` for Rankine

```
[alice@wonderland lab2]$ ./convert
Enter a temperature:
98.6 F
= 37.00 C
= 98.60 F
= 310.15 K
= 558.27 R
```

To ensure the correct number of decimal digits, include the `iomanip` header and
add the following line  before printing your results  (C++ has annoyingly quirky
output formatting commands):

```cpp
std::cout << std::fixed << std::setprecision(2);
```


## FizzBuzz

Create a new file called `fizzbuzz.cpp`. Write a program that loops over all the
integers from 1 to 50 (inclusive), and prints a line for each number.  This line
should be one of the following:

- The string `FizzBuzz` if the number is divisible by both three and five.
- The string `Fizz` if the number is divisible by three but not five.
- The string `Buzz` if the number is divisible by five but not three.
- Otherwise, the number itself.

Running the program should produce:

```
[alice@wonderland lab2]$ ./fizzbuzz
1
2
Fizz
4
Buzz
...many lines skipped...
49
Buzz
```


## Diamond

Create a file named `diamond.cpp`.  Write a program that prompts the user for an
integer, and then prints an ASCII art diamond where each side is made up of that
number of slashes:

```
[alice@wonderland lab2]$ ./diamond
Side length:
3
  /\
 /  \
/    \
\    /
 \  /
  \/
```

The left corner of the diamond  should always be flush  against the left edge of
the console.  Use spaces for indentation, but only where necessary: there should
be no spaces to the right of the diamond.  If the user enters a number less than
one, there should be no further output.


## GCD / LCM

Create a file named `gcd-lcm.cpp`. Write a program that prompts the user for two
integers, and then calculates the greatest common divisor (GCD) and least common
multiple (LCM) of those two numbers.

```
[alice@wonderland lab2]$ ./gcd-lcm
Number one:
12
Number two:
42
gcd(12, 42) = 6
lcm(12, 42) = 84
```

You can assume that both inputs will be  greater than zero.  The GCD and LCM are
guaranteed  to fit in `int`s,  but the product  of the two inputs is not;  order
your operations to avoid integer overflow!


## Submission

The autograder is (intentionally) slow, so test locally as much as possible.

You can submit your programs one at a time to test them on Gradescope, but make
sure you submit all five together in your final submission!


## Notes

- The `>>` operator  skips any leading whitespace characters  (spaces, newlines,
  tabs, etc.) when reading from `std::cin`.

- When using the  `>>`  operator to read a `std::string`,  C++ will skip leading
  whitespace, then read one "word": a series of non-whitespace characters.  This
  means that in the first program, the user `Genghis Khan` will get the greeting
  `Hello Genghis!`

- "User input" won't show up in Gradescope  like it does in the terminal, due to
  the way  the autograder works.  It is given  to your program,  though, and you
  should be able  to figure out what it is by  looking at the test case names or
  the expected output.
