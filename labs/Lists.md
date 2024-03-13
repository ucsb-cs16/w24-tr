# Lists

This is a  bonus extension  to the Poker lab.  In this lab,  you'll re-write the
`Hand` class that you used to store playing cards as a different data structure.
This data structure is known as a linked list.

As  in the Poker lab,  you may not use any  container classes  from the standard
library.  This lab also comes  with an additional  restriction:  you may not use
`for` or `while` statements.  All looping must be done with recursion!


## Linked Lists

A linked list is a data structure that stores items in a series of `Node`s. Each
node stores one piece of data (in this case a `Card`),  and has a pointer to the
next node in the list.  The last node in the list  has a null next pointer.  The
list  object itself simply contains  a pointer to the first node.  In memory, it
looks like this:

```
 List              Node               Node               Node
+-----------+     +-----------+      +-----------+      +-----------+
| head = *------->| next = *-------->| next = *-------->| next = *-------X
+-----------+     +-----------+      +-----------+      +-----------+
                  | card = Q♠ |      | card = J♦ |      | card = 7♣ |
                  +-----------+      +-----------+      +-----------+
```


## Support Types

As in the Poker lab,  the `Card` class  that represents playing cards is written
for you.  It lives in a file called  `ListCard.h`,  which you can  download from
GitHub [here](files/ListCard.h).  Turn in this file along with your code.

This file also contains a `Node` struct.  Use this struct  for the nodes in your
linked list.


## The New Hand

Your task is  once again to implement a `Hand` class that stores a collection of
`Card`s in sorted order, with the highest card  at the head of the list  and the
lowest card at the tail.  The implementation of this class  should be split into
two files, which you should create:

- In `ListHand.h`, you'll declare your `Hand` class,  its member variables,  and
  its member functions.  Don't implement any functions in this file!
- In `ListHand.cpp`,  you'll implement all of your  `Hand` member functions, and
  any helper functions those member functions require.

Your  `Hand` class should support  all the member functions from the  Poker lab,
plus one more:  a `head()` function that returns  a pointer to the first node in
the linked list.  The full list is as follows.

- `Hand()` is a default constructor.  It should take no arguments and initialize
  the hand as an empty hand.
- `Hand(const Hand& other)` is a copy constructor. It should initialize the hand
  as a copy of `other`.
- `~Hand()` is a destructor.  It should free all heap memory owned by the hand.
- `void add(Card card)` should add `card` to the hand.  Remember that you should
  store cards in descending order.
- `void clear()` should remove all cards from the hand.
- `size_t count() const` should return the number of cards in the hand.
- `Card get(size_t index) const`  should return the card at index `index`.  This
  function will only be tested with valid indices.
- `const Node* head() const` should return  a pointer to the first `Node` in the
  hand.  If the hand is empty, it should return a null pointer.
- `void print() const` should print the cards in the hand in order, separated by
  one  space character.  It should print nothing  after the final card (no space
  and no newline).

Unlike the Poker lab, you don't need to (and shouldn't!) implement the functions
`make_hand()` and `best_hand()`.


## Hints

- The autograder check for banned keywords is very simple, and can't distinguish
  comments from non-comments.  If the words `for` or `while`  appear anywhere in
  your files, it'll assume you're using banned statements and refuse to compile.
- Most of the  `Hand` member functions  are easiest to implement in pairs.  Each
  `Hand` function can have a recursive helper function (which doesn't need to be
  a member function), and simply call out to that helper function.
- The autograder uses your `Hand` member functions to test your `Hand` class, so
  before you can pass any test cases,  you'll need a constructor,  a destructor,
  an `add()` function, and a `head()` function  (the autograder will use its own
  print function unless it's testing your `print()` function).  The other member
  functions will need to be there in order to compile, but they can be stubs.
- The `head()` function isn't something you would normally make public. Users of
  your `Hand` class shouldn't normally need to know how your structure is set up
  internally.  But here,  it makes sure you're using the correct data structure,
  and it lets the autograder use its own print function, so we expose it.
- Since this `Hand` class  has all the same  member functions  as the `Hand` you
  wrote for the Poker lab, you should be able to switch them seamlessly!  Change
  `best_hand.cpp` to include `ListHand.h` instead of `Hand.h`, recompile against
  `ListHand.cpp` instead of `Hand.cpp`, and everything should still work.
