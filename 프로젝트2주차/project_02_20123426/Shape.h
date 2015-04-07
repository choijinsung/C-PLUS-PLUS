#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <iostream>
#include <fstream>
using namespace std;

class Shape
{
private:
	int id;
	float red, green, blue;
public:
	Shape(int num=0) : id(num) { }
	int GetID() const { return id; }
	float GetRed() const { return red; }
	float GetGreen() const { return green; }
	float GetBlue() const { return blue; }
	void color(const float& r, const float& g, const float& b)
	{
		red=r;
		green=g;
		blue=b;
	}
	virtual void draw(ofstream& fout) const = 0;
};

#endif