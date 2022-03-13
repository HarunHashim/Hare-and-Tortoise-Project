# TORTOISE AND HARE PROJECT
This is a project I wrote in C to implement the concepts I learned when learning C programming language.  

These concepts include :
-> Multi -threading in C. ( Use of semaphore ad mutex)  
-> Memory allocation and deallocation  
-> Use of queues and linked lists to store data.  
-> Separation of code into header files and source files.  


# The files for this project

->makefile.  
->defs.h 	- contains all structure  and fuctions references used in the program .  
->deque.c 	- contains functions used to manipulate the deque  
->main.c 	- main control flow of the program.  
->fight.c 	- the fight function.  
->fighter.c	- contains all functions used to manipulate and initiallize  fighter types.  
->threads.c - contains all the thread functions used in the program.  
->stats.c 	- contains all the functions used to manipualte and initialize  statistics.  
->specs.c	- contains all the functions used to manipulate and initialize  specs .  


# The purpose of this program and how it works

The purpose of this program is to simulate a pirate war. To breifly describe, it is a battle which happens between
pirate and two heroes namely the tortoise and the hare. Each of this hero is supposed to tackle the pirates from 
one end while the other does the same on the other end . The battle continues until either all the pirates have 
been defeated, or both heroes have perished in the attempt. This battle happens over three different scenarios , 
where one of the heroes have a sword and none of the heroes have a sword. Inorder to simulate this program over 
many runs as quickly as possible we used multi-threading.

The pirates are stored in a deque which can be accessed from both ends. Instead of having the heroes take turns fighting individually , I used multi threading inorder to simulate a fight happening in both ends of the deque at the same time . This quickens the whole fight thus results are generated faster.


As for the output of this program, it will generate a table displaying what percentage of the runs resulted in a success , failure ( meaning both heroes died before the pirates where finished off ) or partial success(meaning one of the heroes died) for each of the three scenarios. The number of runs by default is one hundred but can be specified in the arguments as will be shown in the execution instructions below.

There is an image illustrating the general flow of this program to see how the data is generated .

# Launching Instructions:

-> Once in the terminal , move in to the project directory type in "make" into the command line inorder to create the program's executable.  
-> The executable is called "project".  
-> Once you have made the program , type in "./project" inorder to run the program.  
-> The program runs with default 100 runs. If you want to change the number of runs , add the number of runs
   you would like to run into the command line after the executable.   
   For example : "./project 50"  will execute program with 50 runs instead of the default 100.