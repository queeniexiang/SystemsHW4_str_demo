/* 
Queenie Xiang
Systems pd5
HW4 -- Demonstringing Code
2017-09-28
*/ 

#include <stdio.h>
#include <string.h>    


//char *strchr( const char *str, int ch )
/* 
-IF ch is found in str, strchr returns a pointer to ch (if you choose to print the results, everything after ch will be printed as well)

-strchr takes in str, which is the string you want to check for the occurence of
-strchr takes in ch, which will be an int because it's an ASCII value. You can put in a char for ch and c will convert it ASCII automatically, and vice-versa
//If ch isn't in str, then null will be returned

-You can also search for the null value at the end of the string by searching for '\0'

-This can only return a pointer to the position of ch because by taking in a const char pointer, the function is "promising" to not modify the value stored in str.

-To find the position of where ch starts in str, set a pointer ptr to strchr(str, ch) and do: ptr-str 
*/ 


//char *strstr( const char* str, const char* substr )
/*
-If substr is found in str, strstr returns a pointer to substr 

-The terminating null characters are not compared

-Null will be returned if substr is not found in str
-If substr points to an empty string, str is returned

TLDR: 
-strchr is an alias of strstr 
-BUT: strstr can only search for a pointer to substr, where strchr can directly take a char 
-Thus strstr can only take in an immutable pointer where strchr can take something mutable; 
-strstr doesn't compare terminating null characters whereas strchr does
*/ 

int main(){
  char * string = "Hello world!";

  //note single quote usage 
  char search1 = 'H';
  char search2 = 'h';
  char search3 = '!';
  char search4 = '\0';
  char search5 = ' ';

  //note double quotes usage
  char * search6 = "H"; 
  char * search7 = "h";
  char * search8 = "!";
  char * search9 = "\0";
  char * search10 = " ";

  //Error: both strstr and strchr can only search for and return the pointer to the char being searched for, thus it only points to the starting position of char.
  //If you want to search for multiple chars, you'd have to find and store the position of the first char. Then, start from there and keep repeating the process until you get the desired results. 
  //char search_error = 'He'; 

  //checks to see if the char being searched is present in the string:
  //1 means true, 0 means false
  int boolean1 = (strchr(string, search1) != NULL);
  int boolean2 = (strchr(string, search2) != NULL);

  int boolean3 = (strstr(string, search6) != NULL);
  int boolean4 = (strstr(string, search7) != NULL); 

  //These processes will return the "index" of the char you're searching for 
  char * pos_ptr = strchr(string, search1);
  int pos = pos_ptr - string;

  char * pos_ptr2 = strchr(string, search3);
  int pos2 = pos_ptr2 - string;

  char * pos_ptr3 = strstr(string, search6);
  int pos3 = pos_ptr3 - string;

  char *pos_ptr4 = strstr(string, search8);
  int pos4 = pos_ptr4 - string; 

  
  //Error: can't store results into a variable whose value is mutable 
  //char results = (strchr(string, search1));

  //Okay: can store results into a pointer whose value it points to is immutable 
  char * results_pointer_pos = (strchr(string, search1));
  char * results_pointer_pos2 = (strstr(string, search6)); 


  printf("===================================\n");
  printf("Results of using strchr:\n");
  printf("Results of search1: %s\n", strchr(string, search1)); 
  printf("Results of search2: %s\n", strchr(string, search2));
  printf("Results of search3: %s\n", strchr(string, search3));
  printf("Results of search4: %s\n", strchr(string, search4));
  printf("Results of search5: %s\n", strchr(string, search5));
  //printf("Results of search6: %s\n", strstr(string, search_error));
  
  printf("===================================\n");
  
  printf("Results of using strstr:\n");
  printf("Results of search6: %s\n", strstr(string, search6)); 
  printf("Results of search7: %s\n", strstr(string, search7));
  printf("Results of search8: %s\n", strstr(string, search8));
  printf("Results of search9: %s\n", strstr(string, search9));
  printf("Results of search10: %s\n", strstr(string, search10));
  
  printf("===================================\n");
  printf("Results of using strchr:\n");
  printf("Results of boolean1: %d\n", boolean1);
  printf("Results of boolean2: %d\n", boolean2);
  
  printf("\nResults of using strstr:\n");
  printf("Results of boolean3: %d\n", boolean3);
  printf("Results of boolean4: %d\n", boolean4);
  
  printf("===================================\n");
  
  printf("Results of using strchr:\n");
  printf("The position of %c is at %d\n", search1, pos);
  printf("The position of %c is at %d\n", search3, pos2);
  
  printf("\nResults of using strstr:\n");
  printf("The position of %s is at %d\n", search6, pos3);
  printf("The position of %s is at %d\n", search8, pos4);
  
  printf("===================================\n");

  printf("Results of using strchr:\n");
  printf("Results of results_pointer_pos: %s\n", results_pointer_pos);

  printf("\nResults of using strstr:\n");
  printf("Results of results_pointer_pos: %s\n", results_pointer_pos2);
   
}
