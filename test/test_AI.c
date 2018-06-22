#include "unity.h"
#include "AI.h"
#include <malloc.h>
#include <string.h>
#include <ctype.h>
//#include <stdio.h>

void setUp(void)
{
}

void tearDown(void)
{
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
  char  *ExpectedReply = "Nice to meet you,Jason";
  char  *Reply 	  = speakToAIMachine("My name is Jason");
  //char  *Reply
}
