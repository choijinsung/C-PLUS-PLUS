#include <iostream>
#include <fstream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(int num, float x1, float y1, float x2, float y2, float x3, float y3) 
	: Shape(num), xpos1(x1), ypos1(y1), xpos2(x2), ypos2(y2), xpos3(x3), ypos3(y3)
{ }
	
void Triangle::draw(ofstream& fout) const
{
	fout<<"% draw a triangle (ID: "<<GetID()<<")"<<endl;
	fout<<"newpath"<<endl;
	fout<<"    "<<xpos1<<" "<<ypos1<<" moveto"<<endl;
	fout<<"    "<<xpos2<<" "<<ypos2<<" lineto"<<endl;
	fout<<"    "<<xpos3<<" "<<ypos3<<" lineto"<<endl;
	fout<<"closepath"<<endl;
	fout<<GetRed()<<" "<<GetGreen()<<" ";
	fout<<GetBlue()<<" setrgbcolor"<<endl;
	fout<<"fill"<<endl<<endl;
}