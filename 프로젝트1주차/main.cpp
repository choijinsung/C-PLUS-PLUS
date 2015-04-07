#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
using namespace std;

class save
{
public:
	char option;
	float xpos, ypos;
	float radius;
	float xpos1, ypos1, xpos2, ypos2, xpos3, ypos3;
	float upleftX, upleftY, lowrightX, lowrightY;
	float red, green, blue;
};

void print(save mySave[], int count, char filename[]);

void main()
{
	int count=0;
	char select;
	save mySave[100];

	cout<<"도형 드로잉 툴을 구동합니다."<<endl;

	while(1)
	{
		cout<<"다음 중 그리고 싶은 도형 하나를 선택하십시오."<<endl;
		cout<<"(a) 원, (b) 삼각형, (c) 사각형, (x) 프로그램 종료: ";
		cin>>select;

		if(select=='a')
		{
			float x,y,r;
			float rVal, gVal, bVal;
			
			cout<<"원의 중심 좌표 (x,y) 값을 입력하세요: ";
			cin>>x>>y;
			
			cout<<"원의 반지름 R 값을 입력하세요: ";
			cin>>r;
			
			circle myCircle(x,y,r);
			
			cout<<"원의 색깔 (r,g,b) 값을 입력하세요: ";
			cin>>rVal>>gVal>>bVal;
			
			myCircle.color(rVal, gVal, bVal);

			mySave[++count].option='a';
			mySave[count].xpos=x;
			mySave[count].ypos=y;
			mySave[count].radius=r;
			mySave[count].red=rVal;
			mySave[count].green=gVal;
			mySave[count].blue=bVal;
		}
		else if(select=='b')
		{
			float x1, y1, x2, y2, x3, y3;
			float rVal, gVal, bVal;

			cout<<"삼각형의 세 꼭지점 좌표 (x,y) 값을 반시계 방향 순서로 입력하세요: ";
			cin>>x1>>y1>>x2>>y2>>x3>>y3;

			triangle myTriangle(x1, y1, x2, y2, x3, y3);

			cout<<"삼각형의 색깔 (r,g,b) 값을 입력하세요: ";
			cin>>rVal>>gVal>>bVal;

			myTriangle.color(rVal, gVal, bVal);

			mySave[++count].option='b';
			mySave[count].xpos1=x1;
			mySave[count].ypos1=y1;
			mySave[count].xpos2=x2;
			mySave[count].ypos2=y2;
			mySave[count].xpos3=x3;
			mySave[count].ypos3=y3;
			mySave[count].red=rVal;
			mySave[count].green=gVal;
			mySave[count].blue=bVal;
		}
		else if(select=='c')
		{
			float ulX, ulY, lrX, lrY;
			float rVal, gVal, bVal;

			cout<<"사각형의 좌상단 좌표 (x,y) 값을 입력하세요: ";
			cin>>ulX>>ulY;
			cout<<"사각형의 우하단 좌표 (x,y) 값을 입력하세요: ";
			cin>>lrX>>lrY;

			rectangle myRectangle(ulX, ulY, lrX, lrY);

			cout<<"사각형의 색깔 (r,g,b) 값을 입력하세요: ";
			cin>>rVal>>gVal>>bVal;

			myRectangle.color(rVal, gVal, bVal);

			mySave[++count].option='c';
			mySave[count].upleftX=ulX;
			mySave[count].upleftY=ulY;
			mySave[count].lowrightX=lrX;
			mySave[count].lowrightY=lrY;
			mySave[count].red=rVal;
			mySave[count].green=gVal;
			mySave[count].blue=bVal;
		}
		else if(select=='x')
		{
			char filename[50];
			cout<<"지금까지 그린 도형을 저장할 파일 이름을 입력하세요: ";
			cin>>filename;
			print(mySave, count, filename);
			cout<<"현재 디렉토리에 "<<filename<<" 파일이 생성되었습니다."<<endl;
			cout<<"도형 드로잉 툴을 종료합니다."<<endl;
			break;
		}
	}
}

void print(save mySave[], int count, char filename[])
{
	ofstream fout;
	strcat(filename, ".ps");
	fout.open(filename);

	fout<<"%!"<<endl;
	fout<<"50 50 scale"<<endl<<endl;

	for(int i=0; i<=count; i++)
	{
		switch(mySave[i].option)
		{
		case 'a':
			fout<<"% draw a circle"<<endl;
			fout<<"newpath"<<endl;
			fout<<"    "<<mySave[i].xpos<<" "<<mySave[i].ypos<<" ";
			fout<<mySave[i].radius<<" 0 360 arc"<<endl;
			fout<<"closepath"<<endl;
			fout<<mySave[i].red<<" "<<mySave[i].green<<" ";
			fout<<mySave[i].blue<<" setrgbcolor"<<endl;
			fout<<"fill"<<endl<<endl;
			break;
		case 'b':
			fout<<"% draw a triangle"<<endl;
			fout<<"newpath"<<endl;
			fout<<"    "<<mySave[i].xpos1<<" "<<mySave[i].ypos1<<" moveto"<<endl;
			fout<<"    "<<mySave[i].xpos2<<" "<<mySave[i].ypos2<<" lineto"<<endl;
			fout<<"    "<<mySave[i].xpos3<<" "<<mySave[i].ypos3<<" lineto"<<endl;
			fout<<"closepath"<<endl;
			fout<<mySave[i].red<<" "<<mySave[i].green<<" ";
			fout<<mySave[i].blue<<" setrgbcolor"<<endl;
			fout<<"fill"<<endl<<endl;
			break;
		case 'c':
			fout<<"% draw a rectangle"<<endl;
			fout<<"newpath"<<endl;
			fout<<"    "<<mySave[i].upleftX<<" "<<mySave[i].upleftY<<" moveto"<<endl;
			fout<<"    "<<mySave[i].upleftX<<" "<<mySave[i].lowrightY<<" lineto"<<endl;
			fout<<"    "<<mySave[i].lowrightX<<" "<<mySave[i].lowrightY<<" lineto"<<endl;
			fout<<"    "<<mySave[i].lowrightX<<" "<<mySave[i].upleftY<<" lineto"<<endl;
			fout<<"closepath"<<endl;
			fout<<mySave[i].red<<" "<<mySave[i].green<<" ";
			fout<<mySave[i].blue<<" setrgbcolor"<<endl;
			fout<<"fill"<<endl<<endl;
			break;
		}
	}
	fout<<"showpage"<<endl;
	fout.close();
}