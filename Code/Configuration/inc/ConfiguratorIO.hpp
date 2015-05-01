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
  virtual void save(const Configurator& conf, std::ostream& out) const = 0;
  virtual void load(const Configurator conf, std::istream& in) const = 0;
};

}
}
