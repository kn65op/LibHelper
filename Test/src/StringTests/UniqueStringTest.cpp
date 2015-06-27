#include "String/UniqueString.hpp"
#include <gtest/gtest.h>
#include <string>

using namespace ::testing;

using namespace THelper::String;

struct UniqueStringWithStringTester : public Test
{
  UniqueString<std::string> un;
};

TEST_F(UniqueStringWithStringTester, NewUniqueStringShouldNotBeEmpty)
{
  EXPECT_FALSE(un.empty());
}

TEST_F(UniqueStringWithStringTester, TwoNewUniqueStringShouldHaveBeDifferent)
{
  UniqueStdString un1;
  EXPECT_NE(un.getContent(), un1.getContent());
}

TEST_F(UniqueStringWithStringTester, NewUniqueStringShouldNotChange)
{
  std::string t{"tesT"};
  UniqueString<std::string> un2{t};

  EXPECT_EQ(t, un2.getContent());
}

TEST_F(UniqueStringWithStringTester, UniqueStringShouldBeEqualToUnderlyingTypeInBoothCases)
{
  std::string s{"Test1"};
  UniqueString<std::string> us{s};

  EXPECT_TRUE(s == us);
  EXPECT_TRUE(us == s);
}

TEST_F(UniqueStringWithStringTester, UniqueStringShouldNotBeEqualToUnderlyingTypeInBoothCases)
{
  std::string s{"Test1"};
  std::string other{"Test2"};
  UniqueString<std::string> us{s};

  EXPECT_NE(s, un);
  EXPECT_TRUE(un != s);
}

TEST_F(UniqueStringWithStringTester, TwoNewUniqueStringsShouldNotBeEqual)
{
  UniqueString<std::string> un2;

  EXPECT_NE(un, un2);
}

TEST_F(UniqueStringWithStringTester, AfterDeletionUniqueStringCanBeUseAgain)
{
  std::string s{"test"};
  {
    UniqueString<std::string> us{s};
    ASSERT_EQ(s, us);
  }
  UniqueString<std::string> us{s};
  EXPECT_EQ(s, us);
}

TEST_F(UniqueStringWithStringTester, TwoCategoriesShouldBeAbleToHaveSameString)
{
  std::string base{"test"};
  UniqueStdCategorizedString<0> s_category0{base};
  UniqueStdCategorizedString<1> s_category1{base};
  EXPECT_EQ(s_category0.getContent(), s_category1.getContent());

  UniqueStdCategorizedString<0> s_category0_2{base};
  UniqueStdCategorizedString<1> s_category1_2{base};
  EXPECT_EQ(s_category0_2.getContent(), s_category1_2.getContent());
}

TEST_F(UniqueStringWithStringTester, AfterSettingDefaultNameItShouldBeUsedDuringCreation)
{
  std::string default_string{"new_default"};
  UniqueStdString::setDefaultName(default_string);
  UniqueStdString new_default;
  EXPECT_EQ(default_string, new_default.getContent());
}

TEST_F(UniqueStringWithStringTester, AfterCreationStringShoulBeReAssinged)
{
  const std::string new_value{"new_value"};
  un = new_value;
  EXPECT_EQ(new_value, un.getContent());
}

TEST_F(UniqueStringWithStringTester, WhenTwoUniqueStdStringsAreSetToSameStringItShouldHaveDifferentContent)
{
  const std::string new_value{"new_value"};
  un = new_value;
  UniqueStdString un2;
  un2 = new_value;
  EXPECT_EQ(new_value, un.getContent());
  EXPECT_EQ(new_value + "2", un2.getContent());
}

TEST_F(UniqueStringWithStringTester, ShouldTellIfNameIsAlreadyInUse)
{
  EXPECT_TRUE(UniqueStdString::isStringInUse(un.getContent()));
  EXPECT_FALSE(UniqueStdString::isStringInUse(un.getContent() + "a"));
}

TEST_F(UniqueStringWithStringTester, WhenTwoUniqueStdStringsAreSetToSameStringUsingSafeAssignItShouldThrow)
{
  const std::string new_value{"new_value"};
  un.safeAssign(new_value);
  UniqueStdString un2;
  const std::string un2_before_assigment{un2.getContent()};
  EXPECT_THROW(un2.safeAssign(new_value), StringAlreadyInUse);
  EXPECT_EQ(un2_before_assigment, un2.getContent());
}

TEST_F(UniqueStringWithStringTester, AssigningOwnValueShouldNotChangeValue)
{
  const std::string un_before_assigment{un.getContent()};
  un = un_before_assigment;
  EXPECT_EQ(un_before_assigment, un.getContent());
  un.safeAssign(un_before_assigment);
  EXPECT_EQ(un_before_assigment, un.getContent());
}