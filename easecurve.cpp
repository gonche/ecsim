#include "easecurve.h"

EaseCurve::EaseCurve(){}

float EaseCurve::EaseInOutSine(float t, float b, float c, float d)
{
    return -c / 2 * (cos(M_PI * t / d) - 1) + b;
}

float EaseCurve::Linear(float t, float b, float c, float d)
{
    // return  b + t * (c - b) / d;
    return c * t / d + b;
}

float EaseCurve::EaseIn(float t, float b, float c, float d)
{
    return c * (t /= d) * t + b;
}

float EaseCurve::EaseOut(float t, float b, float c, float d)
{
    return -c * (t /= d) * (t - 2) + b;
}

float EaseCurve::InQuad(float t, float b, float c, float d)
{
    return c * (t /= d) * t * t * t + b;
}
float EaseCurve::OutQuad(float t, float b, float c, float d)
{
    return -c * ((t = t / d - 1) * t * t * t - 1) + b;
}

float EaseCurve::InOutQuad(float t, float b, float c, float d)
{
    if ((t /= d / 2) < 1)
        return c / 2 * t * t * t * t + b;
    return -c / 2 * ((t -= 2) * t * t * t - 2) + b;
}

float EaseCurve::getInterpolation(string type, float t, float b, float c, float d)
{
    float result;
    if (type == "linear")
    {
        result = Linear(t, b, c, d);
    }
    else if (type == "easein")
    {
        result = EaseIn(t, b, c, d);
    }
    else if (type == "easeout")
    {
        result = EaseOut(t, b, c, d);
    }
    else if (type == "inquad")
    {
        result = InQuad(t, b, c, d);
    }
    else if (type == "outquad")
    {
        result = OutQuad(t, b, c, d);
    }
    else if (type == "inoutquad")
    {
        result = InOutQuad(t, b, c, d);
    }
    return result;
}
