/*  
 *  fizzbuzz.c - FizzBuzz as a Kernel Module
 */
#include <linux/module.h>
#include <linux/kernel.h>

#define MAX 20

MODULE_LICENSE("MIT");

MODULE_AUTHOR("Joe Banks");

MODULE_DESCRIPTION("LKM for running FizzBuzz");

MODULE_VERSION("0.1");

static int __init hello_start(void)
{
  int i;
  printk(KERN_INFO "fizzbuzz: Loading the FizzBuzz module\n");

  for (i = 1; i <= MAX; i++) {
    if (i % 5 == 0 && i % 3 == 0) {
      printk(KERN_INFO "fizzbuzz: FizzBuzz!\n");
    } else if (i % 3 == 0) {
      printk(KERN_INFO "fizzbuzz: Fizz!\n");
    } else if (i % 5 == 0) {
      printk(KERN_INFO "fizzbuzz: Buzz!\n");
    } else {
      printk(KERN_INFO "fizzbuzz: %d\n", i);
    }
  }
    

  return 0;
}
  
static void __exit hello_end(void)
{
  printk(KERN_INFO "fizzbuzz: Unloading the FizzBuzz module.\n");
}
  
module_init(hello_start);
module_exit(hello_end);
