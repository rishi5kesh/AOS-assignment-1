#include <unistd.h>
#include <stdlib.h>
#include "readInput.h"








int main()
{
  /*Variable Declarations*/
  int Number_of_strings,size_of_column;
  char Read_Number[5];

         
         write(1,"enter the no. of lines: ",24);

         /*Reading the number of lines from user*/
         read(0,&Read_Number,5);
         Number_of_strings=atoi(Read_Number);

         write(1,"enter the max size of string: ",30);

         /*Reading the maximum size of string from user*/
         read(0,&Read_Number,5);
         size_of_column=atoi(Read_Number);



         /*Dynamically allocating 1D result array*/
         char *result = (char *) malloc(sizeof(char ) *Number_of_strings*size_of_column);

         /*Pass number of lines Number_of_strings as parameter to readInput function and get the result*/
         result=readInput(Number_of_strings,size_of_column,result);

         /*Print the result*/
         write(1,"\nReverse concatenation: \n",25);
         write(1,result,Number_of_strings*size_of_column);
         write(1,"\n\n",2);

         /*Deallocate array*/
         free(result);



return 0;

}