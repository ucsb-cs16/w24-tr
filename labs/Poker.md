# Poker

In this lab,  you'll write a class and a function  that work with playing cards.
This lab has the same general structure as the Library lab: first you write some
supporting code, and then you use that code to solve a problem:

- First you'll write a data structure that holds a list of playing cards.
- Then you'll write a function that finds poker hands in a list of cards.

To ensure that you're using your list class to store cards, _you may not use any
container types from the standard library._  You can use arrays  (these are part
of the language,  not the library),  but library classes  that hold items  (like
`std::vector`, `std::list`, or `std::map`) are not allowed.


## The Cards

This lab uses a `Card` type to represent playing cards,  as found in a [standard
fifty-two card deck][cards].  Each card has a `rank` (2 through 10, jack, queen,
king, or ace) and a `suit` (clubs, diamonds, hearts, or spades).

The `Card` struct is written for you. You can find it in `Card.h`, which you can
download from  GitHub [here](files/Card.h).  You'll need to turn in  this file -
unmodified - alongside your files when you submit the assignment.

The  `Card.h` file also includes some other useful things.  It has constants for
all of the  ranks and suits  used in the lab,  and it defines operators that let
you compare cards  with the standard  comparison operators.  It also  provides a
`Card::print()` member function that'll print cards in the format the autograder
expects.  Use these whenever you need to compare or print cards.

```cpp
if(card1 < card2) {
  card1.print();
}
else {
  card2.print();
}
```


## The Hand

Your first task  is to implement a class that  can store  a collection of cards.
This class should be called `Hand`,  and it should store cards in  sorted order,
with the highest card at the front of the list (index zero)  and the lowest card
at the back of the list.

The code for your `Hand` class  will be spread over two files,  which you should
create.  For an example of code you'd find  in each file,  see the Example Files
section below.

- In `Hand.h`, you'll declare your `Hand` class,  its member variables,  and its
  member functions.  Don't implement any functions in this file!
- In `Hand.cpp`, you'll implement the member functions you declared in `Hand.h`.

Your `Hand` class should store cards in an array of `Card`s that it allocates on
the heap.  If it ever needs more storage space, it should allocate a new, bigger
array, copy its cards into the new array, and delete the old array.

Your `Hand` also needs some member functions so people can interact with it.  It
should provide all of the following public member functions.

- `Hand()` is a default constructor.  It should take no arguments and initialize
  the hand as an empty hand.
- `Hand(const Hand& other)` is a copy constructor. It should initialize the hand
  as a copy of `other`.
- `~Hand()` is a destructor.  It should free all heap memory owned by the hand.
- `void add(Card card)` should add `card` to the hand.
- `void clear()` should remove all cards from the hand.
- `size_t count() const` should return the number of cards in the hand.
- `Card get(size_t index) const`  should return the card at index `index`.  This
  function will only be tested with valid indices.
- `void print() const` should print the cards in the hand in order, separated by
  one  space character.  It should print nothing  after the final card (no space
  and no newline).

Finally, to make the autograder run correctly,  you'll also need a `make_hand()`
function.  This is not  a `Hand` member function.  It should create a new, empty
`Hand` on the heap, and return a pointer to that new hand. Declare this function
in `Hand.h` and add its implementation to `Hand.cpp`:

```cpp
Hand* make_hand() {
  return new Hand();
}
```

You can test your `Hand` functions as soon as you have the fundamental ones done
and the rest stubbed out  (see the Hints section for details).  Upload `Card.h`,
`Hand.h`, and `Hand.cpp` to test your `Hand` class.


## The Best Hand

Your second task  is to write a function that finds the best possible poker hand
in a `Hand` of cards.

```cpp
Hand* best_hand(const Hand& cards);
```

Declare this function in `Hand.h`  (note that like `make_hand()`,  this is not a
`Hand` member function).  Then create a new file called `best_hand.cpp`; this is
where you'll implement the  `best_hand()`  function and any  helper functions it
needs.

The function should take one argument:  a `Hand` containing any number of cards.
It should then find the best possible poker hand that can be made from the input
cards, and return a newly allocated `Hand` containing only the cards involved in
that poker hand.  For example, if the best poker hand it can make is a Pair, the
output `Hand` should only contain two cards.

The function should recognize  all the standard poker hands,  plus an additional
None hand that contains  no cards  (this is the worst possible hand,  and should
only be returned  when the input hand is empty).  There are  ten possible hands,
listed here  from worst to best.  For a more detailed description  of each hand,
and how to order hands of the same type, see [Wikipedia][hands].

- **None**             No cards.
- **High Card**        One card.
- **Pair**             Two cards, both of the same rank.
- **Two Pair**         Two pairs.
- **Three of a Kind**  Three cards, all of the same rank.
- **Straight**         Five cards with consecutive ranks.
- **Flush**            Five cards, all of the same suit.
- **Full House**       Five cards: a three of a kind and a pair.
- **Four of a Kind**   Four cards, all of the same rank.
- **Straight Flush**   A straight with all cards of the same suit.

Some notes on the comparison of hands:

- If you have a choice as to which cards to include in a hand, always choose the
  highest possible cards, as defined by the comparison operators in `Card.h`.
- Wikipedia lists an additional hand type: Five of a Kind. You'll never see this
  hand: you'll never be given duplicate cards, and there are no wild cards.
- The autograder will use your `Hand`'s `print()` function to print the cards in
  the hand.  An ace low straight will print out as `A5432`, and that's okay; the
  autograder is expecting this.


## Hints

- The autograder uses your `Hand` member functions to test your `Hand` class, so
  before you can pass any test cases,  you'll need a constructor,  a destructor,
  an `add()` function,  and a `print()` function.  The other functions will need
  to be there in order to compile on Gradescope, but they can be stubs.
- Instead of operating  directly on the list of cards  passed to  `best_hand()`,
  try sorting these cards into sub-lists.  You could have sub-lists with all the
  cards of one rank, and/or sub-lists with all the cards of one suit.
- The logic for all the N of a Kind hands is pretty much the same. Generalize it
  into a single function if you can!
- Your code will only  be tested with  cards from a single  fifty-two card deck.
  There will never be duplicate cards, and there are no jokers or wild cards.


## Example Files

In class,  I write my `struct`s and `class`es in one piece, with member function
code inside the  class definition.  This keeps everything in one file,  which is
nice for taking notes, but it's better practice to define classes in `.h` files,
and then implement their  member functions in `.cpp` files - it keeps the header
files clean and readable, and it can speed up compilation.

As an example,  here's what the class definition of a  `Thing`  class might look
like.  This code defines the type  and its member variables,  and declares - but
does not implement - its member functions.  This is code you'd find  in a header
file, probably named `Thing.h`.

The `#ifndef`,  `#define`,  and `#endif` make up what's called a "header guard."
This prevents weirdness in the case that  the header file  gets `#include`d more
than once in some `.cpp` file. Without the header guard, the `Thing` class would
be defined twice, and the compiler would get upset.

```cpp
#ifndef THING_H
#define THING_H

#include <string>

class Thing {
  std::string   x;
  unsigned int* y;

public:
  Thing();

  void foo(int i);
  int  bar() const;
};

#endif
```

Here's the  corresponding `Thing.cpp` file.  Note that the member function names
are prefixed with  `Thing::`  when they appear outside of the  class definition.
This tells the compiler that these functions belong to the `Thing` class.

```cpp
#include "Thing.h"

Thing::Thing() {
  // Code...
}

void Thing::foo(int i) {
  // Code...
}

int Thing::bar() const {
  // More code...
}
```


[cards]: https://en.wikipedia.org/wiki/Standard_52-card_deck
[hands]: https://en.wikipedia.org/wiki/List_of_poker_hands
