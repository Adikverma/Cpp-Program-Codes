#include <bits/stdc++.h>
using namespace std;

class HEX
{
    string hex;

public:
    string setHex(string hex)
    {
        this->hex = hex;
    }
};

class RGB
{
    int red;
    int green;
    int blue;

public:
    void setRGB(int r, int g, int b)
    {
        this->red = r;
        this->green = g;
        this->blue = b;
    }
};

class CMY
{
    int cyan;
    int magenta;
    int yellow;

public:
    void setRGB(int c, int m, int y)
    {
        this->cyan = c;
        this->magenta = m;
        this->yellow = y;
    }
};

class ColorConverter
{
    string hexToRGB(HEX hexValue, RGB rgbValue)
    {
    }
};