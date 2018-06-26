#include "AI.h"
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>

int stringCompare(char *str1,char*str2)
{

  int i = 0;
  int j = 0;
                                  //                           | stop / never enter
  i = strlen(str1) ;             // in loop i/j:5  4  3  2  1  0
  j = strlen(str2) ;                  //  eg     H   E  L  L  O  \0
                                      //  STR 1 : HELLO
                                      //  STR 2 : HELLO

//if(str1!= 0 || *str1 !='\0' ||str2 != 0 || *str2 !='\0')
  if (strlen(str1)==strlen(str2))
	{
	while(i !=0 || j!=0)
  {
    if(toupper(*str1)==toupper(*str2))  // convert both strings to upper case N compare
    {
      str1++;         //str1,2 move to next character
      str2++;
      i--;            // reduce to end the loop
      j--;
    }
    else
    {
      return 0;           // if ptr1 != ptr2 then return 0
    }
  }

  return 1;
  }

  else
  {
    return 0;           // if length of str1 and str2 not equal
  }
}
char *extractName(char *msg){
    // My name is xxxxxx   11 spaces until 1st x
    // because 11 spaces for ptr to reach first char of name
    int i = 11;
    int k = 0;
    char * name;
    char * temp;
    name = malloc(strlen(msg)+1);

    // move the pointer to first char of the name
    for(k=i;k>0;k--)
    {
      temp = &(msg[k]); // k/loop conditions variable must be used inside the loop if not infinite loop
      msg++;
    }
      name = msg;
	    return name;
}

int stringContains(char *str1,char *str2)
{
  // My name is   - 10 characters until 's' / to compare the string without checking for the same
  int i = 10;
  int j = 10;

  while(i !=0 && j !=0)
  {
    if(toupper(*str1)==toupper(*str2))
    {
      str1++;
      str2++;
      i--;
      j--;
    }
    else
    {
      return 0;     // if ptr1 != ptr2
    }

  }
    return 1;       // After complete the loop all char same;
}


char *concatenateStrings_wSpace(char *str1,char *str2)
{
  char *combinedString;
  combinedString = malloc(strlen(str1)+strlen(str2)+1);
  strcpy(combinedString,str1);
  strcat(combinedString," ");
  strcat(combinedString,str2);
  return combinedString;
}


char *speakToAIMachine(char *msg) {

  //If user input greeting words
  if(stringCompare(msg,"hi") == 1 || stringCompare(msg,"hello") == 1 || stringCompare(msg,"hey") == 1 || stringCompare(msg,"greetings") == 1)
  {
    return "Hi there! My name is theMachine, What is yours?";
  }
  //If user input name
  if(stringContains(msg,"My Name is") == 1)
  {
    char*reply;
    reply = malloc(strlen(concatenateStrings_wSpace("My name is",extractName(msg))));
    reply = concatenateStrings_wSpace("Nice to meet you,",extractName(msg));
    return reply;
  }
  if(stringCompare(msg,"bye") == 1)
  {
      return "Goodbye, have a nice day!";
  }

  else
  {
    return 0;
  }

}

//Combine "My name is" and "Jason" by using pointers
/* Method 1 (using poiters sometimes works without using str2)
char *concatenateStrings(char *str1,char *str2)
{

  int i = 0;
  int j = 0;
  i = strlen(str1) + 1; // +1 to add the extra ' '
  j = strlen(str2);
  char * combinedString;
  combinedString = malloc(strlen(str1)+strlen(str2)+1);

  //str1 = My name is
  //str2 = Jason
  combinedString = str1;  // store str 1 to combinedString
  while(i>0)
  {
    combinedString++;
    i--;
  }
  while(j>=0)
  {
    *combinedString = *str2;   // bad memory error?
    // end of str1 + ' ' = str 2
    combinedString++;
    str2++;
    j--;
  }

return combinedString;
}*/
/*char *concatenateStrings_woutSpace(char *str1,char *str2)
{
  char *combinedString;
  combinedString = malloc(strlen(str1)+strlen(str2)+1);
  strcpy(combinedString,str1);
  strcat(combinedString," ");
  strcat(combinedString,str2);
  return combinedString;
}
*/
