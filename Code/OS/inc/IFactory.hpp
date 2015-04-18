#pragma once

#include "Paths.hpp"
#include <memory>

namespace THelper
{
namespace OS
{

class IFactory
{
public:
  virtual ~IFactory()
  {}

  virtual std::unique_ptr<Paths> getPaths() const = 0;

};

}}
