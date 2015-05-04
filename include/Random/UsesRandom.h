#pragma once

#include <random>
#include <memory>

namespace THelper
{

/**
 * @brief Class which is interface to class that use random engine.
 *
 * For now it use mersenne twister engine.
 * This class can be use to skip part of making engine and device in C++11 way. You can just create distribution which you like to use and use gen which is poiter to std::mt199937 engine.
 */
class UsesRandom
{
public:
  /**
   * Default constructor.
   */
  UsesRandom();
  /**
   * Copy constructor which creates new objects for random engine.
   * @param orig Original object.
   */
  UsesRandom(const UsesRandom& orig);
  /**
   * Default destructor.
   */
  virtual ~UsesRandom();
protected:
  /** random device
   */
  static std::random_device rd;
  /** random engine
   */
  std::unique_ptr<std::mt19937> gen;
};

}//namespace
