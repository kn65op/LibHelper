#include "Configuration/inc/Configurator.hpp"

#include <gtest/gtest.h>

using namespace THelper::Configuration;
using namespace ::testing;

struct ConfiguratorTest : public Test
{
  Configurator conf;
  const std::string param_one = "param_one";
  const std::string value_one = "value_one";
  const std::string param_two = "param_two";
  const std::string value_two = "value_two";

  unsigned countParams(Configurator::Container::const_iterator& begin,
                       Configurator::Container::const_iterator& end)
  {
    unsigned count{0};
    auto it = begin;
    while (it++ != end)
    {
      ++count;
    }
    return count;
  }
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
  conf.storeStringParameter(param_one, value_one);
  conf.storeStringParameter(param_two, value_two);

  EXPECT_EQ(value_one, conf.loadStringParameter(param_one));
  EXPECT_EQ(value_two, conf.loadStringParameter(param_two));
}

TEST_F(ConfiguratorTest, CofiguratorShouldReturnValidNumberOfElements)
{
  auto params = conf.getAllParams();
  EXPECT_EQ(params.first, params.second);

  conf.storeStringParameter(param_one, value_one);
  params = conf.getAllParams();
  EXPECT_EQ(1, countParams(params.first, params.second));

  conf.storeStringParameter(param_two, value_two);
  params = conf.getAllParams();
  EXPECT_EQ(2, countParams(params.first, params.second));
}