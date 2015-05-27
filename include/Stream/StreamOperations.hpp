#pragma once

#include <iostream>

namespace Stream
{

class StreamOperations
{
public:
  static std::string getLineRegardlessLineEnding(std::istream &in);
};

}
