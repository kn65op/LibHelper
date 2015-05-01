#pragma once

#include <string>
#include <map>

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

  void storeStringParameter(const std::string& parameter, const std::string& value);
  std::string loadStringParameter(const std::string& parameter) const;

private:
  using Container = std::map<std::string, std::string>;
  Container values;
};

}
}
