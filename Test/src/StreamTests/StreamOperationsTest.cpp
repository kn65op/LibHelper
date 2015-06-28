#include <gtest/gtest.h>
#include <sstream>

#include "Stream/StreamOperations.hpp"

using namespace ::testing;
using namespace THelper;

struct StreamOperationsTest : public Test
{
  using StreamOperations = Stream::StreamOperations;

};

TEST_F(StreamOperationsTest, ShouldReadWithUnixLineEnding)
{
  std::string line_one = "line one";
  std::string line_two= "line two";
  std::string line_ending = "\n";
  std::istringstream input{line_one + line_ending + line_two + line_ending};
  EXPECT_EQ(line_one, StreamOperations::getLineRegardlessLineEnding(input));
  EXPECT_EQ(line_two, StreamOperations::getLineRegardlessLineEnding(input));
}

TEST_F(StreamOperationsTest, ShouldReadWithDosLineEnding)
{
  std::string line_one = "line one";
  std::string line_two= "line two";
  std::string line_ending = "\r\n";
  std::istringstream input{line_one + line_ending + line_two + line_ending};
  EXPECT_EQ(line_one, StreamOperations::getLineRegardlessLineEnding(input));
  EXPECT_EQ(line_two, StreamOperations::getLineRegardlessLineEnding(input));
}


