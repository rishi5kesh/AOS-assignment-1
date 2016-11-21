#include <unistd.h>
#include <stdio.h>
#define SIZE 1024

int main()
{
	//Variable declaration
	long status;
	int index,index2=1,number;
	static int result[SIZE];
	
	//get the number to b factorized from the user
	printf("Enter the number: \n");
	scanf("%d",&number);
	

	//pass the number and the array in which the factors are to be stored to the predefined system call
	status=syscall(326,number,result);


	//To check the status returned by the system call
	//printf("status: %l\n",status);

	printf("The Factors are:\n");

	//loop to print the factors
	for(index=0;index<SIZE;index++)
	{	
		//format the output with 10 factors per line
		if(index2%11==0)
			{
				printf("\n");
				index2=1;
			}


		if(result[index]==0)
			break;
		printf("%d  ",result[index]);
		index2++;
		
	}
	printf("\n");
	



	return 0;
}