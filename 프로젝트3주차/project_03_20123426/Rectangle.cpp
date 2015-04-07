#include <iostream>
#include <fstream>
#include <list>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(int num, double ulX, double ulY, double lrX, double lrY)
	: Shape(num), upleftX(ulX), upleftY(ulY), lowrightX(lrX), lowrightY(lrY)
{ }

Shape* Rectangle::copyAndPaste(int& cnt) const       // ���� �� �ٿ��ֱ�
{
	Shape* s=new Rectangle(cnt, upleftX+0.5, upleftY-0.5, lowrightX+0.5, lowrightY-0.5);     // ����� ������ x,y ��ǥ�� ������ ������ �ٸ� ��ġ�� ����
	cnt++;
	s->color(GetRed(), GetGreen(), GetBlue());
	return s;
}

void Rectangle::translation(const double& dx, const double& dy)    // �̵�
{
	upleftX+=dx, upleftY+=dy;
	lowrightX+=dx, lowrightY+=dy;
}

void Rectangle::scaling(const double& ratio) { }    

void Rectangle::printGenerate() const
{
	cout<<"�簢��(���� ID: "<<GetID()<<")�� �����Ǿ����ϴ�."<<endl;
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