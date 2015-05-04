#pragma once

#include "Paths.hpp"

namespace THelper
{
namespace OS
{

class LinuxPaths: public THelper::OS::Paths
{
public:
  LinuxPaths();
  ~LinuxPaths();
  std::string getHomeDir() const override;
};

}}
