/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password p;
    ASSERT_EQ(1, p.count_leading_characters("Z"));
}

TEST(PasswordTest, empty_string)
{
    Password p;
    ASSERT_EQ(0, p.count_leading_characters(""));
}

TEST(PasswordTest, all_same_characters)
{
    Password p;
    ASSERT_EQ(4, p.count_leading_characters("aaaa"));
}

TEST(PasswordTest, stops_on_different_char)
{
    Password p;
    ASSERT_EQ(2, p.count_leading_characters("aabb"));
}

TEST(PasswordTest, no_repetition)
{
    Password p;
    ASSERT_EQ(1, p.count_leading_characters("abcd"));
}

/* -------- has_mixed_case tests -------- */

TEST(PasswordTest, mixed_case_true)
{
    Password p;
    ASSERT_TRUE(p.has_mixed_case("Abc"));
}

TEST(PasswordTest, all_lowercase)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("abc"));
}

TEST(PasswordTest, all_uppercase)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case("ABC"));
}

TEST(PasswordTest, empty_string_mixed_case)
{
    Password p;
    ASSERT_FALSE(p.has_mixed_case(""));
}