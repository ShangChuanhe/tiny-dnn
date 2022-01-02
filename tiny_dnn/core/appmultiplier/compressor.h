#pragma once

#include <iostream>
#include <tuple>
#include <utility>

#include "majority.h"


std::tuple<int, int> EFA(int a, int b, int Cin)
{
  int Cout = maj(a, b, Cin);
  int sum = maj(!maj(a, b, Cin), maj(a, b, !Cin), Cin);
  return std::make_tuple(Cout, sum);
}

std::tuple<int, int, int> ExCompressor(int x1, int x2, int x3, int x4, int Cin)
{
  auto [Cout, s0] = EFA(x1, x2, x3);
  auto [carry, sum] = EFA(s0, x4, Cin);
  return std::make_tuple(Cout, carry, sum);
}

std::tuple<int, int, int> AC63(int a, int b, int c, int d, int e, int f)
{
  int carry = maj(1, d, f);
  int sum1 = e;
  int sum0 = b;
  return std::make_tuple(carry, sum1, sum0);
}

std::tuple<int, int, int> MLAC1(int x1, int x2, int x3, int x4, int Cin)
{
  auto Cout = x3;
  auto carry = x4;
  auto sum = maj(x1, x2, !maj(x3, x4, !Cin));
  return std::make_tuple(Cout, carry, sum);
}

std::tuple<int, int> Salman2021(int x1, int x2, int x3, int x4)
{
  auto carry = maj(0,x1,maj(1,x3,x4));
	auto sum = 1;
  return std::make_tuple(carry, sum);
}
