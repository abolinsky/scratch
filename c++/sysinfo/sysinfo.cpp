#include <sys/sysinfo.h>
#include <iostream>

int main(){
  struct sysinfo si;
  sysinfo(&si);

  ::std::cout << "Free RAM: " << si.freeram << ::std::endl; 
  ::std::cout << "Total RAM: " << si.totalram << ::std::endl; 
  ::std::cout << "Free SWAP: " << si.freeswap << ::std::endl; 
  ::std::cout << "Total SWAP: " << si.totalswap << ::std::endl; 

  return 0;
}
