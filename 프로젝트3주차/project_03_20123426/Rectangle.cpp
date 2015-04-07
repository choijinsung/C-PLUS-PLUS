#include <iostream>
#include <fstream>
#include <list>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int num, double ulX, double ulY, double lrX, double lrY)
	: Shape(num), upleftX(ulX), upleftY(ulY), lowrightX(lrX), lowrightY(lrY)
{ }

Shape* Rectangle::copyAndPaste(int& cnt) const       // 복사 및 붙여넣기
{
	Shape* s=new Rectangle(cnt, upleftX+0.5, upleftY-0.5, lowrightX+0.5, lowrightY-0.5);     // 복사된 도형의 x,y 좌표를 기존의 도형과 다른 위치로 설정
	cnt++;
	s->color(GetRed(), GetGreen(), GetBlue());
	return s;
}

void Rectangle::translation(const double& dx, const double& dy)    // 이동
{
	upleftX+=dx, upleftY+=dy;
	lowrightX+=dx, lowrightY+=dy;
}

void Rectangle::scaling(const double& ratio) { }    

void Rectangle::printGenerate() const
{
	cout<<"사각형(도형 ID: "<<GetID()<<")이 생성되었습니다."<<endl;
}

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