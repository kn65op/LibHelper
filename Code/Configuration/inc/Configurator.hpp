#pragma once

#include <string>
#include <map>
#include <utility>

namespace THelper
{
namespace Configuration
{

class IConfigurator
{
public:
  using Container = std::map<std::string, std::string>;
  virtual void storeStringParameter(const std::string& parameter, const std::string& value) = 0;
  virtual std::string loadStringParameter(const std::string& parameter) const = 0;
  virtual std::pair<Container::const_iterator, Container::const_iterator> getAllParams() const = 0;
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
  std::pair<IConfigurator::Container::const_iterator, IConfigurator::Container::const_iterator> getAllParams() const override;

private:
  Container values;
};

}
}
