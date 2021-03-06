#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
public:
	/* 생성자 */
	Triangle();

	/* 데이터 얻기 */
	double Get_X1();
	double Get_Y1();
	double Get_X2();
	double Get_Y2();
	double Get_X3();
	double Get_Y3();
	double Get_Color(int num); // 색깔 얻기 (r=0, g=1, b=2)

	/* 데이터 입력 */
	void Set_X1(double _x);
	void Set_Y1(double _y);
	void Set_X2(double _x);
	void Set_Y2(double _y);
	void Set_X3(double _x);
	void Set_Y3(double _y);
	void Set_Color(double R, double G, double B);

private:
	/* 반시계방향 좌표 */
	double x1, y1; // 첫번째 좌표
	double x2, y2; // 두번째 좌표
	double x3, y3; // 세번째 좌표
	double color[3]; // 색깔 (r=0, g=1, b=2)
	
};

#endif