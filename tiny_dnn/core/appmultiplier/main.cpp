#include <iostream>
#include <vector>
#include <algorithm>

//#include "algorithm.h"
//#include "multiplier.h"
#include "appMultiplier.h"

using namespace std;

int main()
{
  long E = 0;
  int MAE = 0;
  double NMED = 0;

// 误差距离测试段
//#if 0
  //auto LUT = getLUT('a');
  for(int X = 0; X < 256; X++)
  {
    for(int Y = 0; Y < 256; Y++)
    {
      int result_ex = X*Y;
      //int result = AM_EX53(X, Y);
      int result = ap_pdt[X][Y];

      MAE = max(abs(result - result_ex), MAE);
      E += abs(result - result_ex);
    }
  }


  NMED = (double)E / (double)((long)65025 * (long)65536);

  cout << "ED: " << E << endl;
  cout << "MAE: " << MAE << endl;
  cout << "NMED: " << fixed << NMED << endl;
//#endif

//精度测试
#if 0
  for(int i = 0; i < 256; i++)
  {
    float r = static_cast<float> (rand()) / static_cast<float> (RAND_MAX);
    int fix = float2fix(r);
    float r_ap = fix2float(fix);
    cout << "float: " << r << "\t int: " << fix << "\t float_ap: " << r_ap << "\t accuracy: " << abs(r_ap - r) <<"\n";
  }
#endif

// 查找表获取测试


  return 0;
}
