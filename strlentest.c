#include "shell.h"                                                                                                  

                                                                                                                   
/**                                                                                                                 
 * main - Returns the length of a string.                                                                       i

 * @s: A pointer to the characters string.                                                                          

 *                                                                                                                  

 * Return: The length of the character string.                                                                      

 */                                                                                                                 

                                                                                                                    

int main(const char *s)                                  
{                                                                                                                   

        int length = 0;                                                                                             

                                                                                                                    

        if (!s)                                                                                                     

                return (length);                                                                                    

        for (length = 0; s[length]; length++)                                                                       

                ;                                                                                                   

        return (length);                                                                                            

}
