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
  UsesRandom(const UsesRandom& orig);
  /**
   * Default destructor.
   */
  virtual ~UsesRandom();
private:
  //random
  std::random_device rd;
  std::mt19937 *gen;
};

#endif	/* USESRANDOM_H */

