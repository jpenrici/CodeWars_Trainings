/*
CODEWARS
https://www.codewars.com/kata/513e08acc600c94f01000001

"RGB To Hex Conversion"
*/

#include <iostream>
#include <sstream>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
};

std::string RGBToHex::rgb(int r, int g, int b)
{
    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;
    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    std::ostringstream rgb2hex;
    if (r < 10) rgb2hex << '0';
    rgb2hex << std::hex << std::uppercase << r;
    if (g < 10) rgb2hex << '0';
    rgb2hex << std::hex << std::uppercase << g;
    if (b < 10) rgb2hex << '0'; 
    rgb2hex << std::hex << std::uppercase << b;

    return rgb2hex.str();
}

void testequal(std::string ans, std::string sol)
{
    std::cout << "ans: " << ans << "\nsol: " << sol << std::endl;
    std::cout << std::boolalpha << (ans == sol) << std::endl;
}

int main()
{
    testequal(RGBToHex::rgb(0,0,0), "000000");
    testequal(RGBToHex::rgb(1,2,3), "010203");
    testequal(RGBToHex::rgb(255,255,255), "FFFFFF");
    testequal(RGBToHex::rgb(254,253,252), "FEFDFC");
    testequal(RGBToHex::rgb(-20,275,125), "00FF7D");
    
    return 0;
};
