#include "unity.h"
#include "AI.h"
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
}
void test_StringCompare_given_blank_and_blank_exptect_1(void){
    TEST_ASSERT_EQUAL(1,stringCompare("",""));
}
void test_StringCompare_given_Hello_and_Hello_expect_1(void){
  TEST_ASSERT_EQUAL(1,stringCompare("Hello","Hello"));
}

void test_StringCompare_given_MaMbo_juMbO_and_mambo_jumbo_expect_1(void){
  TEST_ASSERT_EQUAL(1,stringCompare("MaMbo juMbO","mambo jumbo"));
}

void test_StringCompare_given_Rambo_and_Rambu_expect_0(void){
  TEST_ASSERT_EQUAL(0,stringCompare("Rambo","Rambu"));
}

void test_StringCompare_given_Hell_and_Hello_expect_0(void){
  TEST_ASSERT_EQUAL(0,stringCompare("Hell","Hello"));
}

void test_StringCompare_given_Hello_and_Hell_expect_0(void){
  TEST_ASSERT_EQUAL(0,stringCompare("Hello","Hell"));
}

void test_StringContains_given_My_name_is_jason_and_My_name_is_expect_1(void){
  TEST_ASSERT_EQUAL(1,stringContains("My name is jason","My name is"));
}
void test_StringContains_given_My_name_is_jason_and_kkkMy_name_is_expect_1(void){
  TEST_ASSERT_EQUAL(0,stringContains("My name is jason","kkkMy name is"));
}
void test_extractName_given_My_name_is_Jason_exptect_Jason(void)
{
  TEST_ASSERT_EQUAL_STRING("Jason",extractName("My name is Jason"));
  //free(extractName("My name is Jason"));
}
void test_extractName_given_123456789ka__Jason_Leong_Xie_Wei_exptect_Jason(void)
{
  TEST_ASSERT_EQUAL_STRING("Jason Leong Xie Wei",extractName("123456789kaJason Leong Xie Wei"));
  //free(extractName("My name is Jason"));
}
void test_concatenateStrings_Given_Hi_and_Jason_exptect_Hi_Jason(void)
{
    TEST_ASSERT_EQUAL_STRING ("Hi Jason",concatenateStrings_wSpace("Hi","Jason"));
  //free(concatenateStrings("Hi","Jason"));
}
void test_concatenateStrings_Given_SOS_and_at_Block_D_exptect_Hi_Jason(void)
{
    TEST_ASSERT_EQUAL_STRING ("SOS at Block D",concatenateStrings_wSpace("SOS","at Block D"));
  //free(concatenateStrings("Hi","Jason"));
}
void test_speakToAIMachine_Given_Hello_Hi_Hey_Greetings_exptect_hi_there_my_name_is_theMachine_What_is_yours(void){
  char  *ExpectedReply = "Hi there! My name is theMachine, What is yours?";
  char  *Reply          = speakToAIMachine("hEllo");
  TEST_ASSERT_NOT_NULL (Reply);
  TEST_ASSERT_EQUAL (strlen(ExpectedReply),strlen(Reply));
  TEST_ASSERT_EQUAL_STRING (ExpectedReply,Reply);

  //free(Reply);
}

void test_speakToAIMachine_Given_My_name_is_Jason_exptect_Nice_to_meet_you_Jason(void)
{
  char  *ExpectedReply = "Nice to meet you, Jason";
  char  *Reply 	  = speakToAIMachine("My name is Jason");
  TEST_ASSERT_EQUAL (strlen(ExpectedReply),strlen(Reply));
  TEST_ASSERT_EQUAL_STRING (ExpectedReply,Reply);

  //char  *Reply
}

void test_speakToAIMachine_Given_bye_expect_Goodbye_have_a_nice_day(void)
{
  char  *ExpectedReply = "Goodbye, have a nice day!";
  char  *Reply 	  = speakToAIMachine("Bye");
  TEST_ASSERT_EQUAL_STRING (ExpectedReply,Reply);
}

// exptect 1. Hi there! My name is theMachine, What is yours?
//         2. Nice to meet you, xxxxxx
//         3. "Goodbye, have a nice day!
void test_combine_three_functions(void)
{
  char  *ExpectedReply1  = "Hi there! My name is theMachine, What is yours?";
  char  *Reply1          = speakToAIMachine("hey");

  TEST_ASSERT_EQUAL (strlen(ExpectedReply1),strlen(Reply1));
  TEST_ASSERT_EQUAL_STRING (ExpectedReply1,Reply1);

  char  *ExpectedReply2 = "Nice to meet you, Mr.NoName";
  char  *Reply2 	  = speakToAIMachine("My name is Mr.NoName");
  TEST_ASSERT_EQUAL (strlen(ExpectedReply2),strlen(Reply2));
  TEST_ASSERT_EQUAL_STRING (ExpectedReply2,Reply2);

  char  *ExpectedReply3 = "Goodbye, have a nice day!";
  char  *Reply3 	  = speakToAIMachine("Bye");
  TEST_ASSERT_EQUAL_STRING (ExpectedReply3,Reply3);
}
