#include <iostream>

static char memory[32];

int main() {
::std::cout << reinterpret_cast<void *>(memory) << ::std::endl;
::std::cout << reinterpret_cast<void *>(memory + 8) << ::std::endl;
::std::cout << reinterpret_cast<void *>(memory + 16) << ::std::endl;
::std::cout << reinterpret_cast<void *>(memory + 24) << ::std::endl;
::std::cout << reinterpret_cast<void *>(memory + 32) << ::std::endl;
*(memory + 31) = 'a';
*(memory + 32) = 'b';
*(memory + 33) = 'c';
::std::cout << reinterpret_cast<void *>(&memory[31]) << ::std::endl;

pthread_create
  clone
}
