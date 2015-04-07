#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include <iostream>
#include <fstream>
#include <list>
#include "Shape.h"
using namespace std;

class Circle : public Shape     // 원 class
{
private:
	double xpos, ypos;      // 중심의 x,y 좌표
	double radius;       // 반지름의 길이
public:
	Circle(int num, double x=0, double y=0, double r=0);
	virtual Shape* copyAndPaste(int& cnt) const;
	virtual void translation(const double& dx, const double& dy);
	virtual void scaling(const double& ratio);
	virtual void printGenerate() const;
	virtual void draw(ofstream& fout) const;
};

#endif