#ifndef EASECURVE_H
#define EASECURVE_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class EaseCurve{
public:
  EaseCurve();
  float easeInOutSine(float t, float b, float c, float d);
  float linear(float t, float b, float c, float d);
  float easeIn(float t, float b, float c, float d);
  float easeOut(float t, float b, float c, float d);
  float getInterpolation(string type, float t, float b, float c, float d); 
};

#endif