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
#include <stdio.h>
#include <regex.h>       
#include <sys/types.h>
#include "acct_info_t.h"

int main(){

int rec;
acct_info_t acct;
FILE *inFile;
regex_t regex;
int reti;
char input[40];
int i;
int choice;

    inFile=fopen("acct_info", "rb");
    
    //tests if file opens correctly
    if (!inFile){ 
	printf("Error: File not openned correctly");
	return 1;
    }
 
    fseek(inFile, sizeof(unsigned int)*2, SEEK_SET);  // skips the position for seek past the two unsigned ints

    printf("Select 1 to enter record number. Select 2 for alpha search\n");
    scanf("%d", &choice);

    switch(choice){
	case 1: 
		printf("Which record would you like?\n");
		scanf("%d", &rec);

		fseek(inFile, sizeof(acct_info_t)*(rec - 1), SEEK_CUR); // there is an entry in the 0 element of the struct
		fread(&acct, sizeof(acct_info_t),1, inFile);
		printf("Account Owner:%s\nRecord Number:%d\nAccount Balance:$%.2f\n",acct.name,acct.number, acct.balance);
	break;

	case 2:
		printf("Please enter alpha search term\n");
		scanf("%s", input);
		/* Compile regular expression */
    		reti = regcomp(&regex, input, REG_ICASE);
		if (reti) {
		printf("Could not compile regex\n");
		    return;
    		}			

		while (!feof(inFile)){
    		
		/* Execute regular expression */
    
		fread(&acct, sizeof(acct_info_t),1, inFile );
        	reti = regexec(&regex, acct.name, 0, NULL, 0);
    	
			if (!reti) {
			printf("\nAccount Owner:%s\nRecord Number:%d\nAccount Balance:$%.2f\n",acct.name,acct.number, acct.balance);
        		}		
   		}

		    /* Free memory allocated to the pattern buffer by regcomp() */
		    regfree(&regex);
     }  


     fclose(inFile);
     return 0;
}


