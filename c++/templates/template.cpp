#include <iostream>
#include <string>

/********************************************
 * Replacing virtual methods with templates *
 ********************************************/
template <typename T>
class Clock : public T {
public:
  void now() {
    Clock::nowImpl();
  }
};

class _AlicaClock {
protected:
  void nowImpl() {
    ::std::cout << "Alica Clock" << ::std::endl; 
  }
};

class _StillClock {
protected:
  void nowImpl() {
    ::std::cout << "Still Clock" << ::std::endl; 
  }
};

typedef Clock<_AlicaClock> AlicaClock;
typedef Clock<_StillClock> StillClock;

int main() {
  AlicaClock ac;
  ac.now();

  StillClock sc;
  sc.now();

  return 0;
}
