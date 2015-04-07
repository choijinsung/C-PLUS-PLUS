#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
public:
	/* ������ */
	Triangle();

	/* ������ ��� */
	double Get_X1();
	double Get_Y1();
	double Get_X2();
	double Get_Y2();
	double Get_X3();
	double Get_Y3();
	double Get_Color(int num); // ���� ��� (r=0, g=1, b=2)

	/* ������ �Է� */
	void Set_X1(double _x);
	void Set_Y1(double _y);
	void Set_X2(double _x);
	void Set_Y2(double _y);
	void Set_X3(double _x);
	void Set_Y3(double _y);
	void Set_Color(double R, double G, double B);

private:
	/* �ݽð���� ��ǥ */
	double x1, y1; // ù��° ��ǥ
	double x2, y2; // �ι�° ��ǥ
	double x3, y3; // ����° ��ǥ
	double color[3]; // ���� (r=0, g=1, b=2)
	
};

#endif