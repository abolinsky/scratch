#include <iostream>
#include <string>

class AlicaClock {
public:
  template <bool still_clock>
  typename std::enable_if<!still_clock>::type now() {
    std::cout << "Alica Clock" << std::endl; 
  }

  template <bool still_clock>
  typename std::enable_if<still_clock>::type now() {
    std::cout << "Still Clock" << std::endl; 
  }
};

int main() {

  AlicaClock ac;
  ac.now<true>(); // Still Clock
  ac.now<false>(); // Alica Clock

  return 0;
}
