#pragma once

#include <string>
#include <map>

namespace THelper
{
namespace Configuration
{

class IConfigurator
{
public:
  virtual void storeStringParameter(const std::string& parameter, const std::string& value) = 0;
  virtual std::string loadStringParameter(const std::string& parameter) const = 0;
};

class Configurator : public IConfigurator
{
public:
  struct NoSuchParameter
  {

  };
  virtual ~Configurator() {}

  void storeStringParameter(const std::string& parameter, const std::string& value) override;
  std::string loadStringParameter(const std::string& parameter) const override;

private:
  using Container = std::map<std::string, std::string>;
  Container values;
};

}
}
