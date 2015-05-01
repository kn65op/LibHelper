#include "Configuration/inc/Configurator.hpp"

#include <gtest/gtest.h>

using namespace THelper::Configuration;
using namespace ::testing;

struct ConfiguratorTest : public Test
{
  Configurator conf;
  const std::string param_one = "param_one";
  const std::string value_one = "value_one";
};

TEST_F(ConfiguratorTest, ConfiguratorShouldThrowWhenParameterWasNotSet)
{
  EXPECT_THROW(conf.loadStringParameter(param_one), Configurator::NoSuchParameter);
}

TEST_F(ConfiguratorTest, ConfiguratorShouldReturnPreviouslySetValue)
{
  conf.storeStringParameter(param_one, value_one);
  EXPECT_EQ(value_one, conf.loadStringParameter(param_one));
}

TEST_F(ConfiguratorTest, ConfiguratorShouldReturnValidValueForTwoParameters)
{
  const std::string param_two = "param_one";
  const std::string value_two = "value_one";
  conf.storeStringParameter(param_one, value_one);
  conf.storeStringParameter(param_two, value_two);

  EXPECT_EQ(value_one, conf.loadStringParameter(param_one));
  EXPECT_EQ(value_two, conf.loadStringParameter(param_two));
}