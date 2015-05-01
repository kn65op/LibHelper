#pragma once

#include "ConfiguratorIO.hpp"

namespace THelper
{
namespace Configuration
{

class EqualsSignConfiguratorIO : public ConfiguratorIO
{
public:
  void save(const Configurator& conf, std::ostream& out) const override;
  void load(const Configurator conf, std::istream& in) const override;
};

}
}
