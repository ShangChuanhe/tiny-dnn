#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>

//#include "multiplier.h"

#define BIT 8
#define INTBIT 1
#define FRACTBIT 7

std::vector<int> dec2bin(int dec)
{
  std::vector<int> bin;
  while(dec != 0)
  {
    bin.emplace_back(dec % 2 == 0 ? 0 : 1);
    dec /= 2;
  }

  for(auto i = bin.size(); i < BIT; i++)
  {
    bin.emplace_back(0);
  }

  assert(bin.size() == BIT);

  return bin;
}

// Floating point number converted to fixed point number
int float2fix(float flt)
{
  return round(flt / (1 / pow(2, FRACTBIT)));
}

// Fixed-point number convert to floating-point number
float fix2float(int fix)
{
  return static_cast<float>(fix) / static_cast<float>(pow(2, FRACTBIT));
}


