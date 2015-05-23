#pragma once

#include <string>
#include <ctime>
#include <stdexcept>

namespace DateTime
{

class DateIO
{
public:
  class CouldNotConvert : public std::logic_error
  {
  public:
    CouldNotConvert(const std::string& msg) : std::logic_error(msg)
    {}
  };
  std::string getDateStringInFormat(const std::tm* time, const std::string& format);
};

}
