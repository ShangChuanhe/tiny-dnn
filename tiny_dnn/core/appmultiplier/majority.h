#pragma once

int maj(int a, int b, int c)
{
  return ((a&&b)||(a&&c)||(b&&c));
}
