/*
 * rot13.c: ROT13 cipher test application
 *
 * Authors: Di Li<dil1@andrew.cmu.edu>
 *          Minglei Chen<mingleic@andrew.cmu.edu>
 *          Zhe Shen<zshen@andrew.cmu.edu>
 * Date:    Oct 18 2013, 8:16PM
 */

#include <unistd.h> 
#include <stdlib.h>

#define STDIN  0
#define STDOUT 1


int main(int argc, char *argv[]) {

        char array[256]; 
        int r = 0, w = 0, i = 0, j = 0, tmpargc;                                         
        char tmp = 0;                                                           

        /* Test the argc and argv */ 
        tmpargc = argc + 48;            
        write(1, "argc is :", 9);       
        write(1, &tmpargc, 1);          
        write(1, "\n", 1);              
        for(i = 1; i < argc ; i++) {      
            j = 0;                      
            while(argv[i][j] != '\0')   
                j++;                   
            write(1, argv[i], j);       
            write(1, "\n", 1);        
        } 

                                                                                
        /* Continue read characters from stdin,
         * each time at most 10 bytes.
         */
         while((r = read(STDIN, array, 255)) > 0) {                               
            /* Encrypt the characters */                                          
            for (i = 0; i < r; i++) {                                            
                tmp = array[i];                                                 
                if (tmp >= 'A' && tmp <= 'M') {                                 
                    tmp += 13;                                                  
                }                                                               
                else if (tmp >= 'N' && tmp <= 'Z') {                            
                    tmp -= 13;                                                  
                }                                                               
                else if (tmp >= 'a' && tmp <= 'm') {                            
                    tmp += 13;                                                  
                }                                                               
                else if (tmp >= 'n' && tmp <= 'z') {                            
                    tmp -= 13;                                                  
                }                                                               
                array[i] = tmp;                                                 
           }      
                        
           /* Write to stdout */                                      
           if ((w = write(STDOUT, array, r)) < 0)         
               exit(1);                                                         
        }                                                                       
        /* Check if r is 0 */                                         
        if (r == 0)                                                             
            exit(0);                                                            
        /* System call error */                                                   
        exit(1);                                                                
        return -255;                                                            
}
