#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "circle.h"		// �� Ŭ����
#include "triangle.h"	// �ﰢ�� Ŭ����
#include "rectangle.h"	// �簢�� Ŭ����

using std::ofstream;
using std::cin;
using std::cout;
using std::endl;

void main()
{
	/* �迭 �� ����, ����� �������� ���� 50���� ���� */
	Circle my_Circle[50];		// �� Ŭ���� �迭
	Triangle my_Triangle[50];	// �ﰢ�� Ŭ���� �迭
	Rectangle my_Rectangle[50];	// �簢�� Ŭ���� �迭
	char title[50];				// .ps���� ����
	char type[50];				// ������ ����
	int turn(0);				// ������ ����
	int circle_count=0, rectangle_count=0, triangle_count=0; // �� ������ ���� ī��Ʈ (�� �迭�� ������� �ֱ�����)
	double x, y, r; 
	double R, G, B;

	cout << "���� ����� ���� �����մϴ�." << endl;
	while(++turn) // ���� ī��Ʈ �ø��鼭 �ݺ��� ����
	{
		/* ���� �Է� */
		cout << "���� �� �׸��� ���� ���� �ϳ��� �����Ͻʽÿ�." << endl;
		cout << "(a) ��, (b) �ﰢ��, (c) �簢��, (x) ���α׷� ����: ";
		cin >> type[turn-1];

		/* �� ������ ������ �Է� */
		switch(type[turn-1])
		{
		case 'a':		
			/* ��ǥ�� �Է� */
			cout << "���� �߽� ��ǥ (x, y) ���� �Է��ϼ���: ";
			cin >> x >> y;
			my_Circle[circle_count].Set_X(x);
			my_Circle[circle_count].Set_Y(y);

			/* ������ �Է� */
			cout << "���� ������ R ���� �Է��ϼ���: ";
			cin >> r;
			my_Circle[circle_count].Set_R(r);

			/* ���� ���� �Է� */
			cout << "���� ���� (r, g, b) ���� �Է��ϼ���: ";
			cin >> R >> G >> B;
			my_Circle[circle_count].Set_Color(R, G, B);

			/* �� ī��Ʈ �ø� (���� �迭�� �ֱ� ����) */
			circle_count++;
			break;

		case 'b':
			/* �ﰢ���� ��ǥ �Է� */
			cout << "�ﰢ���� �� ������ ��ǥ (x, y) ���� �ݽð� ���� ������ �Է��ϼ���: ";
			for(int i=0; i<3; i++)
			{
				cin >> x >> y;
				if(i==0)
				{
					my_Triangle[triangle_count].Set_X1(x);
					my_Triangle[triangle_count].Set_Y1(y);
				}
				else if(i==1)
				{
					my_Triangle[triangle_count].Set_X2(x);
					my_Triangle[triangle_count].Set_Y2(y);
				}
				else
				{
					my_Triangle[triangle_count].Set_X3(x);
					my_Triangle[triangle_count].Set_Y3(y);
				}
			}
			/* �ﰢ���� ���� �Է� */
			cout << "�ﰢ���� ���� (r, g, b) ���� �Է��ϼ���: ";
			cin >> R >> G >> B;
			my_Triangle[triangle_count].Set_Color(R, G, B);

			/* �ﰢ�� ī��Ʈ �ø� */
			triangle_count++;
			break;

		case 'c':
			/* �簢�� �»�� ��ǥ �Է� */
			cout << "�簢���� �»�� ��ǥ (x, y) ���� �Է��ϼ���: ";
			cin >> x >> y;
			my_Rectangle[rectangle_count].Set_UP_X(x);
			my_Rectangle[rectangle_count].Set_UP_Y(y);

			/* �簢�� ���ϴ� ��ǥ �Է� */
			cout << "�簢���� ���ϴ� ��ǥ (x, y) ���� �Է��ϼ���: ";
			cin >> x >> y;
			my_Rectangle[rectangle_count].Set_DOWN_X(x);
			my_Rectangle[rectangle_count].Set_DOWN_Y(y);

			/* �簢�� ���� �Է� */
			cout << "�簢���� ���� (r, g, b) ���� �Է��ϼ���: ";
			cin >> R >> G >> B;
			my_Rectangle[rectangle_count].Set_Color(R, G, B);

			/* �簢�� ī��Ʈ �ø� */
			rectangle_count++;
			break;

		case 'x':
			/* ���� ���� �Է� */
			cout << "���ݱ��� �׸� ������ ������ ���� �̸��� �Է��ϼ���: ";
			cin >> title;
			strcat(title,".ps"); // ���� �ڿ� .ps �ٿ���
			
			cout << "���� ���丮�� " << title << " ������ �����Ǿ����ϴ�." << endl;
			cout << "���� ����� ���� �����մϴ�." << endl;
		}
		/* x�� �Է������ ���ѹݺ��Ǵ� while�� ���� */
		if(type[turn-1]=='x')
			break;
	}

	/* �Է��� �����͸� �̿��� .ps ���� ����� */
	ofstream outStream; 
	circle_count=0, triangle_count=0, rectangle_count=0; // �� ���� ī��Ʈ(�迭�� ����)
	outStream.open(title); // �Է¹޾Ҵ� �������� ���� ���� (������ ������ �����, ������ ����)

	outStream << "%!" << endl;
	outStream << "50 50 scale			% Just scale the coordinate. DO NOT TOUCH THIS LINE." << endl << endl;
	
	/* �Ҽ��� ���ڸ� ��� */
	outStream << std::fixed;
	outStream.precision(1);
	outStream << std::showpoint; // �Ҽ��� ����

	/* �Է��ߴ� ���� ������ ���� */
	for(int i=0; i<turn; i++) // ������ ������ŭ �ݺ�
	{
		switch(type[i])
		{
		case 'a':
			/* ���� x,y��ǥ r�� ���� ���� */
			outStream << "% draw a circle" << endl;
			outStream << "newpath" << endl;
			outStream << "	"  << my_Circle[circle_count].Get_X() << ' ' << my_Circle[circle_count].Get_Y() << ' ' << my_Circle[circle_count].Get_R() << " 0 360 arc";
			outStream << "	% x y r start_angle end_angle" << endl;
			outStream << "closepath" << endl;

			/* ���� ���� ���� */
			outStream << my_Circle[circle_count].Get_Color(0) << ' ' << my_Circle[circle_count].Get_Color(1) << ' ' << my_Circle[circle_count].Get_Color(2) << ' ';
			outStream << "setrgbcolor		% r g b" << endl;
			outStream << "fill				% draw a shape by filling with the current color" << endl << endl;

			/* �� ī��Ʈ �ø� (���� �迭 ����) */
			circle_count++;
			break;

		case 'b':
			/* �ﰢ���� ��ǥ ���� */
			outStream << "% draw a triangle" << endl;
			outStream << "newpath" << endl;
			outStream << "	" << my_Triangle[triangle_count].Get_X1() << ' ' << my_Triangle[triangle_count].Get_Y1() << " moveto" << endl;
			outStream << "	" << my_Triangle[triangle_count].Get_X2() << ' ' << my_Triangle[triangle_count].Get_Y2() << " lineto" << endl;
			outStream << "	" << my_Triangle[triangle_count].Get_X3() << ' ' << my_Triangle[triangle_count].Get_Y3() << " lineto" << endl;
			outStream << "closepath" << endl;

			/* �ﰢ���� ���� ���� */
			outStream << my_Triangle[triangle_count].Get_Color(0) << ' ' << my_Triangle[triangle_count].Get_Color(1) << ' ' << my_Triangle[triangle_count].Get_Color(2) << ' ';
			outStream << "setrgbcolor		% r g b" << endl;
			outStream << "fill				% draw a shape by filling with the current color" << endl << endl;

			/* �ﰢ�� ī��Ʈ �ø� */
			triangle_count++;
			break;

		case 'c':
			/* �簢�� ��ǥ ���� */
			outStream << "% draw a rectangle" << endl;
			outStream << "newpath" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_UP_X() << ' ' << my_Rectangle[rectangle_count].Get_UP_Y() << " moveto" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_UP_X() << ' ' << my_Rectangle[rectangle_count].Get_DOWN_Y() << " lineto" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_DOWN_X() << ' ' << my_Rectangle[rectangle_count].Get_DOWN_Y() << " lineto" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_DOWN_X() << ' ' << my_Rectangle[rectangle_count].Get_UP_Y() << " lineto" << endl;
			outStream << "closepath" << endl;
			
			/* �簢�� ���� ���� */
			outStream << my_Rectangle[rectangle_count].Get_Color(0) << ' ' << my_Rectangle[rectangle_count].Get_Color(1) << ' ' << my_Rectangle[rectangle_count].Get_Color(2) << ' ';
			outStream << "setrgbcolor		%r g b" << endl;
			outStream << "fill				%draw a shape by filling with the current color" << endl << endl;

			/* �簢�� ī��Ʈ �ø� */
			rectangle_count++;
			break;

		case 'x':
			outStream << "showpage" << endl;
		}
	}
	outStream.close(); // ���� �ݱ�
}