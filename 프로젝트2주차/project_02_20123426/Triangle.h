#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Triangle : public Shape
{
private:
	float xpos1, ypos1, xpos2, ypos2, xpos3, ypos3;
public:
	Triangle(int num=0, float x1=0, float y1=0, float x2=0, float y2=0, float x3=0, float y3=0);
	virtual void draw(ofstream& fout) const;
};

#endif