#include <stdio.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <errno.h> /* Contains headers for the loadable kernel modul	\
\                                                                               
es. */
#include <linux/kernel.h>
#include <linux/time.h>
int main() {
  struct timespec * ballz;
  // ballz = current_kernel_time();
  int bola = 0;
  bola = syscall(326, ballz);
  printf("time is : %d ", bola);
  return bola;
};
