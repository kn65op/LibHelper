/* 
 * File:   UsesRandom.cpp
 * Author: tomko
 * 
 * Created on 25 lipiec 2012, 12:33
 */

#include "../include/UsesRandom.h"

UsesRandom::UsesRandom()
{
  gen = new std::mt19937(rd());
}

UsesRandom::UsesRandom(const UsesRandom& orig)
{
  //new engine
  gen = new std::mt19937(rd());
}

UsesRandom::~UsesRandom()
{
  delete gen;
}