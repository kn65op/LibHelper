#include "Configuration/EqualsSignConfiguratorIO.hpp"

using namespace THelper::Configuration;

void EqualsSignConfiguratorIO::save(const IConfigurator& conf, std::ostream& out) const
{
  auto params = conf.getAllParams();
  auto it = params.first;
  while (it != params.second)
  {
    out << it->first << equalsSign << it->second << "\n";
    ++it;
  }
}

void EqualsSignConfiguratorIO::load(IConfigurator& conf, std::istream& in) const
{
  while (!in.eof())
  {
    std::string line;
    std::getline(in, line);
    auto equalsPlace = line.find(equalsSign);
    if (equalsPlace == std::string::npos)
    {
      continue;
    }
    conf.storeStringParameter(line.substr(0, equalsPlace), line.substr(equalsPlace + 1));
  }
}
