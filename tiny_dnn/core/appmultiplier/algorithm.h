#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define BIT 8

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

  return bin;
}

