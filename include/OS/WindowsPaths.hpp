#pragma once

#include "Paths.hpp"

namespace THelper
{
namespace OS
{

class WindowsPaths: public Paths
{
public:
  WindowsPaths();
  ~WindowsPaths();
  std::string getHomeDir() const override;
  std::string getTmpDir() const override;
};

}}
