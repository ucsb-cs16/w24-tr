# Syllabus

## Overview

This is an introductory C++ course. The course catalog calls it "Problem Solving
I," but I prefer to think of it as "How to Talk to Computers." We'll cover basic
C++ syntax,  starting with variables and control flow  and working our way up to
arrays and pointers, structs and classes, and basic data structures like vectors
and linked lists.

Lectures will focus on C++ syntax and how to use some basic functions. These are
tools that you'll use to solve programming problems. The labs will give you some
practice putting these tools to work.


## Materials

Everything in this class is optional  except the programming assignments and the
tests. I don't take attendance. Lecture notes will be available on GitHub. There
is no required reading.  There is no  official textbook.  We'll be talking about
fundamental  C++ concepts, and you can find myriad tutorials online  in whatever
format you like best.

If you prefer learning from textbooks, I suggest **Problem Solving with C++** by
Walter Savitch.  This was the  standard textbook for other CS 16 classes  before
they switched to Zybooks.


## Grading

Your grade comes from  two sources.  The majority  comes from weekly programming
assignments, and the rest comes from two tests: a midterm and a final.

Programming assignments  make up  55%  of your final grade.  There will be about
nine  programming assignments:  one per week,  unless there's a test.  All these
assignments are (roughly) equally weighted.

You can turn in any programming assignment up to three days late, but at a price
of  ten percent of your grade per day.  For example, an assignment due on Monday
could earn a maximum of 90% if turned in on Tuesday,  80% on Wednesday,  and 70%
on Thursday.  On Friday or later, it would not be accepted.

Tests make up 45% of your final grade: 20% comes from the midterm, and 25% comes
from the final. The final is cumulative, but with an emphasis on later material.

I may  decide to curve the class;  if I do,  this will apply to  your cumulative
scores at the end of the quarter, and will only be in your favor. Getting 90% of
the possible points guarantees you at least an A-, 80% a B-, and so on.


## Coding

This is a C++ class,  so you'll be coding in C++.  We'll be using C++ 17 (C++ 20
is the latest standard),  so compile your code with the `-std=c++17` flag.  Your
code must compile with no warnings.  Use the `-Wall`,  `-Wextra`,  and `-Werror`
flags to enforce this, and use Makefiles to save yourself some typing.

Your assignments will be  auto-graded on Gradescope,  which is currently running
GCC 11.4.0 in Ubuntu 22.04 containers.  Code written on other platforms may need
slight tweaking to compile correctly on Gradescope. In particular, Mac users may
need to include more header files.

The official development environment for this class is the CSIL computers, which
are running GCC 13.2.1 on Fedora 38. The CSTL (Phelps 3525) computers are set up
the same way, and user files are shared across both labs.  You're welcome to use
your own computer as well,  but we can't promise to provide tech support in this
case.  If you use your own system, the recommended configurations are:

- **Linux**  Install GCC with your package manager and you're ready to go.
- **Mac**  Install the XCode Command Line Tools; this will provide a `g++`
  command that works as expected (and some other useful tools), but it's
  actually Clang underneath.
- **Windows**  Install Ubuntu Linux via WSL.  Once you have an Ubuntu install,
  use its package manager (`apt`) to install GCC.  There's a VSCode plugin that
  will let you edit files inside your Ubuntu install.

In general, I recommend using the command line for as much as possible. Use your
text editor only as a text editor! Some editors (VSCode) try to do too much, and
this will make it harder for you to understand what's really going on.


## Piazza

We'll be using Piazza as a Q&A forum. If you have a question that might apply to
other people as well, it's better to ask on Piazza than to send an email.

If you ask coding questions on Piazza, please:

- Post the smallest section of code that fully describes your problem.
- Include any code as a code snippet, not a screenshot or cell phone photo.
- If you include more than a few lines of your code, make your question private.


## Cheating

All assignments are individual assignments.  Write your own code.  If you decide
to turn in code that you did not write, keep in mind:

- **First Offense:** Zero on the assignment _and_ final grade lowered by one letter.
- **Second Offense:** Fail the class.

The programming assignments  are involved enough  that it's virtually impossible
for anyone to have the same code as you  by accident.  As long as you write your
own code you have nothing to worry about.
