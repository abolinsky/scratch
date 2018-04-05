#include <string>
#include <iostream>
#include <functional>

class Story {
  public:
  Story(std::string s = std::string("you can do better")) : _s(s) {}
  std::string ToString() {return _s;}

  private:
  std::string _s;
};

class A {
  public:
  A(std::function<void ()> fptr = std::function<void ()>(nowInternal)) : _fptr(fptr) {}

  void now() {
    _fptr();
  }

  static void nowInternal() {
    ::std::cout << Story("original now").ToString() << ::std::endl; 
  }

  private:
  std::function<void ()> _fptr;
};

void replacement() {
  ::std::cout << "replacement now" << ::std::endl; 
}

int main() {
  A a = A();
  a.now();

  A b = A(replacement);
  b.now();
  return 0;
}
