/* 
 * File:   Helper.cpp
 * Author: tomko
 * 
 * Created on 18 listopad 2011, 16:50
 */

#include "Helper.h"

#include <sstream>

using namespace std;

Helper::Helper()
{
  
}
Helper::Helper(const Helper & h)
{
  
}


inline static string Helper::intToString(int n)
{
  stringstream ss;
  ss << n;
  return ss.str();
}

inline static string Helper::doubleToString(double n)
{
  stringstream ss;
  ss << n;
  return ss.str();
}
