#pragma once

#include "ConfiguratorIO.hpp"

namespace THelper
{
namespace Configuration
{

class EqualsSignConfiguratorIO : public ConfiguratorIO
{
public:
  void save(const IConfigurator& conf, std::ostream& out) const override;
  void load(IConfigurator& conf, std::istream& in) const override;
};

}
}
