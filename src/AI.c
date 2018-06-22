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
      return 0;
    }
  }
  return 1;
  }
  else
  {
    return 0;
  }
}

char *speakToAIMachine(char *msg) {

  //If user input greeting words
  if(stringCompare(msg,"hi") == 1 || stringCompare(msg,"hello") == 1 || stringCompare(msg,"hey") == 1 || stringCompare(msg,"greetings") == 1)
  {
    return "Hi there! My name is theMachine, What is yours?";
  }
  //If user input name
  if(stringCompare(msg,"My Name is Jason") == 1)
  {
    int i = 0;
    int j = 0;
    char *name = extractName(msg);
    char *replymsg = "Nice to meet you,";
    while(i=17 && i>=0)
    {
      replymsg++;           // move the pointer after ','
      i--;
    }  // to remove the '\0'
    while(j = strlen(name) - 1 && j>=0)
    {
      *replymsg = *name ;
      replymsg++;
      name++;
    }
  }
  else
  {
    return 0;
  }
//else if ()

}

char *extractName(char *msg){
    // My name is xxxxxx   11 spaces until 1st x
    // because 11 spaces for ptr to reach first char of name
    int i = 0;
    char * name;
    name = malloc(strlen(msg)+1);

    // move the pointer to first char of the name
    while(i = 11 && i>=0)
    {
      msg++;
      i--;
    }
    while(*msg != '\0')
    {
      *name = *msg;
      msg++;
      name++;
    }

    msg--;
    return name;
}
