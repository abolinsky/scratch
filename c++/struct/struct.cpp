#include <iostream>

struct Dummy {
  unsigned long long a;
  unsigned int c;
  unsigned char b;
};

int main(){
  ::std::cout << sizeof(Dummy) << ::std::endl;   
  return 0;
}
