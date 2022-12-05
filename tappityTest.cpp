/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, reference_length_longer_diff) {
	tappity t("123456789");
	t.entry("1234");
	ASSERT_EQ(5, t.length_difference());
	t.entry("");
	ASSERT_EQ(9, t.length_difference());
	t.entry("12345678");
	ASSERT_EQ(1, t.length_difference());
}

TEST(tappityTest, input_length_longer_diff) {
	tappity t("1234");
	t.entry("12345678");
	ASSERT_EQ(4, t.length_difference());
	t.entry("111111111111");
	ASSERT_EQ(8, t.length_difference());
	tappity t1("");
	t1.entry("abc");
	ASSERT_EQ(3, t1.length_difference());
}

TEST(tappityTest, input_same_length_diff) {
	tappity t("");
	t.entry("");
	tappity t1("abc");
	t1.entry("123");
	tappity t2("happy");
	t2.entry("plain");
	ASSERT_EQ(0, t.length_difference());
	ASSERT_EQ(0, t1.length_difference());
	ASSERT_EQ(0, t2.length_difference());
}

TEST(tappityTest, correct_accuracy) {
	tappity t("");
	t.entry("");

	tappity t1("abcd");
	t1.entry("abcd");

	tappity t2("123abc");
	t2.entry("123abc");

	ASSERT_EQ(100.0, t.accuracy());
	ASSERT_EQ(100.0, t1.accuracy());
	ASSERT_EQ(100.0, t2.accuracy());
}

TEST(tappityTest, incorrect_input_shorter) {
	tappity t("123");
	t.entry("");

	tappity t1("abcdef");
	t1.entry("abc");

	tappity t2("car");
	t2.entry("");

	tappity t3("Fred");
	t3.entry("ab");

	tappity t4("12345678");
	t4.entry("12");

	ASSERT_EQ(0, t.accuracy());
	ASSERT_EQ(50, t1.accuracy());
	ASSERT_EQ(0, t2.accuracy());
	ASSERT_EQ(0, t3.accuracy());
	ASSERT_EQ(25.0, t4.accuracy());
}

TEST(tappityTest, incorrect_input_longer) {

}

TEST(tappityTest, incorrect_same_length){

}

TEST(tappityTest, caps_checking){
	
}