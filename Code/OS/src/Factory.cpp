#include "../inc/Factory.hpp"
#include "../inc/WindowsPaths.hpp"
#include "../inc/LinuxPaths.hpp"

using namespace THelper::OS;


Factory::~Factory()
{
}

std::unique_ptr<Paths> Factory::getPaths() const
{
#ifdef _WIN32
  return std::make_unique<WindowsPaths>();
#elif __linux
  return std::make_unique<LinuxPaths>();
#else
#error LibTHelper::OS: Not supported platform. Currently supported platforms is Linux and Windows32
#endif
}
