#include "../src/bitmap.h"

// Funtion Inputs : This Function does not take any input
// Function Desc : This Function adds a grayscale to all the pixels present in the Photo
// Function returns : This Function returns the edited photo
// Note GrayScale is average of the R, G, B values. Replace R, G and B values of each pixel with Grayscale value calculated.
vector<vector<vector<int>>> PhotoEditor::grayscale()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int gray = (photo[y][x][0] + photo[y][x][1] + photo[y][x][2]) / 3;
            photo[y][x] = {gray, gray, gray};
        }
    }
    return this->photo;
}

// Funtion Inputs : This Function takes input as
// 1. x = starting pixel x coordinate
// 2. y = starting pixel y coordinate
// 3. w = width of the cropped image
// 4. h = height of the cropped image
// Function Desc : This Function returns a cropped image and also updated the photo
// Function returns : This Function returns the edited photo
vector<vector<vector<int>>> PhotoEditor::crop(int x, int y, int w, int h)
{
    w = min(w, width - x);
    h = min(h, height - y);

    vector<vector<vector<int>>> newPhoto(h, vector<vector<int>>(w));

    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            newPhoto[j][i] = photo[j + y][i + x];
        }
    }
    width = w;
    height = h;
    photo = newPhoto;

    return newPhoto;
}

// Funtion Inputs : This Function takes a input as 'factor' the value to be used to contrast
// Function Desc : This Function adds contrast to all the pixels of the photo
// Function returns : The photo is updated with contrast and is returned
// Note: a contrast is an integer value within the range but is equal to the (currentValue -128) * factor + 128 for each R, G and B
vector<vector<vector<int>>> PhotoEditor::contrast(float factor)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                int value = (photo[y][x][c] - 128) * factor + 128;
                value = max(0, min(255, value));
                photo[y][x][c] = value;
            }
        }
    }
    return this->photo;
}

// Funtion Inputs : This Function takes a input as 'delta' the value to be used to adjust brightness
// Function Desc : This Function adds brightness to all the pixels of the photo, either positive or negative
// Function returns : The photo is updated with adjusted brightness and is returned
// Note: a adjusted brightness is an integer value within the range but is equal to the (currentValue + delta) for each R, G and B
vector<vector<vector<int>>> PhotoEditor::brightness(int delta)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                int value = photo[y][x][c] + delta;
                value = max(0, min(255, value));
                photo[y][x][c] = value;
            }
        }
    }
    return this->photo;
}

// Funtion Inputs : This Function does not take any input
// Function Desc : This Function sets the invert to every pixel on the photo
// Function returns : The photo is updated with invert and is returned
// Note: an invert is an integer value within the range but is equal to the (255 - currentValue) for each R, G and B
vector<vector<vector<int>>> PhotoEditor::invert()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                photo[y][x][c] = 255 - photo[y][x][c];
            }
        }
    }
    return this->photo;
}

// Funtion Inputs : This Function takes input as
// 1. size = size of the border
// 2. color = R, G and B values of a color
// Function Desc : This Function adds a border of given color to the photo
// Function returns : The photo is updated with desired border and is returned
vector<vector<vector<int>>> PhotoEditor::addBorder(int size, const vector<int> &rgb)
{
    vector<vector<vector<int>>> newPhoto(height + 2 * size, vector<vector<int>>(width + 2 * size, vector<int>(3, 0)));
    for (int y = 0; y < height + 2 * size; y++)
    {
        for (int x = 0; x < width + 2 * size; x++)
        {
            if (x < size || x >= width + size || y < size || y >= height + size)
            {
                newPhoto[y][x] = rgb;
            }
            else
            {
                newPhoto[y][x] = photo[y - size][x - size];
            }
        }
    }
    width = width + 2 * size;
    height = height + 2 * size;
    photo = newPhoto;

    return this->photo;
}