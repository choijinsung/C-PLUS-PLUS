/* Project : 도형 드로잉 툴 만들기 */
/* 국민대학교 전자정보통신대학 컴퓨터공학부 2학년 20123426 최진성 */

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
	int count=0;                 // 만들어진 도형에 하나씩 순서대로 주어지는 번호(ID)
	char selectMode;             // 모드 선택할 때 고르는 기호 

	cout<<"도형 드로잉 툴을 구동합니다."<<endl;

	while(1)
	{
		cout<<"모드를 선택하십시오."<<endl;
		cout<<"(1) 도형 그리기, (2) 도형 선택, (x) 프로그램 종료: ";
		cin>>selectMode;

		if(selectMode=='1')      // 도형 그리기
		{
			char selectShape;    // 그릴 도형 선택할 때 고르는 기호
			cout<<"다음 중 그리고 싶은 도형 하나를 선택하십시오."<<endl;
			cout<<"(a) 원, (b) 삼각형, (c) 사각형: ";
			cin>>selectShape;

			if(selectShape=='a') // 원 그리기
			{
				double x,y,r;
				double rVal, gVal, bVal;
			
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
			else if(selectShape=='b')   // 사각형 그리기
			{
				double x1, y1, x2, y2, x3, y3;
				double rVal, gVal, bVal;

				cout<<"삼각형의 세 꼭지점 좌표 (x,y) 값을 반시계 방향 순서로 입력하세요: ";
				cin>>x1>>y1>>x2>>y2>>x3>>y3;
				
				cout<<"삼각형의 색깔 (r,g,b) 값을 입력하세요: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Triangle(count++,x1,y1,x2,y2,x3,y3);
				shapePtr->color(rVal,gVal,bVal);
				ls.push_back(shapePtr);

				cout<<"삼각형(도형 ID:"<<shapePtr->GetID()<<")이 생성되었습니다."<<endl;
			}
			else if(selectShape=='c')   // 삼각형 그리기
			{
				double ulX, ulY, lrX, lrY;
				double rVal, gVal, bVal;

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
		else if(selectMode=='2')    // 도형 선택하기
		{
			int numOfShape;  // 선택할 도형의 개수 
			cout<<"선택할 도형의 개수와 ID를 입력하세요: ";
			cin>>numOfShape;
			int* IDptr=new int[numOfShape];  // 선택할 도형의 ID를 저장할 배열을 동적 할당(index는 선택할 도형의 개수)
			for(int i=0; i<numOfShape; i++)
				cin>>IDptr[i];

			char process;  // 수행할 작업을 고르는 기호
			cout<<"선택된 도형에 대해 수행할 작업을 입력하세요."<<endl;
			cout<<"(a) 복사 및 붙여넣기, (b) 맨 앞으로 가져오기, (c) 맨 뒤로 보내기, (t) 이동, (s) 확대축소, (d) 삭제: ";
			cin>>process;
			
			if(process=='a')  // 복사 및 붙여넣기
			{
				for(int i=0; i<numOfShape; i++)  // 도형을 선택한 순서대로 반복문 실행
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							const Shape* s=(*it);  // it가 가리키는 기존의 정보는 유지
							Shape* ref=s->copyAndPaste(count);   // 도형에 따라 다르게 기능하는 가상함수
							ls.push_back(ref);  // 새로 만들어진 포인터변수를 list에 추가
							ref->printGenerate();
							break;
						}
			}
			else if(process=='b')   // 맨 앞으로 가져오기
			{
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							ls.push_back(*it);  // it가 가리키는 정보를 list의 맨 뒤로 가져옴
							ls.erase(it);   // 현재 위치의 포인터 삭제
							break;
						}
			}
			else if(process=='c')   // 맨 뒤로 보내기
			{
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							ls.push_front(*it);  // it가 가리키는 정보를 list의 맨 앞으로 보냄
							ls.erase(it);   // 현재 위치의 포인터 삭제
							break;
						}
			}
			else if(process=='t')   // 이동
			{
				double dx, dy;
				cout<<"이동량 (dx, dy) 값을 입력하세요: ";
				cin>>dx>>dy;
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							Shape *s=(*it); 
							s->translation(dx, dy);   // 도형에 따라 다르게 기능하는 가상함수
							break;
						}
			}
			else if(process=='s')   // 확대축소
			{
				double p;
				cout<<"확대축소량을 입력하세요: ";
				cin>>p;
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							Shape *s=(*it);
							s->scaling(p);    // 도형에 따라 다르게 기능하는 가상함수
							break;
						}
			}
			else if(process=='d')   // 삭제
			{
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							ls.erase(it);
							break;
						}
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
				s->draw(fout);  // 도형에 따라 다르게 기능하는 가상함수
			}
	
			fout<<"showpage"<<endl;
			fout.close();
			cout<<"현재 디렉토리에 "<<filename<<" 파일이 생성되었습니다."<<endl;
			cout<<"도형 드로잉 툴을 종료합니다."<<endl;
			break;
		}
	}
}