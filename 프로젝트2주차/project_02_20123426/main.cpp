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

	cout<<"���� ����� ���� �����մϴ�."<<endl;

	while(1)
	{
		cout<<"��带 �����Ͻʽÿ�."<<endl;
		cout<<"(1) ���� �׸���, (2) ���� ����, (x) ���α׷� ����: ";
		cin>>selectMode;

		if(selectMode=='1')
		{
			char selectShape;
			cout<<"���� �� �׸��� ���� ���� �ϳ��� �����Ͻʽÿ�."<<endl;
			cout<<"(a) ��, (b) �ﰢ��, (c) �簢��: ";
			cin>>selectShape;

			if(selectShape=='a')
			{
				float x,y,r;
				float rVal, gVal, bVal;
			
				cout<<"���� �߽� ��ǥ (x,y) ���� �Է��ϼ���: ";
				cin>>x>>y;
			
				cout<<"���� ������ R ���� �Է��ϼ���: ";
				cin>>r;
			
				cout<<"���� ���� (r,g,b) ���� �Է��ϼ���: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Circle(count++,x,y,r);
				shapePtr->color(rVal,gVal,bVal);
				ls.push_back(shapePtr);

				cout<<"��(���� ID:"<<shapePtr->GetID()<<")�� �����Ǿ����ϴ�."<<endl;
			}
			else if(selectShape=='b')
			{
				float x1, y1, x2, y2, x3, y3;
				float rVal, gVal, bVal;

				cout<<"�ﰢ���� �� ������ ��ǥ (x,y) ���� �ݽð� ���� ������ �Է��ϼ���: ";
				cin>>x1>>y1>>x2>>y2>>x3>>y3;
				
				cout<<"�ﰢ���� ���� (r,g,b) ���� �Է��ϼ���: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Triangle(count++,x1,y1,x2,y2,x3,y3);
				shapePtr->color(rVal,gVal,bVal);
				ls.push_back(shapePtr);

				cout<<"�ﰢ��(���� ID:"<<shapePtr->GetID()<<")�� �����Ǿ����ϴ�."<<endl;
			}
			else if(selectShape=='c')
			{
				float ulX, ulY, lrX, lrY;
				float rVal, gVal, bVal;

				cout<<"�簢���� �»�� ��ǥ (x,y) ���� �Է��ϼ���: ";
				cin>>ulX>>ulY;
				cout<<"�簢���� ���ϴ� ��ǥ (x,y) ���� �Է��ϼ���: ";
				cin>>lrX>>lrY;

				cout<<"�簢���� ���� (r,g,b) ���� �Է��ϼ���: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Rectangle(count++, ulX, ulY, lrX, lrY);
				shapePtr->color(rVal, gVal, bVal);
				ls.push_back(shapePtr);

				cout<<"�簢��(���� ID:"<<shapePtr->GetID()<<")�� �����Ǿ����ϴ�."<<endl;
			}
		}
		else if(selectMode=='2')
		{
			int shapeID;
			cout<<"������ ������ ID�� �Է��ϼ���: ";
			cin>>shapeID;

			char process;
			cout<<"���õ� ������ ���� ������ �۾��� �Է��ϼ���."<<endl;
			cout<<"(d) ����: ";
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
			cout<<"���ݱ��� �׸� ������ ������ ���� �̸��� �Է��ϼ���: ";
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
			cout<<"���� ���丮�� "<<filename<<" ������ �����Ǿ����ϴ�."<<endl;
			cout<<"���� ����� ���� �����մϴ�."<<endl;
			break;
		}
	}
}