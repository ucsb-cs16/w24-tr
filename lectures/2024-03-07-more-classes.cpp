#include <iomanip>
#include <iostream>
#include <string>

struct Book {
  std::string title;
  std::string author;
  int         year;

  Book() {}

  Book(const Book& other) {
    title  = other.title;
    author = other.author;
    year   = other.year;
  }

  Book(const std::string& title, const std::string& author, int year) {
    this->title  = title;
    this->author = author;
    this->year   = year;
  }
};

struct Time {
private:
  unsigned int mHour;   // 0-23
  unsigned int mMinute; // 0-59

public:
  Time() {
    mHour   = 0;
    mMinute = 0;
  }

  Time(unsigned int hour, unsigned int minute) {
    mHour   = hour   % 24;
    mMinute = minute % 60;
  }

  int hour() const {
    return this->mHour;
  }

  int minute() const {
    return this->mMinute;
  }
};

struct Event {
  Book* book;
  Time time;

  Event(const Event& other) {
    book = new Book(*other.book);
    time = other.time;
  }

  Event(const Book& book, const Time& time) {
    std::cout << "Book::constructor(book, time)\n";
    this->book = new Book(book);
    // this->time = new Time(time);
    this->time = time;
  }

  ~Event() {
    std::cout << "Book::destructor()\n";
    delete book;
    // delete time;
  }
};

std::ostream& operator << (std::ostream& stream, const Book& book) {
  stream << book.title;
  stream << " by " << book.author;
  stream << " (" << book.year << ')';
  return stream;
}

std::ostream& operator << (std::ostream& stream, const Time& time) {
  stream << std::setfill('0') << std::setw(2) << time.hour() << ':';
  stream << std::setfill('0') << std::setw(2) << time.minute();
  return stream;
}

void print_event(Event event) {
  std::cout << "Event:\n  Book: " << *(event.book);
  std::cout << "\n  Time: " << event.time << '\n';
}


int main() {
  Book book;
  book.title  = "Alice in Wonderland";
  book.author = "Lewis Carroll";
  book.year   = 1865;

  Book book2("Commentarii de Bello Gallico", "Julius Caesar", -50);

  Time time(23, 59);
  // time.hour  = 84;
  // time.minute = 118;

  // print(book);
  std::cout << book  << '\n';
  std::cout << book2 << '\n';
  std::cout << time << '\n';

  if(true) {
    // std::cout << "in if\n";
    Event event(book, time);
    print_event(event);
    // std::cout << "leaving if\n";
  }

  // std::cout << "after if\n";

  return 0;
}
