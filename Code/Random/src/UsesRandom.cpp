#include "../inc/UsesRandom.h"

using namespace THelper;

std::random_device UsesRandom::rd;

UsesRandom::UsesRandom()
{
  gen = new std::mt19937(rd());
}

UsesRandom::UsesRandom(const UsesRandom&)
{
  //new engine
  gen = new std::mt19937(rd());
}

UsesRandom::~UsesRandom()
{
  delete gen;
}
