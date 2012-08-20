/* 
 * File:   UsesRandom.h
 * Author: tomko
 *
 * Created on 25 lipiec 2012, 12:33
 */

#ifndef USESRANDOM_H
#define	USESRANDOM_H

#include <random>

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
  std::random_device rd;
  /** random engine
   */
  std::mt19937 *gen;
};

}//namespace
#endif	/* USESRANDOM_H */

