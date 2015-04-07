#include <iostream>
#include <fstream>
#include <list>
#include "Circle.h"
using namespace std;

Circle::Circle(int num, double x, double y, double r) 
	: Shape(num), xpos(x), ypos(y), radius(r) 
{ }

Shape* Circle::copyAndPaste(int& cnt) const     // 복사 및 붙여넣기
{
	Shape* s=new Circle(cnt, xpos+0.5, ypos-0.5, radius);   // 복사된 도형의 x,y 좌표를 기존의 도형과 다른 위치로 설정
	cnt++;
	s->color(GetRed(), GetGreen(), GetBlue());
	return s;
}

void Circle::translation(const double& dx, const double& dy)    // 이동
{
	xpos+=dx, ypos+=dy;
}

void Circle::scaling(const double& ratio)    // 확대축소
{
	radius*=ratio;
}

void Circle::printGenerate() const
{
	cout<<"원(도형 ID: "<<GetID()<<")이 생성되었습니다."<<endl;
}

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