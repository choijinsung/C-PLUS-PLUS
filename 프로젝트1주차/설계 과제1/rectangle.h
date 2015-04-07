#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	/* ������ */
	Rectangle();

	/* ������ ��� */
	double Get_UP_X();
	double Get_UP_Y();
	double Get_DOWN_X();
	double Get_DOWN_Y();
	double Get_Color(int num); // ���� ��� (r=0, g=1, b=2)

	/* ������ �Է� */
	void Set_UP_X(double _x);
	void Set_UP_Y(double _y);
	void Set_DOWN_X(double _x);
	void Set_DOWN_Y(double _y);
	void Set_Color(double R, double G, double B);

private:
	double up_x, up_y; // �»�� ��ǥ
	double down_x, down_y; // ���ϴ� ��ǥ
	double color[3]; // ���� (r=0, g=1, b=2)
	
};

#endif