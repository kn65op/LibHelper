#include <gtest/gtest.h>
#include <sstream>
#include "Configuration/inc/EqualsSignConfiguratorIO.hpp"
#include "ConfiguratorMock.hpp"


using namespace THelper::Configuration;
using namespace THelper::Configuration::UT;
using namespace ::testing;

struct EqualsSignConfiguratorIOTest : Test
{
  EqualsSignConfiguratorIO confIO;
  ConfiguratorMock conf;
};

TEST_F(EqualsSignConfiguratorIOTest, ShouldStoreWithEqualsSignBetweenParameterAndValue)
{
  std::ostringstream output;
  confIO.save(conf, out);
}