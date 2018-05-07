//Author: Eric Goodwin
//CS2750 Spring 2016 Assignment 4
//Dr. Sanjiv Bhatia
//
//This program is meant to be an introduction to Unix process handling and file processing.
//You are given a file of accounts that is not sorted in any manner. The file is binary and the structure
//of each record is:
//typedef struct
//{
//char name[40];
//int number;
//float balance;
//} acct_info_t;
//The file has a header as well which is two integers long.  This header is meant to verify the file type
//with a magic number and gives the number of records. Thus the structure of the file can be described
//as:
//unsigned int    magic_num;
//unsigned int    num_rec;
//acct_info_t     acct[num_rec];
//Your job is to tell me the balance at a given record number.  Since it is a binary file, you can search
//different areas of the file using different processes.
//You should not be using sequential read through the file but go straight to the record using fseek(3C).
//Bonus 25 points: You can earn 25 extra points by performing a regular expression search of names using
//regexec(3).i

#include <stdio.h>
#include "acct_info_t.h"


int main(){

int rec;
acct_info_t acct;
FILE *inFile;
   
    inFile=fopen("acct_info", "rb");
    
    if (!inFile){ //tests if file is open correctly
	printf("Error: File not openned correctly");
	return 1;
    }

    printf("Which record would you like?");
    scanf("%d", &rec);

    fseek(inFile, sizeof(unsigned int)*2, SEEK_SET);  // skips the position for seek past the two unsigned ints
    fseek(inFile, sizeof(acct_info_t)*(rec - 1), SEEK_CUR); // there is an entry in the 0 element of the struct
    fread(&acct, sizeof(acct_info_t),1, inFile);
    printf("Account Owner:%s\nRecord Number:%d\nAccount Balance:%.2f\n",acct.name,acct.number, acct.balance);


   fclose(inFile);

   return 0;
}

