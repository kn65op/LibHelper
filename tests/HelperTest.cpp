#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Helper.h"
/*
 * Google test
 */

#include "gtest/gtest.h"

/**
 * Helper
 */
TEST(Helper, intToString)
{
  EXPECT_STREQ("1", Helper::intToString(1).c_str());
  EXPECT_STREQ("-1", Helper::intToString(-1).c_str());
  EXPECT_STREQ("234", Helper::intToString(234).c_str());
  EXPECT_STREQ("-234", Helper::intToString(-234).c_str());
  EXPECT_STREQ("5", Helper::intToString(5.6).c_str());
  EXPECT_STREQ("3", Helper::intToString(3.4).c_str());
  EXPECT_STREQ("0", Helper::intToString(-0).c_str());
  EXPECT_STREQ("-1", Helper::intToString(-1.1).c_str());
  EXPECT_STREQ("-2", Helper::intToString(-2.6).c_str());
}

TEST(Helper, doubleToString)
{
  EXPECT_STREQ("1", Helper::doubleToString(1).c_str());
  EXPECT_STREQ("-1", Helper::doubleToString(-1).c_str());
  EXPECT_STREQ("234", Helper::doubleToString(234).c_str());
  EXPECT_STREQ("-234", Helper::doubleToString(-234).c_str());
  EXPECT_STREQ("5.6", Helper::doubleToString(5.6).c_str());
  EXPECT_STREQ("3.4", Helper::doubleToString(3.4).c_str());
  EXPECT_STREQ("0", Helper::doubleToString(-0).c_str());
  EXPECT_STREQ("-1.1", Helper::doubleToString(-1.1).c_str());
  EXPECT_STREQ("-2.6", Helper::doubleToString(-2.6).c_str());
}

int main(int argc, char **argv)
{

  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();

}

