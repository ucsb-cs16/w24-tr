# Hello World

Welcome to CS 16!  This first lab  will make sure you're set up to edit, compile
and submit C++ code. If everything goes well, you'll end up with a classic first
program that prints `Hello world!` to the console:

```
[alice@wonderland lab1]$ ./a.out
Hello world!
```

I recommend doing as much of this lab as you can on the command line.  If you're
new to this, you might want to keep a [Bash Cheatsheet][bash] up in your browser
for reference.



### Find a Computer

Before you can do anything, you'll need a computer to work on. The CSIL and CSTL
(Phelps 3525) computers are provided for your use, and have all the programs you
need installed already.  If you don't have a login, create one [here][csil].

If you want  to work on your own computer,  you'll need to  install `g++` so you
can compile your code.  The [syllabus](../Syllabus.md) has suggestions on how to
do this.


### Make Some Directories

Open up a terminal window.  You should be in your home directory by default; use
the `pwd` (print working directory) command to make sure.

You'll need some directories to keep your code organized.  First use the `mkdir`
command to create  a folder to hold all of your CS 16 files, then `cd` into that
directory and create a subdirectory to hold the files for this lab.

Give these folders sensible names.  Avoid using spaces in filenames.


### Write Some Code

In a text editor,  create a file named `hello.cpp`.  Save it in the subdirectory
you created in the previous step. Then start writing your code. It's a good idea
to start with a "stub" `main()` function:

```cpp
int main() {

}
```

The `main()` function  should print  `Hello world!`  (followed by a newline), so
add the code to do that next:

```cpp
std::cout << "Hello world!\n";
```

Once that's done,  I like to add an explicit return statement,  even though this
isn't strictly required for  `main()`  functions  (they're a special case).  The
return value zero means success:

```cpp
return 0;
```

And finally, since you printed something to the console,  you'll need to include
the IO (input/output) header  so the compiler knows about the `std::cout` stream
and its `<<` operator:

```cpp
#include <iostream>
```

That's all you need.  Remember to save your file!


### Compile and Run

Your code  should now be ready to compile.  In the console, `cd` into the folder
you created  to hold  this lab's files.  Run  `ls`  to list the  contents of the
folder; you should see your `hello.cpp` file from the previous step.

Then compile!  Run:

```sh
g++ hello.cpp
```

If you see  error messages,  something went wrong.  Read the messages carefully,
fix your code, save, and try again.  If there is no output, everything worked.

Since we didn't tell `g++` what to name its output program,  it'll create a file
called `a.out`  (or `a.exe` on Windows) in the current directory by default.  If
you run `ls` again, you should this file.  Run your program by running:

```sh
./a.out
```

You should get the output you expect. If you don't, you have another bug to fix.
Edit your file, recompile, and rerun your program to try again.


### Submit to Gradescope

You're now  ready to submit.  In a browser,  go to the class Gradescope page and
upload your `hello.cpp` file as your submission for the first assignment.  After
a few minutes,  you'll see the  Gradescope output:  if there are any compilation
errors or output mismatches, you'll see those here.


[bash]: https://xavierholt.github.io/cheatsheets/bash.html
[csil]: https://accounts.engr.ucsb.edu/create
