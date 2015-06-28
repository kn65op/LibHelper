#include "Random/UsesRandom.h"

using namespace THelper::Random;

std::random_device UsesRandom::rd;

UsesRandom::UsesRandom()
{
//  gen = new std::mt19937(rd());
  gen = std::make_unique<std::mt19937>(rd());
}

UsesRandom::UsesRandom(const UsesRandom&)
{
  //new engine
  gen = std::make_unique<std::mt19937>(rd());
}

UsesRandom::~UsesRandom()
{
}
