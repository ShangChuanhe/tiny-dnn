#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

//#include "multiplier.h"

#define BIT 8
#define INTBIT 1
#define FRACBIT 7

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

// Floating point number converted to fixed point number
int float2fix(float flt)
{
  return round(flt / (1 / pow(2, FRACBIT)));
}

// Fixed-point number convert to floating-point number
float fix2float(int fix)
{
  return static_cast<float>(fix) / static_cast<float>(pow(2, FRACBIT));
}









/*
std::vector<std::vector<int>> getLUT(std::string nameMul)
{
  std::vector<std::vector<int>> LUT;
  for(int X = 0; X < 256; X++)
  {
    std::vector<int> pdt(256,0);// product

    for(int Y = 0; Y < 256; Y++)
    {
      int rst = 0;// result

      switch(nameMul)
      {
        case "AM_EX53":
          rst = AM_EX53(X, Y);
          break;
        case "AM_AC63":
          rst = AM_AC63(X, Y);
          break;

        default:
          std::cout << "error: No matching multiplier!!\n"
          return LUT;
          break;
      }
      pdt[Y] = rst;
    }
    LUT.emplace_back(pdt);
  }
}
*/



