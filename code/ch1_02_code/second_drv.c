#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>
#include <asm/irq.h>
#include <asm/io.h>
#include <asm/arch/regs-gpio.h>
#include <asm/hardware.h>

#include <linux/device.h>

static struct class *seconddrv_class;
static struct class_device	*seconddrv_class_dev;


static int second_drv_open(struct inode *inode, struct file *file)
{

	return 0;
}

ssize_t second_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{

	return 0;
}


static struct file_operations sencod_drv_fops = {
    .open   =   second_drv_open,     
	.read	=	second_drv_read,	   
};


int major;
static int second_drv_init(void)
{
	major = register_chrdev(0, "second_drv", &sencod_drv_fops);

	seconddrv_class = class_create(THIS_MODULE, "second_drv");

	seconddrv_class_dev = class_device_create(seconddrv_class, NULL, MKDEV(major, 0), NULL, "buttons"); /* /dev/buttons */

	return 0;
}

static void second_drv_exit(void)
{
	unregister_chrdev(major, "second_drv");
	class_device_unregister(seconddrv_class_dev);
	class_destroy(seconddrv_class);

	return 0;
}


module_init(second_drv_init);

module_exit(second_drv_exit);

MODULE_LICENSE("GPL");

