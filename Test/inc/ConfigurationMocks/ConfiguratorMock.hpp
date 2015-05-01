#pragma once

#include <gmock/gmock.h>
#include "Configuration/inc/Configurator.hpp"

namespace THelper
{
namespace Configuration
{

namespace UT
{

class ConfiguratorMock : public IConfigurator
{
public:
  MOCK_METHOD2(storeStringParameter,
               void(const std::string& parameter, const std::string& value));
  MOCK_CONST_METHOD1(loadStringParameter,
                     std::string(const std::string& parameter));
  MOCK_CONST_METHOD0(getAllParams,
                     std::pair<Container::const_iterator, Container::const_iterator>());

};

}
}
}