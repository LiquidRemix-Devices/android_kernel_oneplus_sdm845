/*
 * drivers/param_read_write/param_read_write.c
 * Fake param_read_write Avengers theme
 * Made by pappschlumpf (Erik Müller)
 */

#include <linux/set_os.h>

#include <linux/init.h>
#include <linux/moduleparam.h>

__read mostly static unsigned int oos_detected = 1;

module_param(oos_detected, uint, 0644);
