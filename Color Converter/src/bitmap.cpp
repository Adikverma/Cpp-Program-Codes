#include <iostream>

using namespace std;

class HexColor
{
public:
    HexColor() {}
    HexColor(const string &hex) : hex_(hex) {}
    string toRgb() const;
    string toCmyk() const;

private:
    string hex_;
};

class RgbColor
{
public:
    RgbColor() {}
    RgbColor(int red, int green, int blue) : red_(red), green_(green), blue_(blue) {}
    string toHex() const;
    string toCmyk() const;

private:
    int red_;
    int green_;
    int blue_;
};

class CmykColor
{
public:
    CmykColor() {}
    CmykColor(float cyan, float magenta, float yellow, float key) : cyan_(cyan), magenta_(magenta), yellow_(yellow), key_(key) {}
    string toHex() const;
    string toRgb() const;

private:
    float cyan_;
    float magenta_;
    float yellow_;
    float key_;
};

class ColorConverter
{
public:
    ColorConverter(const HexColor &hex) : hex_(hex) {}
    ColorConverter(const RgbColor &rgb) : rgb_(rgb) {}
    ColorConverter(const CmykColor &cmyk) : cmyk_(cmyk) {}
    HexColor toHex() const;
    RgbColor toRgb() const;
    CmykColor toCmyk() const;

private:
    HexColor hex_;
    RgbColor rgb_;
    CmykColor cmyk_;
};

string HexColor::toRgb() const
{
    string redStr = hex_.substr(0, 2);
    string greenStr = hex_.substr(2, 2);
    string blueStr = hex_.substr(4, 2);
    int red = stoi(redStr, 0, 16);
    int green = stoi(greenStr, 0, 16);
    int blue = stoi(blueStr, 0, 16);
    return to_string(red) + "," + to_string(green) + "," + to_string(blue);
}

string HexColor::toCmyk() const
{
    RgbColor rgb(stoi(hex_.substr(0, 2), 0, 16), stoi(hex_.substr(2, 2), 0, 16), stoi(hex_.substr(4, 2), 0, 16));
    return rgb.toCmyk();
}

string RgbColor::toHex() const
{
    string redStr = to_string(red_);
    string greenStr = to_string(green_);
    string blueStr = to_string(blue_);
    redStr = (red_ < 16 ? "0" : "") + redStr;
    greenStr = (green_ < 16 ? "0" : "") + greenStr;
    blueStr = (blue_ < 16 ? "0" : "") + blueStr;
    return redStr + greenStr + blueStr;
}

string RgbColor::toCmyk() const
{
    float r = static_cast<float>(red_) / 255.0f;
    float g = static_cast<float>(green_) / 255.0f;
    float b = static_cast<float>(blue_) / 255.0f;
    float k = 1.0f - max(max(r, g), b);
    if (k == 1.0f)
    {
        return "0,0,0,100";
    }
    float c = (1.0f - r - k) / (1.0f - k);
}

// under progress
