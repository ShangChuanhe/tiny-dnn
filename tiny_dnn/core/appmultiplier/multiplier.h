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

auto ap_pdt = getLUT('c');

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


  //stage 1
  auto [carry1,result2,result1]=AC63(p13,p22,p31,p14,p23,p32);
  auto [carry2,result4,result3]=AC63(p15,p24,p33,p16,p25,p34);
  auto [carry3,result6,result5]=AC63(p42,p51,p60,p43,p52,p61);
  auto [carry4,result8,result7]=AC63(p17,p26,p35,p27,p36,p45);
  auto [carry5,result10,result9]=AC63(p44,p53,p62,p54,p63,p72);
  auto [carry6,result12,result11]=AC63(p37,p46,p55,p47,p56,p65);
  auto [carry7,result14,result13]=AC63(p64,p73,p82,p74,0,p83);
  auto [carry8,result16,result15]=AC63(p57,p66,p75,p67,p76,p85);

  //stage 2_4_test 精确全加器压缩前端
  auto	[carry9,result18,result17]=AC63(p12,p21,p30,result1,p40,0);
  auto	[carry10,result20,result19]=AC63(result2,p41,p50,result3,carry1,result5);
  auto	[carry11,result22,result21]=AC63(result4,result6,p70,result7,carry2,result9);
  auto	[carry12,result24,result23]=AC63(0,0,0,p71,carry3,p80);
  auto	[carry13,result26,result25]=AC63(result8,result10,p81,result11,carry4,result13);
  auto	[carry14,result27]=EFA(result15,carry6,p84);
  auto	[carry15,result28]=EFA(p77,carry8,p86);
  //stage 3 (case3)
  auto	result=(p10)+((p20))*2+ (result17)*4+(result18)*8+((carry9))*16+((result20))*32+((result21)+(carry10))*64 +((result22)+(result24))*128 +((carry11)+(carry12))*256+((result26)+(carry5))*512 +((carry13)+(result12))*1024 +((result27)+(carry7))*2048 +((carry14)+(result16))*4096+((result28))*4096*2+((p87)+(carry15))*4096*4;

  return static_cast<int>(result);
}

// alias 'c'
int AM_MLAC1(int multiplicand, int multiplier)
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

  //stage 1
  auto [carry1,result1]=EFA(p14,p23,0);
  auto [carry3,carry2,result2]=MLAC1(p15,p24,p33,p42,carry1);
  auto [carry5,carry4,result3]=MLAC1(p16,p25,p34,p43,carry3);
  auto [carry6,result4]=EFA(p52,p61,0);
  auto [carry8,carry7,result5]=MLAC1(p17,p26,p35,p44,carry5);
  auto [carry10,carry9,result6]=MLAC1(p53,p62,p71,p80,carry6);
  auto [carry12,carry11,result7]=MLAC1(p27,p36,p45,p54,carry8);
  auto [carry14,carry13,result8]=MLAC1(p63,p72,p81,0,carry10);
  auto [carry16,carry15,result9]=MLAC1(p37,p46,p55,p64,carry12);
  auto [carry17,result10]=EFA(p73,p82,carry14);
  auto [carry19,carry18,result11]=MLAC1(p47,p56,p65,p74,carry16);
  auto [carry20,result12]=EFA(p57,p66,carry19);

  //stage 2
  auto [carry21,result13]=EFA(p12,p21,0);
  auto [carry23,carry22,result14]=MLAC1(p13,p22,p31,p40,carry21);
  auto [carry25,carry24,result15]=MLAC1(result1,p32,p41,p50,carry23);
  auto [carry27,carry26,result16]=MLAC1(result2,p51,p60,0,carry25);
  auto [carry29,carry28,result17]=MLAC1(carry2,result3,result4,p70,carry27);
  auto [carry31,carry30,result18]=MLAC1(carry4,result5,result6,0,carry29);
  auto [carry33,carry32,result19]=MLAC1(carry7,carry9,result7,result8,carry31);
  auto [carry35,carry34,result20]=MLAC1(carry11,carry13,result9,result10,carry33);
  auto [carry37,carry36,result21]=MLAC1(carry15,carry17,result11,p83,carry35);
  auto [carry39,carry38,result22]=ExCompressor(carry18,result12,p75,p84,carry37);
  auto [carry41,carry40,result23]=MLAC1(carry20,p67,p76,p85,carry39);
  auto [carry42,result24]=EFA(p77,p86,carry41);

  auto result = (p10)+((p11)+(p20))*2+ ((result13)+(p30))*4+((result14))*8+((carry22)+(result15))*16+((carry24)+(result16))*32+((carry26)+(result17))*64 +((carry28)+(result18))*128 +((carry30)+(result19))*256+((carry32)+(result20))*512 +((carry34)+(result21))*1024 +((carry36)+(result22))*2048 +((carry38)+(result23))*4096+((carry40)+(result24))*4096*2+((carry42)+(p87))*4096*4;

  return static_cast<int>(result);
}

// alias 'd'
int AM_MLACSalman2021(int multiplicand, int multiplier)
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

  //stage 1
  auto	[carry1,result1]=EFA(p14,p23,0);
  auto	[carry2,result2]=Salman2021(p15,p24,p33,p42);
  auto	[carry3,result3]=Salman2021(p16,p25,p34,p43);
  auto	[carry4,result4]=EFA(p52,p61,0);
  auto	[carry5,result5]=Salman2021(p17,p26,p35,p44);
  auto	[carry6,result6]=Salman2021(p53,p62,p71,p80);
  auto	[carry7,result7]=Salman2021(p27,p36,p45,p54);
  auto	[carry8,result8]=Salman2021(p63,p72,p81,0);
  auto	[carry9,result9]=Salman2021(p37,p46,p55,p64);
  auto	[carry10,result10]=EFA(p73,p82,0);
  auto	[carry11,result11]=Salman2021(p47,p56,p65,p74);
  auto	[carry12,result12]=EFA(p57,p66,0);



  //stage 2 with one ExCompressor
  auto	[carry13,result13]=EFA(p12,p21,0);
  auto	[carry14,result14]=Salman2021(p13,p22,p31,p40);
  auto	[carry15,result15]=Salman2021(result1,p32,p41,p50);
  auto	[carry16,result16]=Salman2021(carry1,result2,p51,p60);
  auto	[carry17,result17]=Salman2021(carry2,result3,result4,p70);
  auto	[carry18,result18]=Salman2021(carry3,carry4,result5,result6);
  auto	[carry19,result19]=Salman2021(carry5,carry6,result7,result8);
  auto	[carry20,result20]=Salman2021(carry7,carry8,result9,result10);
  auto	[carry21,result21]=Salman2021(carry9,carry10,result11,p83);
  auto	[C1,carry22,result22]=ExCompressor(carry11,result12,p75,p84,0);
  auto	[carry23,result23]=Salman2021(carry12,p67,p76,p85);
  auto	[carry24,result24]=EFA(p77,p86,0);

  auto	result=(p10)+((p11)+(p20))*2+ ((result13)+(p30))*4+((carry13)+(result14))*8+((carry14)+(result15))*16+((carry15)+(result16))*32+((carry16)+(result17))*64 +((carry17)+(result18))*128 +((carry18)+(result19))*256+((carry19)+(result20))*512 +((carry20)+(result21))*1024 +((carry21)+(result22))*2048 +((carry22)+(result23)+(C1))*4096+((carry23)+(result24))*4096*2+((carry24)+(p87))*4096*4;
		
  return static_cast<int>(result);
}


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
        case 'c':
          rst = AM_MLAC1(X, Y);
          break;
        case 'd':
          rst = AM_MLACSalman2021(X, Y);
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

float appMulti(float pw, float pin, float Wk)
{
  float x = pw;
  float y = pin;

  // Quantify
  int X = std::round(std::abs(x) / Wk);
  int Y = std::round(std::abs(y) / Wk);

  X = X > (1 / Wk - 1) ? (1 / Wk - 1) : X;
  Y = Y > (1 / Wk - 1) ? (1 / Wk - 1) : Y;

  // Multiply
  int pdt = ap_pdt[X][Y];// approximate product

  // Anti-quantify
  float rst= static_cast<float>(pdt) * Wk * Wk;// result

  if(pw < 0)
  {
    if(pin > 0)
    {
      rst *= -1;
    }
  }
  else
  {
    if(pin < 0)
    {
      rst *= -1;
    }
  }

  return rst;
}

