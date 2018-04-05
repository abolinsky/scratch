#include <iostream>
#include <cstddef>

int main(int argc, char const *argv[]) {
  std::cout << argc << std::endl;
  for (size_t i = 0; i < argc; ++i) {
    std::cout << argv[i] << std::endl;
  }
}
