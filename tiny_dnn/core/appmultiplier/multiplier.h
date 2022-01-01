#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>

#include "compressor.h"
#include "algorithm.h"

// the width of fraction bit
#define FRACBIT 8

int ** getLUT(const char s);

auto ap_pdt = getLUT('a');

// alias 'a'
int AM_EX53(int multiplicand, int multiplier)
{
  std::vector<int> X = dec2bin(multiplicand);
  std::vector<int> Y = dec2bin(multiplier);

  // AND gate array
  // p1
  int p10 = X[0] && Y[0];
  int p11 = X[1] && Y[0];
  int p12 = X[2] && Y[0];
  int p13 = X[3] && Y[0];
  int p14 = X[4] && Y[0];
  int p15 = X[5] && Y[0];
  int p16 = X[6] && Y[0];
  int p17 = X[7] && Y[0];

  // p2
  int p20 = X[0] && Y[1];
  int p21 = X[1] && Y[1];
  int p22 = X[2] && Y[1];
  int p23 = X[3] && Y[1];
  int p24 = X[4] && Y[1];
  int p25 = X[5] && Y[1];
  int p26 = X[6] && Y[1];
  int p27 = X[7] && Y[1];

  // p3
  int p30 = X[0] && Y[2];
  int p31 = X[1] && Y[2];
  int p32 = X[2] && Y[2];
  int p33 = X[3] && Y[2];
  int p34 = X[4] && Y[2];
  int p35 = X[5] && Y[2];
  int p36 = X[6] && Y[2];
  int p37 = X[7] && Y[2];

  // p4
  int p40 = X[0] && Y[3];
  int p41 = X[1] && Y[3];
  int p42 = X[2] && Y[3];
  int p43 = X[3] && Y[3];
  int p44 = X[4] && Y[3];
  int p45 = X[5] && Y[3];
  int p46 = X[6] && Y[3];
  int p47 = X[7] && Y[3];

  // p4
  int p50 = X[0] && Y[4];
  int p51 = X[1] && Y[4];
  int p52 = X[2] && Y[4];
  int p53 = X[3] && Y[4];
  int p54 = X[4] && Y[4];
  int p55 = X[5] && Y[4];
  int p56 = X[6] && Y[4];
  int p57 = X[7] && Y[4];

  // p5
  int p60 = X[0] && Y[5];
  int p61 = X[1] && Y[5];
  int p62 = X[2] && Y[5];
  int p63 = X[3] && Y[5];
  int p64 = X[4] && Y[5];
  int p65 = X[5] && Y[5];
  int p66 = X[6] && Y[5];
  int p67 = X[7] && Y[5];

  // p6
  int p70 = X[0] && Y[6];
  int p71 = X[1] && Y[6];
  int p72 = X[2] && Y[6];
  int p73 = X[3] && Y[6];
  int p74 = X[4] && Y[6];
  int p75 = X[5] && Y[6];
  int p76 = X[6] && Y[6];
  int p77 = X[7] && Y[6];

  // p7
  int p80 = X[0] && Y[7];
  int p81 = X[1] && Y[7];
  int p82 = X[2] && Y[7];
  int p83 = X[3] && Y[7];
  int p84 = X[4] && Y[7];
  int p85 = X[5] && Y[7];
  int p86 = X[6] && Y[7];
  int p87 = X[7] && Y[7];

#if 0
  printf("X is %d %d %d %d %d %d %d %d\n",X[7],X[6],X[5],X[4],X[3],X[2],X[1],X[0]);
  printf("Y is %d %d %d %d %d %d %d %d\n",Y[7],Y[6],Y[5],Y[4],Y[3],Y[2],Y[1],Y[0]);
  printf("========================================================================\n");
  printf("                       %d %d %d %d %d %d %d %d\n", p17,p16,p15,p14,p13,p12,p11,p10);
  printf("                     %d %d %d %d %d %d %d %d\n", p27,p26,p25,p24,p23,p22,p21,p20);
  printf("                   %d %d %d %d %d %d %d %d\n", p37,p36,p35,p34,p33,p32,p31,p30);
  printf("                 %d %d %d %d %d %d %d %d\n", p47,p46,p45,p44,p43,p42,p41,p40);
  printf("               %d %d %d %d %d %d %d %d\n", p57,p56,p55,p54,p53,p52,p51,p50);
  printf("             %d %d %d %d %d %d %d %d\n", p67,p66,p65,p64,p63,p62,p61,p60);
  printf("           %d %d %d %d %d %d %d %d\n", p77,p76,p75,p74,p73,p72,p71,p70);
  printf("         %d %d %d %d %d %d %d %d\n", p87,p86,p85,p84,p83,p82,p81,p80);
  printf("=====================================================================\n");
#endif


  //%stage 1
  auto [carry1,result1]=EFA(p14,p23,0);
  auto [carry3,carry2,result2]=ExCompressor(p15,p24,p33,p42,carry1);
  auto [carry5,carry4,result3]=ExCompressor(p16,p25,p34,p43,carry3);
  auto [carry6,result4]=EFA(p52,p61,0);
  auto [carry8,carry7,result5]=ExCompressor(p17,p26,p35,p44,carry5);
  auto [carry10,carry9,result6]=ExCompressor(p53,p62,p71,p80,carry6);
  auto [carry12,carry11,result7]=ExCompressor(p27,p36,p45,p54,carry8);
  auto [carry14,carry13,result8]=ExCompressor(p63,p72,p81,0,carry10);
  auto [carry16,carry15,result9]=ExCompressor(p37,p46,p55,p64,carry12);
  auto [carry17,result10]=EFA(p73,p82,carry14);
  auto [carry19,carry18,result11]=ExCompressor(p47,p56,p65,p74,carry16);
  auto [carry20,result12]=EFA(p57,p66,carry19);

  //result=double(p10)+(double(p11)+double(p20))*2+ (double(p12)+double(p21)+double(p30))*4+(double(p13)+double(p22)+double(p31)+double(p40))*8+(double(result1)+double(p32)+double(p41)+double(p50))*16+(+double(result2)+double(p51)+double(p60))*32+(double(carry2)+double(result3)+double(result4)+double(p70))*64 +(double(carry4)+double(result5)+double(result6))*128 +(double(carry7)+double(carry9)+double(result7)+double(result8))*256+(double(carry11)+double(carry13)+double(result9)+double(result10))*512 +(double(carry15)+double(carry17)+double(result11)+double(p83))*1024 +(double(carry18)+double(result12)+double(p75)+double(p84))*2048 +(double(carry20)+double(p67)+double(p76)+double(p85))*4096+(double(p86)+double(p77)+double(carry8))*4096*2+(double(p87))*4096*4;


  //stage 2
  auto [carry21,result13]=EFA(p12,p21,0);
  auto [carry23,carry22,result14]=ExCompressor(p13,p22,p31,p40,carry21);
  auto [carry25,carry24,result15]=ExCompressor(result1,p32,p41,p50,carry23);
  auto [carry27,carry26,result16]=ExCompressor(result2,p51,p60,0,carry25);
  auto [carry29,carry28,result17]=ExCompressor(carry2,result3,result4,p70,carry27);
  auto [carry31,carry30,result18]=ExCompressor(carry4,result5,result6,0,carry29);
  auto [carry33,carry32,result19]=ExCompressor(carry7,carry9,result7,result8,carry31);
  auto [carry35,carry34,result20]=ExCompressor(carry11,carry13,result9,result10,carry33);
  auto [carry37,carry36,result21]=ExCompressor(carry15,carry17,result11,p83,carry35);
  auto [carry39,carry38,result22]=ExCompressor(carry18,result12,p75,p84,carry37);
  auto [carry41,carry40,result23]=ExCompressor(carry20,p67,p76,p85,carry39);
  auto [carry42,result24]=EFA(p77,p86,carry41);

  //auto result=double(p10)+(double(p11)+double(p20))*2+ (double(result13)+double(p30))*4+(double(result14))*8+(double(carry22)+double(result15))*16+(double(carry24)+double(result16))*32+(double(carry26)+double(result17))*64 +(double(carry28)+double(result18))*128 +(double(carry30)+double(result19))*256+(double(carry32)+double(result20))*512 +(double(carry34)+double(result21))*1024 +(double(carry36)+double(result22))*2048 +(double(carry38)+double(result23))*4096+(double(carry40)+double(result24))*4096*2+(double(carry42)+double(p87))*4096*4;
  auto result=p10+(p11+p20)*2+(result13+p30)*4+(result14)*8+(carry22+result15)*16+(carry24+result16)*32+(carry26+result17)*64+(carry28+result18)*128+(carry30+result19)*256+(carry32+result20)*512+(carry34+result21)*1024+(carry36+result22)*2048+(carry38+result23)*4096+(carry40+result24)*4096*2+(carry42+p87)*4096*4;

  return static_cast<int>(result);
}

// alias 'b'
int AM_AC63(int multiplicand, int multiplier)
{
  std::vector<int> X = dec2bin(multiplicand);
  std::vector<int> Y = dec2bin(multiplier);

  // AND gate array
  // p1
  int p10 = X[0] && Y[0];
  int p11 = X[1] && Y[0];
  int p12 = X[2] && Y[0];
  int p13 = X[3] && Y[0];
  int p14 = X[4] && Y[0];
  int p15 = X[5] && Y[0];
  int p16 = X[6] && Y[0];
  int p17 = X[7] && Y[0];

  // p2
  int p20 = X[0] && Y[1];
  int p21 = X[1] && Y[1];
  int p22 = X[2] && Y[1];
  int p23 = X[3] && Y[1];
  int p24 = X[4] && Y[1];
  int p25 = X[5] && Y[1];
  int p26 = X[6] && Y[1];
  int p27 = X[7] && Y[1];

  // p3
  int p30 = X[0] && Y[2];
  int p31 = X[1] && Y[2];
  int p32 = X[2] && Y[2];
  int p33 = X[3] && Y[2];
  int p34 = X[4] && Y[2];
  int p35 = X[5] && Y[2];
  int p36 = X[6] && Y[2];
  int p37 = X[7] && Y[2];

  // p4
  int p40 = X[0] && Y[3];
  int p41 = X[1] && Y[3];
  int p42 = X[2] && Y[3];
  int p43 = X[3] && Y[3];
  int p44 = X[4] && Y[3];
  int p45 = X[5] && Y[3];
  int p46 = X[6] && Y[3];
  int p47 = X[7] && Y[3];

  // p4
  int p50 = X[0] && Y[4];
  int p51 = X[1] && Y[4];
  int p52 = X[2] && Y[4];
  int p53 = X[3] && Y[4];
  int p54 = X[4] && Y[4];
  int p55 = X[5] && Y[4];
  int p56 = X[6] && Y[4];
  int p57 = X[7] && Y[4];

  // p5
  int p60 = X[0] && Y[5];
  int p61 = X[1] && Y[5];
  int p62 = X[2] && Y[5];
  int p63 = X[3] && Y[5];
  int p64 = X[4] && Y[5];
  int p65 = X[5] && Y[5];
  int p66 = X[6] && Y[5];
  int p67 = X[7] && Y[5];

  // p6
  int p70 = X[0] && Y[6];
  int p71 = X[1] && Y[6];
  int p72 = X[2] && Y[6];
  int p73 = X[3] && Y[6];
  int p74 = X[4] && Y[6];
  int p75 = X[5] && Y[6];
  int p76 = X[6] && Y[6];
  int p77 = X[7] && Y[6];

  // p7
  int p80 = X[0] && Y[7];
  int p81 = X[1] && Y[7];
  int p82 = X[2] && Y[7];
  int p83 = X[3] && Y[7];
  int p84 = X[4] && Y[7];
  int p85 = X[5] && Y[7];
  int p86 = X[6] && Y[7];
  int p87 = X[7] && Y[7];

#if 0
  printf("X is %d %d %d %d %d %d %d %d\n",X[7],X[6],X[5],X[4],X[3],X[2],X[1],X[0]);
  printf("Y is %d %d %d %d %d %d %d %d\n",Y[7],Y[6],Y[5],Y[4],Y[3],Y[2],Y[1],Y[0]);
  printf("========================================================================\n");
  printf("                       %d %d %d %d %d %d %d %d\n", p17,p16,p15,p14,p13,p12,p11,p10);
  printf("                     %d %d %d %d %d %d %d %d\n", p27,p26,p25,p24,p23,p22,p21,p20);
  printf("                   %d %d %d %d %d %d %d %d\n", p37,p36,p35,p34,p33,p32,p31,p30);
  printf("                 %d %d %d %d %d %d %d %d\n", p47,p46,p45,p44,p43,p42,p41,p40);
  printf("               %d %d %d %d %d %d %d %d\n", p57,p56,p55,p54,p53,p52,p51,p50);
  printf("             %d %d %d %d %d %d %d %d\n", p67,p66,p65,p64,p63,p62,p61,p60);
  printf("           %d %d %d %d %d %d %d %d\n", p77,p76,p75,p74,p73,p72,p71,p70);
  printf("         %d %d %d %d %d %d %d %d\n", p87,p86,p85,p84,p83,p82,p81,p80);
#endif

  //stage 1
  auto [carry1,result2,result1]=AC63(p13,p22,p31,p14,p23,p32);

  auto [carry2,result4,result3]=AC63(p15,p24,p33,p16,p25,p34);
  auto [carry3,result6,result5]=AC63(p42,p51,p60,p43,p52,p61);

  auto [carry4,result8,result7]=AC63(p17,p26,p35,p27,p36,p45);
  auto [carry5,result10,result9]=AC63(p44,p53,p62,p54,p63,p72);

  auto [carry6,result12,result11]=AC63(p37,p46,p55,p47,p56,p65);
  auto [carry7,result14,result13]=AC63(p64,p73,p82,p74,0,p83);

  auto [carry8,result16,result15]=AC63(p57,p66,p75,p67,p76,p85);

  //result=double(p10)+(double(p11)+double(p20))*2+ (double(p12)+double(p21)+double(p30))*4+(double(result1)+double(p40))*8+(double(result2)+double(p41)+double(p50))*16+(double(carry1)+double(result3)+double(result5))*32+(double(result4)+double(result6)+double(p70))*64 +(double(carry2)+double(carry3)+double(result7)+double(result9)+double(p71)+double(p80))*128 +(double(result8)+double(result10)+double(p81))*256+(double(carry4)+double(carry5)+double(result11)+double(result13))*512 +(double(result12)+double(result14))*1024 +(double(carry6)+double(carry7)+double(result15)+double(p84))*2048 +(double(result16))*4096+(double(p86)+double(p77)+double(carry8))*4096*2+(double(p87))*4096*4;

#if 0
  //stage 2_1 尽量分配carry
  auto [carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto [carry10,result20,result19]=AC63(result2,p41,p50,carry1,result3,result5);
  auto [carry11,result22,result21]=AC63(result4,result6,p70,carry2,result7,carry3);
  auto [carry12,result24,result23]=AC63(0,0,0,result9,p71,p80);
  auto [carry13,result26,result25]=AC63(result8,result10,p81,carry4,result11,carry5);
  auto [carry14,result28,result27]=AC63(result14,result12,0,carry6,result15,carry7);
  auto [carry15,result30,result29]=AC63(0,result16,0,carry8,p77,p86);
  //stage 3_1
  result=double(p10)+(double(p11)+double(p20))*2+ double(result17)*4+double(result18)*8+(double(carry9)+double(result19))*16+(double(result20))*32+(double(result21)+double(result23)+double(carry10))*64 +(double(result22)+double(result24))*128 +(double(carry11)+double(carry12)+double(result25))*256+(double(result26)+double(result13))*512 +(double(carry13)+double(result27))*1024 +(double(result28)+double(p84))*2048 +(double(carry14)+double(result29))*4096+(double(result30))*4096*2+(double(p87)+double(carry15))*4096*4;
#endif

#if 0
  //stage 2_2  尽量不分配carry
  auto [carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto [carry10,result20,result19]=AC63(result2,p41,p50,result3,carry1,result5);
  auto [carry11,result22,result21]=AC63(result4,result6,p70,result7,carry2,result9);
  auto [carry12,result24,result23]=AC63(0,0,0,p71,carry3,p80);
  auto [carry13,result26,result25]=AC63(result8,result10,p81,result11,carry4,result13);
  auto [carry14,result28,result27]=AC63(result14,result12,0,result15,carry6,p84);
  auto [carry15,result30,result29]=AC63(0,result16,0,p77,carry8,p86);
  //stage 3_2
  result=double(p10)+(double(p11)+double(p20))*2+ double(result17)*4+double(result18)*8+(double(carry9)+double(result19))*16+(double(result20))*32+(double(result21)+double(result23)+double(carry10))*64 +(double(result22)+double(result24))*128 +(double(carry11)+double(carry12)+double(result25))*256+(double(result26)+double(carry5))*512 +(double(carry13)+double(result27))*1024 +(double(result28)+double(carry7))*2048 +(double(carry14)+double(result29))*4096+(double(result30))*4096*2+(double(p87)+double(carry15))*4096*4;
#endif

#if 0
  //stage 2_3_1 分配一个carry，方式1
  auto [carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto [carry10,result20,result19]=AC63(result2,p41,p50,result3,result5,carry1);
  auto [carry11,result22,result21]=AC63(result4,result6,p70,result7,result9,carry2);
  auto [carry12,result24,result23]=AC63(0,0,0,p71,p80,carry3);
  auto [carry13,result26,result25]=AC63(result8,result10,p81,result11,result13,carry4);
  auto [carry14,result28,result27]=AC63(result14,result12,0,result15,p84,carry6);
  auto [carry15,result30,result29]=AC63(0,result16,0,p77,p86,carry8);
  //stage 3_3_1
  result=double(p10)+(double(p11)+double(p20))*2+ double(result17)*4+double(result18)*8+(double(carry9)+double(result19))*16+(double(result20))*32+(double(result21)+double(result23)+double(carry10))*64 +(double(result22)+double(result24))*128 +(double(carry11)+double(carry12)+double(result25))*256+(double(result26)+double(result13))*512 +(double(carry13)+double(result27))*1024 +(double(result28)+double(p84))*2048 +(double(carry14)+double(result29))*4096+(double(result30))*4096*2+(double(p87)+double(carry15))*4096*4;
#endif

#if 0
  //stage 2_3_2 分配一个carry，方式2
  auto [carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto [carry10,result20,result19]=AC63(result2,p41,p50,result5,result3,carry1);
  auto [carry11,result22,result21]=AC63(result4,result6,p70,result9,result7,carry2);
  auto [carry12,result24,result23]=AC63(0,0,0,p71,p80,carry3);
  auto [carry13,result26,result25]=AC63(result8,result10,p81,result13,result11,carry4);
  auto [carry14,result28,result27]=AC63(result14,result12,0,p84,result15,carry6);
  auto [carry15,result30,result29]=AC63(0,result16,0,p86,p77,carry8);
  //stage 3_3_2
  result=double(p10)+(double(p11)+double(p20))*2+ double(result17)*4+double(result18)*8+(double(carry9)+double(result19))*16+(double(result20))*32+(double(result21)+double(result23)+double(carry10))*64 +(double(result22)+double(result24))*128 +(double(carry11)+double(carry12)+double(result25))*256+(double(result26)+double(result13))*512 +(double(carry13)+double(result27))*1024 +(double(result28)+double(p84))*2048 +(double(carry14)+double(result29))*4096+(double(result30))*4096*2+(double(p87)+double(carry15))*4096*4;
#endif

#if 0
  //stage 2_4_1精确全加器压缩前端
  auto [carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto [carry10,result20,result19]=AC63(result2,p41,p50,result3,carry1,result5);
  auto [carry11,result22,result21]=AC63(result4,result6,p70,result7,carry2,result9);
  auto [carry12,result24,result23]=AC63(0,0,0,p71,carry3,p80);
  auto [carry13,result26,result25]=AC63(result8,result10,p81,result11,carry4,result13);
  auto [carry14,result27]=EFA(result15,carry6,p84);
  auto [carry15,result28]=EFA(p77,carry8,p86);
  //stage 3_4_1
  result=double(p10)+(double(p11)+double(p20))*2+ double(result17)*4+double(result18)*8+(double(carry9)+double(result19))*16+(double(result20))*32+(double(result21)+double(result23)+double(carry10))*64 +(double(result22)+double(result24))*128 +(double(carry11)+double(carry12)+double(result25))*256+(double(result26)+double(carry5))*512 +(double(carry13)+double(result12))*1024 +(double(result27)+double(carry7))*2048 +(double(carry14)+double(result16))*4096+(double(result28))*4096*2+(double(p87)+double(carry15))*4096*4;
#endif


  //#if 0
  //stage 2_4_test 精确全加器压缩前端
  auto [carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto [carry10,result20,result19]=AC63(result2,p41,p50,result3,carry1,result5);
  auto [carry11,result22,result21]=AC63(result4,result6,p70,result7,carry2,result9);
  auto [carry12,result24,result23]=AC63(0,0,0,p71,carry3,p80);
  auto [carry13,result26,result25]=AC63(result8,result10,p81,result11,carry4,result13);
  auto [carry14,result27]=EFA(result15,carry6,p84);
  auto [carry15,result28]=EFA(p77,carry8,p86);
  //stage 3_4_test
  auto result=p10+(p11+p20)*2+ result17*4+result18*8+(carry9+result19)*16+(result20)*32+(result21+result23+carry10)*64 +(result22+result24)*128 +(carry11+carry12+result25)*256+(result26+carry5)*512 +(carry13+result12)*1024 +(result27+carry7)*2048 +(carry14+result16)*4096+(result28)*4096*2+(p87+carry15)*4096*4;
  //endif

  return static_cast<int>(result);
}

/*
std::vector<std::vector<int>> getLUT(const char s)
{
  std::vector<std::vector<int>> LUT;
  for(int X = 0; X < std::pow(2, FRACBIT) + 1; X++)
  {
    std::vector<int> pdt(std::pow(2, FRACBIT) + 1,0);// product

    for(int Y = 0; Y < std::pow(2, FRACBIT) + 1; Y++)
    {
      int rst = 0;// result

      switch(s)
      {
        case 'a':
          rst = AM_EX53(X, Y);
          break;
        case 'b':
          rst = AM_AC63(X, Y);
          break;

        default:
          std::cout << "error: No matching multiplier!!\n";
          return LUT;
          break;
      }
      pdt[Y] = rst;
    }
    LUT.emplace_back(pdt);
  }
  return LUT;
}
*/


int ** getLUT(const char s)
{
  
  int **LUT = nullptr;
  int LUTsize = std::pow(2, FRACBIT) + 1;

  LUT = new int*[LUTsize];
  for(int i = 0; i < LUTsize; i++)
  {
    LUT[i] = new int[LUTsize];
  }
  
  //std::vector<std::vector<int>> LUT;
  for(int X = 0; X < LUTsize; X++)
  {
    for(int Y = 0; Y < LUTsize; Y++)
    {
      int rst = 0;// result

      switch(s)
      {
        case 'a':
          rst = AM_EX53(X, Y);
          break;
        case 'b':
          rst = AM_AC63(X, Y);
          break;

        default:
          std::cout << "error: No matching multiplier!!\n";
          return LUT;
          break;
      }
      LUT[X][Y] = rst;
    }
  }
  return LUT;
}

