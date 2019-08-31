/*
  This Program invokes external applications 1 and 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i, j, k, nfile, status;
    char str1[10][100], str2[10][100];
    char *args_1[3], *args_2[3];
    pid_t p, Q;


    printf("Enter the number of files\n");    // number of input files is read from user and saved in nflie
    scanf("%d", &nfile);

    
    
    strcpy(str1[0],"Appl-1.out");             // setting the first argument of Application 1


    for(i=0;i<nfile;i++)
        strcpy(str1[i+1],argv[i+1]);           // The name of each file is copied to a string

    


    for(i=0;i<nfile;i++){                    // The generated string including the name of input files is set as
                                            //       the arguments for Application 1
        
    p = fork();                              // forking process for running Application 1  
    if(p==-1)
    
        printf("There is an error while calling fork()");
    
    if(p==0)
    {
    
    args_1[0] = str1[0]; 
    
    args_1[1] = str1[i+1]; 

    args_1[2] = NULL;


    execv("Appl-1.out", args_1);          // excecuting Application 1

    printf("\nif this prints excev() has failed\n");
    }
    
    
    }

    if (waitpid(p, &status, 0) > 0)             // if condition to assure excecustion completion of child process (Application 1)
    {

   
    Q = fork();                                 // forking process for running Application 2  
    if(Q==-1)
    {
        printf("There is an error while calling fork()");
    }
    if(Q==0)
    {
    
    args_2[0] = "Appl-2.out";

    args_2[1] = "Result_Application_1.txt";   // The output of application 1 is set as the input file for application 2.

    args_2[2] = NULL;
    
    
    execv("Appl-2.out", args_2);               // excecuting Application 2

    printf("\nif this prints excev() has failed\n");

    }
    
        
    }


    return 0;
}
