#pragma once

#include <string>

namespace THelper
{
namespace OS
{

class Paths
{
public:
  virtual ~Paths();

  virtual std::string getHomeDir() const = 0;

};

}
}
