#include "../inc/LinuxPaths.hpp"

using namespace THelper::OS;

LinuxPaths::LinuxPaths()
{
}

LinuxPaths::~LinuxPaths()
{
}

std::string LinuxPaths::getHomeDir() const
{
  return std::getenv("HOME");
}
