#include <iostream>
#include <fstream>
#include <list>
#include "Circle.h"
using namespace std;

Circle::Circle(int num, double x, double y, double r) 
	: Shape(num), xpos(x), ypos(y), radius(r) 
{ }

Shape* Circle::copyAndPaste(int& cnt) const     // ���� �� �ٿ��ֱ�
{
	Shape* s=new Circle(cnt, xpos+0.5, ypos-0.5, radius);   // ����� ������ x,y ��ǥ�� ������ ������ �ٸ� ��ġ�� ����
	cnt++;
	s->color(GetRed(), GetGreen(), GetBlue());
	return s;
}

void Circle::translation(const double& dx, const double& dy)    // �̵�
{
	xpos+=dx, ypos+=dy;
}

void Circle::scaling(const double& ratio)    // Ȯ�����
{
	radius*=ratio;
}

void Circle::printGenerate() const
{
	cout<<"��(���� ID: "<<GetID()<<")�� �����Ǿ����ϴ�."<<endl;
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