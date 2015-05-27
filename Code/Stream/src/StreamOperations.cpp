#include "Stream/StreamOperations.hpp"

using namespace Stream;

std::string StreamOperations::getLineRegardlessLineEnding(std::istream &in)
{
  std::string line;
  std::getline(in, line);
  auto carriage_return = line.find('\r');
  if (carriage_return != std::string::npos)
  {
    line.erase(carriage_return, 1);
  }
  return line;
}
