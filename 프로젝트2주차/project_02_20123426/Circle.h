#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Circle : public Shape
{
private:
	float xpos, ypos;
	float radius;
public:
	Circle(int num=0, float x=0, float y=0, float r=0);
	virtual void draw(ofstream& fout) const;
};

#endif