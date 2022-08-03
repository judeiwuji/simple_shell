#include "shell.h"                                                                                                  

#include <stdlib.h>                                                                                                 

                                                                                                    

/**                                                                                                                 
 * main - Concantenates two strings.                                                                             
 * @dest: Pointer to destination string.                                                                            
 * @src: Pointer to source string.                                                                                  
 *                                                                                                                 

 * Return: Pointer to destination string.                                                                           
 */                                                                                                                 

                                                                                                                    
char main(char *dest, const char *src)                                                                          
{                                                                                                                   

        char *destTemp;                                                                                             

        const char *srcTemp;                                                                                        

                                                                                                                    

        destTemp = dest;                                                                                            

        srcTemp =  src;                                                                                             

                                                                                                                    

        while (*destTemp != '\0')                                                                                   

                destTemp++;                                                                                         

                                                                                                                    

        while (*srcTemp != '\0')                                                                                    

                *destTemp++ = *srcTemp++;                                                                           

                                                                                                                    

        *destTemp = '\0';                                                                                           

        return (dest);                                                                                              

                                                                                                                    

}          
