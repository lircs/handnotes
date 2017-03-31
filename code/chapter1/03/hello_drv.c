//first_drv

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

static int hello_drv_init(void)
{
	printk("insmod ok\n");
	
	return 0;
}

static void hello_drv_exit(void)
{
	printk("rmmod ok\n");
}

module_init(hello_drv_init);
module_exit(hello_drv_exit);


MODULE_LICENSE("GPL");
