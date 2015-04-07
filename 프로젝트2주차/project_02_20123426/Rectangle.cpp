#include <iostream>
#include <fstream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int num, float ulX, float ulY, float lrX, float lrY)
	: Shape(num), upleftX(ulX), upleftY(ulY), lowrightX(lrX), lowrightY(lrY)
{ }

void Rectangle::draw(ofstream& fout) const
{
	fout<<"% draw a rectangle (ID: "<<GetID()<<")"<<endl;
	fout<<"newpath"<<endl;
	fout<<"    "<<upleftX<<" "<<upleftY<<" moveto"<<endl;
	fout<<"    "<<upleftX<<" "<<lowrightY<<" lineto"<<endl;
	fout<<"    "<<lowrightX<<" "<<lowrightY<<" lineto"<<endl;
	fout<<"    "<<lowrightX<<" "<<upleftY<<" lineto"<<endl;
	fout<<"closepath"<<endl;
	fout<<GetRed()<<" "<<GetGreen()<<" ";
	fout<<GetBlue()<<" setrgbcolor"<<endl;
	fout<<"fill"<<endl<<endl;
}