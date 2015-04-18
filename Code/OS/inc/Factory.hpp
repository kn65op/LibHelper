#pragma once

#include "IFactory.hpp"

namespace THelper
{
namespace OS
{

class Factory : public IFactory
{
public:
  Factory();
  virtual ~Factory();
  std::unique_ptr<Paths> getPaths() const override;

};

}}
