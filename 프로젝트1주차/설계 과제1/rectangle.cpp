#include "rectangle.h"

Rectangle::Rectangle() : up_x(0), up_y(0), down_x(0), down_y(0) { }
double Rectangle::Get_UP_X()
{
	return up_x;
}
double Rectangle::Get_UP_Y()
{
	return up_y;
}
double Rectangle::Get_DOWN_X()
{
	return down_x;
}
double Rectangle::Get_DOWN_Y()
{
	return down_y;
}
double Rectangle::Get_Color(int num)
{
	return color[num];
}
void Rectangle::Set_UP_X(double _x)
{
	up_x = _x;
}
void Rectangle::Set_UP_Y(double _y)
{
	up_y = _y;
}
void Rectangle::Set_DOWN_X(double _x)
{
	down_x = _x;
}
void Rectangle::Set_DOWN_Y(double _y)
{
	down_y = _y;
}
void Rectangle::Set_Color(double R, double G, double B)
{
	color[0] = R;
	color[1] = G;
	color[2] = B;
}