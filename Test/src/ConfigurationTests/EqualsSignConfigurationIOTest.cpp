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

  const std::string param_one{"param 1"};
  const std::string param_two{"param 2"};
  const std::string value_one{"val 1"};
  const std::string value_two{"val 2"};
  const std::string newline{"\n"};
  const std::string equal_sign{"="};

  std::string file_string{param_one + equal_sign + value_one + newline
                          + param_two + equal_sign + value_two + newline};
};

TEST_F(EqualsSignConfiguratorIOTest, ShouldStoreWithEqualsSignBetweenParameterAndValue)
{
  std::ostringstream output;
  confIO.save(conf, output);

  EXPECT_EQ(file_string, output.str());
}