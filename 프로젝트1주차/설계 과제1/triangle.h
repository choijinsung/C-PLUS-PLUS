#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
public:
	/* »ý¼ºÀÚ */
	Triangle();

	/* µ¥ÀÌÅÍ ¾ò±â */
	double Get_X1();
	double Get_Y1();
	double Get_X2();
	double Get_Y2();
	double Get_X3();
	double Get_Y3();
	double Get_Color(int num); // »ö±ò ¾ò±â (r=0, g=1, b=2)

	/* µ¥ÀÌÅÍ ÀÔ·Â */
	void Set_X1(double _x);
	void Set_Y1(double _y);
	void Set_X2(double _x);
	void Set_Y2(double _y);
	void Set_X3(double _x);
	void Set_Y3(double _y);
	void Set_Color(double R, double G, double B);

private:
	/* ¹Ý½Ã°è¹æÇâ ÁÂÇ¥ */
	double x1, y1; // Ã¹¹øÂ° ÁÂÇ¥
	double x2, y2; // µÎ¹øÂ° ÁÂÇ¥
	double x3, y3; // ¼¼¹øÂ° ÁÂÇ¥
	double color[3]; // »ö±ò (r=0, g=1, b=2)
	
};

#endif