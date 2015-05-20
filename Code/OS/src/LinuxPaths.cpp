#include "OS/LinuxPaths.hpp"

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

std::string LinuxPaths::getTmpDir() const
{
  return "/tmp";
}