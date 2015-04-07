#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
	/* ������ */
	Circle();

	/* ������ ��� */
	double Get_X();
	double Get_Y();
	double Get_R();
	double Get_Color(int num); // num��° ���� ���(r=0, g=1, b=2)

	/* ������ �Է� */
	void Set_X(double _x);
	void Set_Y(double _y);
	void Set_R(double _r);
	void Set_Color(double R, double G, double B);

private:
	double x, y;
	double r;
	double color[3]; // ����(r=0, g=1, b=2)
};

#endif