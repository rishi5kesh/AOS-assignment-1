#include <unistd.h>
#include <stdlib.h>


char* readInput(int Number_of_Strings, int size_of_column, char *result)
{
      /*Variable Declarations*/
     int row,column,string_limit;
     char temp;
     char final[Number_of_Strings][size_of_column];
     char buffer[size_of_column];
          
         
         
          /*Initializing arrays buffer,final and result*/
          for(row=0;row<Number_of_Strings;row++)
          {
            buffer[row] = '\0';
            for(column=0;column<size_of_column;column++)
          {

              final[row][column]='\0';
          }
          }

          for(row=0;row<Number_of_Strings*size_of_column;row++)
          {
            result[row]='\0';

          }

         for(row=0;row<Number_of_Strings;row++)
         {
          //Reading each Line
            read(0,&buffer,size_of_column);
            for(column=0;column<size_of_column;column++)
            { 

              /*Storing it in a 2D array and removing '/n' 
              read along with the string and replacing with space*/

              if(buffer[column]=='\n')
                { buffer[column]=' ';
                  final[row][column]=buffer[column];
                  break;

                }

              final[row][column]=buffer[column];
            }
           
            
         }



          for(row=0;row<Number_of_Strings;row++)
          { 
            
            //Getting the index at which each string ends
            string_limit=0;
            while(final[row][string_limit]!='\0')
            {           
              string_limit++;
            }
            string_limit--;


            //Reversing string until half so the entire string is reversed
            for(column=0;column<string_limit/2;column++)
          {  if(final[row][column])
                temp=final[row][column];
             final[row][column]=final[row][string_limit-column-1];
             final[row][string_limit-column-1]=temp;

          }
          }

          //Copying the result array to pointer array to return it to the calling function
          string_limit=0;
          for(row=0;row<Number_of_Strings;row++)
          {
            for(column=0;column<size_of_column;column++)
          { 
              if(final[row][column]=='\0')
                break;

              result[string_limit]=final[row][column];
              string_limit++;

          }
          }


         return result;
       

}