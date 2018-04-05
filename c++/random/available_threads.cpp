#include <iostream>
#include <thread>

int main(int argc, char const *argv[]) {
  unsigned int num_threads = std::thread::hardware_concurrency();
  std::cout << num_threads << std::endl;
}
