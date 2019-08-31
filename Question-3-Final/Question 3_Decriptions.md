Program Objectives:

This C program invokes external applications and prints their outputs. The mentioned applications are the programs developed in questions 1 and 2. 

Code Structure:

The main program execute application 1. To this end, the number of input text files is read (nfile), and their names are set as arguments to main function (see Fig. 1 in the folder 
Question-3-Final). The name of arguments are transformed to strings and then are set as arguments of application 1 using fork() and execv()function.
The excecutable forms (.out) of application 1 and 2 are needed (Appl-1.out and Appl-2.out). They are obtained from running the applications and are coppied to the folder of 
Question-3-Final.
It should be noted that after end of each run of the program, the generated output of application 1 (Result_Application_1) should be removed to supress excessive input data for
application 2.      

The description commnets for diffrent parts of the program are included in the source code.

Verification Example:

One example is solved using this program, and the results are shown in Fig.1. In this case, two input files are introduced into the main program.