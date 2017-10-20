
#include <linux/linkage.h>
#include <linux/export.h>
#include <asm/uaccess.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <linux/init.h>       /* Contains macros such as __init and __exit. */
#include <linux/module.h>     
#include <linux/kernel.h>
#include <linux/time.h>

asmlinkage int  sys_my_xtime(struct timespec *current_time) {
  struct timespec c_time;
  if(!access_ok(VERIFY_WRITE, current_time, sizeof(struct timespec))) {
    return EFAULT;
  }

  //  struct timespec c_time;
  c_time  =  current_kernel_time();
  current_time = &c_time;
  printk("Current time is : %ld  ", current_time->tv_nsec);

  return 0;
}

EXPORT_SYMBOL(sys_my_xtime);
