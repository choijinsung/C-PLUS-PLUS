#include "triangle.h"

Triangle::Triangle() :x1(0), y1(0), x2(0), y2(0), x3(0), y3(0){}
double Triangle::Get_X1()
{
	return x1;
}
double Triangle::Get_Y1()
{
	return y1;
}
double Triangle::Get_X2()
{
	return x2;
}
double Triangle::Get_Y2()
{
	return y2;
}
double Triangle::Get_X3()
{
	return x3;
}
double Triangle::Get_Y3()
{
	return y3;
}
double Triangle::Get_Color(int num)
{
	return color[num];
}
void Triangle::Set_X1(double _x)
{
	x1=_x;
}
void Triangle::Set_Y1(double _y)
{
	y1=_y;
}
void Triangle::Set_X2(double _x)
{
	x2=_x;
}
void Triangle::Set_Y2(double _y)
{
	y2=_y;
}
void Triangle::Set_X3(double _x)
{
	x3=_x;
}
void Triangle::Set_Y3(double _y)
{
	y3=_y;
}
void Triangle::Set_Color(double R, double G, double B)
{
	color[0]=R;
	color[1]=G;
	color[2]=B;
}