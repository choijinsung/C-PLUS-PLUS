#ifndef __TRIANGLE_H_
#define __TRIANGLE_H_

#include <iostream>
#include <fstream>
#include <list>
#include "Shape.h"
using namespace std;

class Triangle : public Shape    // 삼각형 class
{
private:
	double xpos1, ypos1, xpos2, ypos2, xpos3, ypos3;    // 세 꼭지점의 x,y 좌표
public:
	Triangle(int num, double x1=0, double y1=0, double x2=0, double y2=0, double x3=0, double y3=0);
	virtual Shape* copyAndPaste(int& cnt) const;
	virtual void translation(const double& dx, const double& dy);
	virtual void scaling(const double& ratio);
	virtual void printGenerate() const;
	virtual void draw(ofstream& fout) const;
};

#endif