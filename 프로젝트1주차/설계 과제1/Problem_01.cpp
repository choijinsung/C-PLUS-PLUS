#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "circle.h"		// 원 클래스
#include "triangle.h"	// 삼각형 클래스
#include "rectangle.h"	// 사각형 클래스

using std::ofstream;
using std::cin;
using std::cout;
using std::endl;

void main()
{
	/* 배열 및 변수, 몇개까지 가능한지 몰라서 50개로 생성 */
	Circle my_Circle[50];		// 원 클래스 배열
	Triangle my_Triangle[50];	// 삼각형 클래스 배열
	Rectangle my_Rectangle[50];	// 사각형 클래스 배열
	char title[50];				// .ps파일 제목
	char type[50];				// 생성한 도형
	int turn(0);				// 도형의 개수
	int circle_count=0, rectangle_count=0, triangle_count=0; // 각 도형의 개수 카운트 (각 배열에 순서대로 넣기위해)
	double x, y, r; 
	double R, G, B;

	cout << "도형 드로잉 툴을 구동합니다." << endl;
	while(++turn) // 개수 카운트 올리면서 반복문 실행
	{
		/* 도형 입력 */
		cout << "다음 중 그리고 싶은 도형 하나를 선택하십시오." << endl;
		cout << "(a) 원, (b) 삼각형, (c) 사각형, (x) 프로그램 종료: ";
		cin >> type[turn-1];

		/* 각 도형의 데이터 입력 */
		switch(type[turn-1])
		{
		case 'a':		
			/* 좌표값 입력 */
			cout << "원의 중심 좌표 (x, y) 값을 입력하세요: ";
			cin >> x >> y;
			my_Circle[circle_count].Set_X(x);
			my_Circle[circle_count].Set_Y(y);

			/* 반지름 입력 */
			cout << "원의 반지름 R 값을 입력하세요: ";
			cin >> r;
			my_Circle[circle_count].Set_R(r);

			/* 원의 색깔 입력 */
			cout << "원의 색깔 (r, g, b) 값을 입력하세요: ";
			cin >> R >> G >> B;
			my_Circle[circle_count].Set_Color(R, G, B);

			/* 원 카운트 올림 (다음 배열에 넣기 위해) */
			circle_count++;
			break;

		case 'b':
			/* 삼각형의 좌표 입력 */
			cout << "삼각형의 세 꼭지점 좌표 (x, y) 값을 반시계 방향 순서로 입력하세요: ";
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
			/* 삼각형의 색깔 입력 */
			cout << "삼각형의 색깔 (r, g, b) 값을 입력하세요: ";
			cin >> R >> G >> B;
			my_Triangle[triangle_count].Set_Color(R, G, B);

			/* 삼각형 카운트 올림 */
			triangle_count++;
			break;

		case 'c':
			/* 사각형 좌상단 좌표 입력 */
			cout << "사각형의 좌상단 좌표 (x, y) 값을 입력하세요: ";
			cin >> x >> y;
			my_Rectangle[rectangle_count].Set_UP_X(x);
			my_Rectangle[rectangle_count].Set_UP_Y(y);

			/* 사각형 우하단 좌표 입력 */
			cout << "사각형의 우하단 좌표 (x, y) 값을 입력하세요: ";
			cin >> x >> y;
			my_Rectangle[rectangle_count].Set_DOWN_X(x);
			my_Rectangle[rectangle_count].Set_DOWN_Y(y);

			/* 사각형 색깔 입력 */
			cout << "사각형의 색깔 (r, g, b) 값을 입력하세요: ";
			cin >> R >> G >> B;
			my_Rectangle[rectangle_count].Set_Color(R, G, B);

			/* 사각형 카운트 올림 */
			rectangle_count++;
			break;

		case 'x':
			/* 파일 제목 입력 */
			cout << "지금까지 그린 도형을 저장할 파일 이름을 입력하세요: ";
			cin >> title;
			strcat(title,".ps"); // 제목 뒤에 .ps 붙여줌
			
			cout << "현재 디렉토리에 " << title << " 파일이 생성되었습니다." << endl;
			cout << "도형 드로잉 툴을 종료합니다." << endl;
		}
		/* x이 입력됬었으면 무한반복되는 while문 나옴 */
		if(type[turn-1]=='x')
			break;
	}

	/* 입력한 데이터를 이용해 .ps 파일 만들기 */
	ofstream outStream; 
	circle_count=0, triangle_count=0, rectangle_count=0; // 각 도형 카운트(배열을 위해)
	outStream.open(title); // 입력받았던 제목으로 파일 열기 (제목이 있을땐 덮어쓰기, 없을땐 생성)

	outStream << "%!" << endl;
	outStream << "50 50 scale			% Just scale the coordinate. DO NOT TOUCH THIS LINE." << endl << endl;
	
	/* 소수점 한자리 출력 */
	outStream << std::fixed;
	outStream.precision(1);
	outStream << std::showpoint; // 소수점 보기

	/* 입력했던 도형 데이터 쓰기 */
	for(int i=0; i<turn; i++) // 도형의 개수만큼 반복
	{
		switch(type[i])
		{
		case 'a':
			/* 원의 x,y좌표 r의 길이 쓰기 */
			outStream << "% draw a circle" << endl;
			outStream << "newpath" << endl;
			outStream << "	"  << my_Circle[circle_count].Get_X() << ' ' << my_Circle[circle_count].Get_Y() << ' ' << my_Circle[circle_count].Get_R() << " 0 360 arc";
			outStream << "	% x y r start_angle end_angle" << endl;
			outStream << "closepath" << endl;

			/* 원의 색깔 쓰기 */
			outStream << my_Circle[circle_count].Get_Color(0) << ' ' << my_Circle[circle_count].Get_Color(1) << ' ' << my_Circle[circle_count].Get_Color(2) << ' ';
			outStream << "setrgbcolor		% r g b" << endl;
			outStream << "fill				% draw a shape by filling with the current color" << endl << endl;

			/* 원 카운트 올림 (다음 배열 위해) */
			circle_count++;
			break;

		case 'b':
			/* 삼각형의 좌표 쓰기 */
			outStream << "% draw a triangle" << endl;
			outStream << "newpath" << endl;
			outStream << "	" << my_Triangle[triangle_count].Get_X1() << ' ' << my_Triangle[triangle_count].Get_Y1() << " moveto" << endl;
			outStream << "	" << my_Triangle[triangle_count].Get_X2() << ' ' << my_Triangle[triangle_count].Get_Y2() << " lineto" << endl;
			outStream << "	" << my_Triangle[triangle_count].Get_X3() << ' ' << my_Triangle[triangle_count].Get_Y3() << " lineto" << endl;
			outStream << "closepath" << endl;

			/* 삼각형의 색깔 쓰기 */
			outStream << my_Triangle[triangle_count].Get_Color(0) << ' ' << my_Triangle[triangle_count].Get_Color(1) << ' ' << my_Triangle[triangle_count].Get_Color(2) << ' ';
			outStream << "setrgbcolor		% r g b" << endl;
			outStream << "fill				% draw a shape by filling with the current color" << endl << endl;

			/* 삼각형 카운트 올림 */
			triangle_count++;
			break;

		case 'c':
			/* 사각형 좌표 쓰기 */
			outStream << "% draw a rectangle" << endl;
			outStream << "newpath" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_UP_X() << ' ' << my_Rectangle[rectangle_count].Get_UP_Y() << " moveto" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_UP_X() << ' ' << my_Rectangle[rectangle_count].Get_DOWN_Y() << " lineto" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_DOWN_X() << ' ' << my_Rectangle[rectangle_count].Get_DOWN_Y() << " lineto" << endl;
			outStream << "	" << my_Rectangle[rectangle_count].Get_DOWN_X() << ' ' << my_Rectangle[rectangle_count].Get_UP_Y() << " lineto" << endl;
			outStream << "closepath" << endl;
			
			/* 사각형 색깔 쓰기 */
			outStream << my_Rectangle[rectangle_count].Get_Color(0) << ' ' << my_Rectangle[rectangle_count].Get_Color(1) << ' ' << my_Rectangle[rectangle_count].Get_Color(2) << ' ';
			outStream << "setrgbcolor		%r g b" << endl;
			outStream << "fill				%draw a shape by filling with the current color" << endl << endl;

			/* 사각형 카운트 올림 */
			rectangle_count++;
			break;

		case 'x':
			outStream << "showpage" << endl;
		}
	}
	outStream.close(); // 파일 닫기
}