#include <iostream>
#include <fstream>
#include "Circle.h"
using namespace std;

Circle::Circle(int num, float x, float y, float r) 
	: Shape(num), xpos(x), ypos(y), radius(r) 
{ }
	
void Circle::draw(ofstream& fout) const
{
	fout<<"% draw a circle (ID: "<<GetID()<<")"<<endl;
	fout<<"newpath"<<endl;
	fout<<"    "<<xpos<<" "<<ypos<<" ";
	fout<<radius<<" 0 360 arc"<<endl;
	fout<<"closepath"<<endl;
	fout<<GetRed()<<" "<<GetGreen()<<" ";
	fout<<GetBlue()<<" setrgbcolor"<<endl;
	fout<<"fill"<<endl<<endl;
}