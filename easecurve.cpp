#include "easecurve.h"

EaseCurve::EaseCurve(){}

float EaseCurve::easeInOutSine(float t, float b, float c, float d)
{
    return -c / 2 * (cos(M_PI * t / d) - 1) + b;
}

float EaseCurve::linear(float t, float b, float c, float d)
{
    // return  b + t * (c - b) / d;
    return c * t / d + b;
}

float EaseCurve::easeIn(float t, float b, float c, float d)
{
    return c * (t /= d) * t + b;
}

float EaseCurve::easeOut(float t, float b, float c, float d)
{
    return -c * (t /= d) * (t - 2) + b;
}

float EaseCurve::getInterpolation(string type, float t, float b, float c, float d)
{
    float result;
    if (type == "linear")
    {
        result = linear(t, b, c, d);
    }
    else if (type == "easein")
    {
        result = easeIn(t, b, c, d);
    }
    else if (type == "easeout")
    {
        result = easeOut(t, b, c, d);
    }
    return result;
}
