#include <stdio.h>
#include <iostream>
#include "easecurve.h"

using namespace std;

std::string get_right_of_delim(std::string const& str, std::string const& delim){
  return str.substr(str.find(delim) + delim.size());
}

int main(int argc, char* argv[]) 
{
    vector<string> Tokens{};
    size_t index = 0;
    string delim = ",";
    string str = "";
    string s = "";
    string curve_def = "";
    string t0_d = "x_t0=";
    string tmax_d = "x_tmax=";
    string duration_d = "duration=";

    std::getline(std::cin, str);
    std::string::difference_type n = std::count(str.begin(), str.end(), ',');

    if (n != 3) {
        cout << "error: malformed curve definition" << endl;
        cout << "usage: ecsim Linear,x_t0=100,x_tmax=200,duration=1" << endl;
        exit(1);
    }

    cout << str << endl;

    while ((index = str.find(delim)) != string::npos)
    {
        Tokens.push_back(str.substr(0, index));
        str.erase(0, index + delim.length());
    }

    if (!str.empty())
        Tokens.push_back(str.substr(0, index));

    string ease_curve = Tokens.at(0);
    std::transform(ease_curve.begin(), ease_curve.end(), ease_curve.begin(),
    [](unsigned char c){ return std::tolower(c); });

    string t0 = Tokens.at(1);
    string tmax = Tokens.at(2);
    string duration = Tokens.at(3);

    string t0_check = t0.substr(0, 5);
    if (t0_check.compare(t0_d) != 0){
        cout << "error: incorrect x_t0= definition" << endl;
        exit(1);
    }

    string tmax_check = tmax.substr(0, 7);
    if (tmax_check.compare(tmax_d) != 0){
        cout << "error: incorrect x_tmax= definition" << endl;
        exit(1);
    }

    string duration_check = duration.substr(0, 9);
    if (duration_check.compare(duration_d) != 0){
        cout << "error: incorrect duration= definition" << endl;
        exit(1);
    }

    string t0_val = get_right_of_delim(t0, t0_d);
    string tmax_val = get_right_of_delim(tmax, tmax_d);
    string duration_val = get_right_of_delim(duration, duration_d);

    if (t0_val == "" || tmax_val == "" || duration_val == ""){
        cout << "error: values missing" << endl;
        exit(1); 
    }

    EaseCurve easeCurve;
    while (std::getline(cin, str)) {
        float f = easeCurve.getInterpolation(ease_curve, stof(str), stof(t0_val), stof(tmax_val), stof(duration_val));
        std::cout << f << std::endl;
        //if(f <= stof(tmax_val))
         //   break;
    }

    return 0;
}
