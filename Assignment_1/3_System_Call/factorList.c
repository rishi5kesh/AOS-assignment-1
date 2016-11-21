#include <linux/kernel.h>

asmlinkage long sys_factorList(int number, int *factorArray)
{	
	int count,count2=0;

	for(count=2; count<=number/2; count++)
	{
		if(number%count==0)
		{
			factorArray[count2]=count;
			printk("%d",factorArray[count2]);
			count2++;
		}
	}

	return 0;
}