#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
static int module1_init(void)
{
	struct task_struct *p;
	printk(KERN_ALERT"程序名\t\tPID号\t进程状态  优先级\n");
	for_each_process(p)
	{
		printk(KERN_ALERT"%d\t%d\t    %d\t   %d\n", p->comm, p->pid, p->state, p->prio);
	}
	return 0;
}

static void module1_exit(void)
{
	printk(KERN_ALERT"Module1 has been exited!\n");
}

MODULE_AUTHOR("ChristianSwift");
module_init(module1_init);
module_exit(module1_exit);
MODULE_LICENSE("GPL");
