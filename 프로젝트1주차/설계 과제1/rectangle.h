#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	/* »ý¼ºÀÚ */
	Rectangle();

	/* µ¥ÀÌÅÍ ¾ò±â */
	double Get_UP_X();
	double Get_UP_Y();
	double Get_DOWN_X();
	double Get_DOWN_Y();
	double Get_Color(int num); // »ö±ò ¾ò±â (r=0, g=1, b=2)

	/* µ¥ÀÌÅÍ ÀÔ·Â */
	void Set_UP_X(double _x);
	void Set_UP_Y(double _y);
	void Set_DOWN_X(double _x);
	void Set_DOWN_Y(double _y);
	void Set_Color(double R, double G, double B);

private:
	double up_x, up_y; // ÁÂ»ó´Ü ÁÂÇ¥
	double down_x, down_y; // ¿ìÇÏ´Ü ÁÂÇ¥
	double color[3]; // »ö±ò (r=0, g=1, b=2)
	
};

#endif