#include <iostream>
#include <fstream>
#include <list>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

void main()
{
	list<Shape*> ls;
	list<Shape*>::iterator it;
	int count=0;
	char selectMode;

	cout<<"도형 드로잉 툴을 구동합니다."<<endl;

	while(1)
	{
		cout<<"모드를 선택하십시오."<<endl;
		cout<<"(1) 도형 그리기, (2) 도형 선택, (x) 프로그램 종료: ";
		cin>>selectMode;

		if(selectMode=='1')
		{
			char selectShape;
			cout<<"다음 중 그리고 싶은 도형 하나를 선택하십시오."<<endl;
			cout<<"(a) 원, (b) 삼각형, (c) 사각형: ";
			cin>>selectShape;

			if(selectShape=='a')
			{
				float x,y,r;
				float rVal, gVal, bVal;
			
				cout<<"원의 중심 좌표 (x,y) 값을 입력하세요: ";
				cin>>x>>y;
			
				cout<<"원의 반지름 R 값을 입력하세요: ";
				cin>>r;
			
				cout<<"원의 색깔 (r,g,b) 값을 입력하세요: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Circle(count++,x,y,r);
				shapePtr->color(rVal,gVal,bVal);
				ls.push_back(shapePtr);

				cout<<"원(도형 ID:"<<shapePtr->GetID()<<")이 생성되었습니다."<<endl;
			}
			else if(selectShape=='b')
			{
				float x1, y1, x2, y2, x3, y3;
				float rVal, gVal, bVal;

				cout<<"삼각형의 세 꼭지점 좌표 (x,y) 값을 반시계 방향 순서로 입력하세요: ";
				cin>>x1>>y1>>x2>>y2>>x3>>y3;
				
				cout<<"삼각형의 색깔 (r,g,b) 값을 입력하세요: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Triangle(count++,x1,y1,x2,y2,x3,y3);
				shapePtr->color(rVal,gVal,bVal);
				ls.push_back(shapePtr);

				cout<<"삼각형(도형 ID:"<<shapePtr->GetID()<<")이 생성되었습니다."<<endl;
			}
			else if(selectShape=='c')
			{
				float ulX, ulY, lrX, lrY;
				float rVal, gVal, bVal;

				cout<<"사각형의 좌상단 좌표 (x,y) 값을 입력하세요: ";
				cin>>ulX>>ulY;
				cout<<"사각형의 우하단 좌표 (x,y) 값을 입력하세요: ";
				cin>>lrX>>lrY;

				cout<<"사각형의 색깔 (r,g,b) 값을 입력하세요: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Rectangle(count++, ulX, ulY, lrX, lrY);
				shapePtr->color(rVal, gVal, bVal);
				ls.push_back(shapePtr);

				cout<<"사각형(도형 ID:"<<shapePtr->GetID()<<")이 생성되었습니다."<<endl;
			}
		}
		else if(selectMode=='2')
		{
			int shapeID;
			cout<<"선택할 도형의 ID를 입력하세요: ";
			cin>>shapeID;

			char process;
			cout<<"선택된 도형에 대해 수행할 작업을 입력하세요."<<endl;
			cout<<"(d) 삭제: ";
			cin>>process;
			
			if(process=='d')
				for(it=ls.begin(); it!=ls.end(); ++it)
					if((*it)->GetID()==shapeID)
					{
						ls.erase(it);
						break;
					}
		}
		else if(selectMode=='x')
		{
			char filename[50];
			cout<<"지금까지 그린 도형을 저장할 파일 이름을 입력하세요: ";
			cin>>filename;
			ofstream fout;
			strcat(filename, ".ps");
			fout.open(filename);

			fout<<"%!"<<endl;
			fout<<"50 50 scale"<<endl<<endl;

			for(it=ls.begin(); it!=ls.end(); ++it)
			{
				const Shape* s=(*it);
				s->draw(fout);
			}
	
			fout<<"showpage"<<endl;
			fout.close();
			cout<<"현재 디렉토리에 "<<filename<<" 파일이 생성되었습니다."<<endl;
			cout<<"도형 드로잉 툴을 종료합니다."<<endl;
			break;
		}
	}
}