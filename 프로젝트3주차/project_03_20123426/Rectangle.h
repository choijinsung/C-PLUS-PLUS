#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include <iostream>
#include <fstream>
#include <list>
#include "Shape.h"
using namespace std;

class Rectangle : public Shape     // 사각형 class
{
private:
	double upleftX, upleftY, lowrightX, lowrightY;     // 좌측상단, 우측하단 꼭지점의 x,y 좌표
public:
	Rectangle(int num, double ulX=0, double ulY=0, double lrX=0, double lrY=0);
	virtual Shape* copyAndPaste(int& cnt) const;
	virtual void translation(const double& dx, const double& dy);
	virtual void scaling(const double& ratio);
	virtual void printGenerate() const;
	virtual void draw(ofstream& fout) const;
};

#endif