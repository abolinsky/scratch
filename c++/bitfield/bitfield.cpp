#include <iostream>

struct Bitfield {
  unsigned int a : 12;
  unsigned int b : 12;
  unsigned int c : 3;
  unsigned int d : 1;
  unsigned int e : 1;
  unsigned int : 3;
};

int main() {
  if(__builtin_expect(sizeof(Bitfield) == 4, true)){
    ::std::cout << "Bitfield is 4 bytes long" << ::std::endl;   
  }
  return 0;
}
