#include "circle.h"

Circle::Circle() :x(0), y(0), r(0) { }

double Circle::Get_X()
{
	return x;
}
double Circle::Get_Y()
{
	return y;
}
double Circle::Get_R()
{
	return r;
}
double Circle::Get_Color(int num)
{
	return color[num];
}
void Circle::Set_X(double _x)
{
	x=_x;
}
void Circle::Set_Y(double _y)
{
	y=_y;
}
void Circle::Set_R(double _r)
{
	r=_r;
}
void Circle::Set_Color(double R, double G, double B)
{
	color[0] = R;
	color[1] = G;
	color[2] = B;
}