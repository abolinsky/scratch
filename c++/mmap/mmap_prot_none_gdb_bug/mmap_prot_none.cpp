#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <iostream>
#include <cstring>

int main(){

  auto fd = open("test", O_CREAT | O_RDWR);
  if (fd == -1) {
    ::std::cout << strerror(errno) << ::std::endl; 
    return 0;
  }
  auto *mmapped = reinterpret_cast<char *>(mmap(0, 4096, PROT_NONE, MAP_SHARED, fd, 0));
  auto x = *reinterpret_cast<uint32_t *>(mmapped + 4);
  return 0;
}
