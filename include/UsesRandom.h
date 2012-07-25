/* 
 * File:   UsesRandom.h
 * Author: tomko
 *
 * Created on 25 lipiec 2012, 12:33
 */

#ifndef USESRANDOM_H
#define	USESRANDOM_H

#include <random>

/**
 * Class which is interface to class that use random engine. For now it use mersenne twister engine.
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

#endif	/* USESRANDOM_H */

