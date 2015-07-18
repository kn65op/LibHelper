#pragma once

#include <iostream>

namespace THelper
{

namespace Stream
{

class StreamOperations
{
public:
  static std::string getLineRegardlessLineEnding(std::istream &in);
};

}
}
