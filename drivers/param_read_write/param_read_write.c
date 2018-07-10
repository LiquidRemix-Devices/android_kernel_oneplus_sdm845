/*
 * drivers/param_read_write/param_read_write.c 
 * Fake param_read_write Avengers theme
 * Made by pappschlumpf (Erik Müller)
 */

#include <linux/module.h> 
#include <linux/printk.h> 
#include <linux/kobject.h> 
#include <linux/sysfs.h> 
#include <linux/init.h> 
#include <linux/fs.h> #include <linux/string.h> 

static struct kobject *param_read_write_kobject;
static int cust_flag = 2;

static ssize_t cust_flag_show(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf)
{
        return sprintf(buf, "%d\n", cust_flag);
}

static ssize_t cust_flag_store(struct kobject *kobj, struct kobj_attribute *attr,
                      char *buf, size_t count)
{
        sscanf(buf, "%du", &cust_flag);
        return count;
}


static struct kobj_attribute cust_flag_attribute =__ATTR(cust_flag, 0660, cust_flag_show,
                                                   cust_flag_store);

static int __init mymodule_init (void)
{
        int error = 0;

        pr_debug("Module initialized successfully \n");

        param_read_write_kobject = kobject_create_and_add("param_read_write",
                                                 kernel_kobj);
        if(!param_read_write_kobject)
                return -ENOMEM;

        error = sysfs_create_file(param_read_write_kobject, &cust_flag_attribute.attr);
        if (error) {
                pr_debug("failed to create the cust_flag_attribute file in /sys/module/param_read_write \n");
        }

        return error;
}

static void __exit mymodule_exit (void)
{
        pr_debug ("Module un initialized successfully \n");
        kobject_put(param_read_write_kobject);
}
