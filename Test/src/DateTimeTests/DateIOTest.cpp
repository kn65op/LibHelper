#include "DateTime/DateIO.hpp"
#include <gtest/gtest.h>
#include <chrono>

#include <iostream>

using namespace ::testing;

struct DateIoTest : public Test
{
  DateTime::DateIO date;
};

TEST_F(DateIoTest, getStringInFormatShouldThrowWhenNullPtrPassedAsTime)
{
  EXPECT_THROW(date.getDateStringInFormat(nullptr, "%H"), DateTime::DateIO::CouldNotConvert);
}

TEST_F(DateIoTest, getStringInFormatShouldThrowWhenTooLongFormatIsRequested)
{
  auto now = std::chrono::system_clock::now();
  auto now_time_t = std::chrono::system_clock::to_time_t(now);

  EXPECT_THROW(date.getDateStringInFormat(std::localtime(&now_time_t), "%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A"
      "%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A%A"), DateTime::DateIO::CouldNotConvert);
}

TEST_F(DateIoTest, getStringInFormatShouldNoThrowForNowDay)
{
  auto now = std::chrono::system_clock::now();
  auto now_time_t = std::chrono::system_clock::to_time_t(now);
  EXPECT_NO_THROW(date.getDateStringInFormat(std::localtime(&now_time_t), "%H%M%S"));
}

TEST_F(DateIoTest, getStringInFormatShouldReturnEmptyStringForNoFormat)
{
  auto now = std::chrono::system_clock::now();
  auto now_time_t = std::chrono::system_clock::to_time_t(now);
  EXPECT_EQ("", date.getDateStringInFormat(std::localtime(&now_time_t), ""));
}

TEST_F(DateIoTest, getStringInFormatShouldReturnToday)
{
  std::chrono::system_clock::time_point some_day;
  some_day += std::chrono::hours{12};
  some_day += std::chrono::minutes{44};
  some_day += std::chrono::seconds{01};
  auto now_time_t = std::chrono::system_clock::to_time_t(some_day);


  EXPECT_EQ("0101-134401", date.getDateStringInFormat(std::localtime(&now_time_t), "%m%d-%H%M%S"));
}