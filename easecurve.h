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
  float EaseInOutSine(float t, float b, float c, float d);
  float Linear(float t, float b, float c, float d);
  float EaseIn(float t, float b, float c, float d);
  float EaseOut(float t, float b, float c, float d);
  float InQuad(float t, float b, float c, float d);
  float OutQuad(float t, float b, float c, float d);
  float InOutQuad(float t, float b, float c, float d);
  float getInterpolation(string type, float t, float b, float c, float d); 
};

#endif