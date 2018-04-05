#include <stdio.h>
#include <numa.h>

int main() {
  if (-1 == numa_available()) exit(0);
  printf("numa is available\n");
  
  printf("num possible nodes: %d\n", numa_num_possible_nodes());
  printf("num configured cpus: %d\n", numa_num_configured_cpus());
  printf("num task nodes: %d\n", numa_num_task_nodes());
  printf("preferred: %d\n", numa_preferred());
}
