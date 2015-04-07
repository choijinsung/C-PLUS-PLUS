#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Rectangle : public Shape
{
private:
	float upleftX, upleftY, lowrightX, lowrightY;
public:
	Rectangle(int num=0, float ulX=0, float ulY=0, float lrX=0, float lrY=0);
	virtual void draw(ofstream& fout) const;
};

#endif