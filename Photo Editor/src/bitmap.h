#include <bits/stdc++.h>
using namespace std;

class PhotoEditor
{
private:
	vector<vector<vector<int>>> photo;
	int width, height;

public:
	PhotoEditor(int width, int height)
	{
		this->width = width;
		this->height = height;
		vector<vector<vector<int>>> data(height, vector<vector<int>>(width, vector<int>(3, 0)));
		this->photo = data;
	}

	void setPixel(int x, int y, vector<int> rgb)
	{
		photo[y][x] = rgb;
	}

	vector<int> getPixel(int x, int y)
	{
		return photo[y][x];
	}

	vector<vector<vector<int>>> grayscale();

	vector<vector<vector<int>>> crop(int x, int y, int w, int h);

	vector<vector<vector<int>>> contrast(float factor);

	vector<vector<vector<int>>> brightness(int delta);

	vector<vector<vector<int>>> invert();

	vector<vector<vector<int>>> addBorder(int size, const vector<int> &rgb);
};