#pragma once

#include "Configurator.hpp"
#include <iostream>

namespace THelper
{
namespace Configuration
{

class ConfiguratorIO
{
public:
  virtual ~ConfiguratorIO() {}
  virtual void save(const IConfigurator& conf, std::ostream& out) const = 0;
  virtual void load(IConfigurator& conf, std::istream& in) const = 0;
};

}
}
