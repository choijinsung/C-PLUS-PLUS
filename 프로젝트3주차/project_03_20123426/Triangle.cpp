#include <iostream>
#include <fstream>
#include <list>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(int num, double x1, double y1, double x2, double y2, double x3, double y3) 
	: Shape(num), xpos1(x1), ypos1(y1), xpos2(x2), ypos2(y2), xpos3(x3), ypos3(y3)
{ }

Shape* Triangle::copyAndPaste(int& cnt) const        // ���� �� �ٿ��ֱ�
{
	Shape* s=new Triangle(cnt, xpos1+0.5, ypos1-0.5, xpos2+0.5, ypos2-0.5, xpos3+0.5, ypos3-0.5);     // ����� ������ x,y ��ǥ�� ������ ������ �ٸ� ��ġ�� ����
	cnt++;
	s->color(GetRed(), GetGreen(), GetBlue());
	return s;
}

void Triangle::translation(const double& dx, const double& dy)         // �̵�
{
	xpos1+=dx, ypos1+=dy;
	xpos2+=dx, ypos2+=dy;
	xpos3+=dx, ypos3+=dy;
}

void Triangle::scaling(const double& ratio) { }

void Triangle::printGenerate() const
{
	cout<<"�ﰢ��(���� ID: "<<GetID()<<")�� �����Ǿ����ϴ�."<<endl;
}

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