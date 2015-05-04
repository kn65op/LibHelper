#include "Configuration/Configurator.hpp"

using namespace THelper::Configuration;

void Configurator::storeStringParameter(const std::string& parameter, const std::string& value)
{
  values[parameter] = value;
}

std::string Configurator::loadStringParameter(const std::string& parameter) const
{
  try
  {
    return values.at(parameter);
  }
  catch(...)
  {
    throw NoSuchParameter();
  }
}

std::pair<IConfigurator::Container::const_iterator, IConfigurator::Container::const_iterator> Configurator::getAllParams() const
{
  return std::make_pair(values.begin(), values.end());
}
