#pragma once

#include <string>

namespace THelper
{
namespace Configuration
{

class Configurator
{
public:
  struct NoSuchParameter
  {

  };
  virtual ~Configurator() {}

  virtual void storeStringParameter(const std::string& parameter, const std::string& value) = 0;
  virtual std::string loadStringParameter(const std::string& parameter) const = 0;
};

}
}
