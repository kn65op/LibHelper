#include "DateTime/DateIO.hpp"

using namespace DateTime;

std::string DateIO::getTimeStringInFormat(const std::tm* time, const std::string& format)
{
  //Not using put_time as it is not available in GCC4.9
  if (!time)
  {
    throw CouldNotConvert{"Passed nullptr as time"};
  }
  if (format.empty())
  {
    return "";
  }

  char mbstr[256];
  if (std::strftime(mbstr, sizeof(mbstr), format.c_str(), time))
  {
    return mbstr;
  }
  throw CouldNotConvert("Requested format not fills in 256 characters");
}