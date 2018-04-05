#include <sys/sysinfo.h> // struct sysinfo, sysinfo.freeram, sysinfo.freeswap
#include <sys/mman.h> // mmap, munmap
#include <iostream>

static const auto PAGE_SIZE = 4096;

static struct Dummy{
  char _[PAGE_SIZE];
}* dummy;

int main(){

  const auto MMAP_SIZE = PAGE_SIZE;
  struct sysinfo si;

  auto print = [&](){
    ::std::cout << "RAM: Total{" << si.totalram << "} ... Free{" << si.freeram << "}" << ::std::endl; 
  };

  sysinfo(&si);

  print();

  auto mmap_ptr = mmap(NULL, MMAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0); print();
  if(reinterpret_cast<unsigned long long>(mmap_ptr) == -1){
    ::std::cout << "mmap failed" << ::std::endl; 
    return 1;
  }

  dummy = new(mmap_ptr) Dummy;
  
  print();

  munmap(mmap_ptr, MMAP_SIZE);

  return 0;
}
