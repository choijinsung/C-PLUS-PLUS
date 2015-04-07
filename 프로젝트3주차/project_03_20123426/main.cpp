/* Project : ���� ����� �� ����� */
/* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 2�г� 20123426 ������ */

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
	int count=0;                 // ������� ������ �ϳ��� ������� �־����� ��ȣ(ID)
	char selectMode;             // ��� ������ �� ���� ��ȣ 

	cout<<"���� ����� ���� �����մϴ�."<<endl;

	while(1)
	{
		cout<<"��带 �����Ͻʽÿ�."<<endl;
		cout<<"(1) ���� �׸���, (2) ���� ����, (x) ���α׷� ����: ";
		cin>>selectMode;

		if(selectMode=='1')      // ���� �׸���
		{
			char selectShape;    // �׸� ���� ������ �� ���� ��ȣ
			cout<<"���� �� �׸��� ���� ���� �ϳ��� �����Ͻʽÿ�."<<endl;
			cout<<"(a) ��, (b) �ﰢ��, (c) �簢��: ";
			cin>>selectShape;

			if(selectShape=='a') // �� �׸���
			{
				double x,y,r;
				double rVal, gVal, bVal;
			
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
			else if(selectShape=='b')   // �簢�� �׸���
			{
				double x1, y1, x2, y2, x3, y3;
				double rVal, gVal, bVal;

				cout<<"�ﰢ���� �� ������ ��ǥ (x,y) ���� �ݽð� ���� ������ �Է��ϼ���: ";
				cin>>x1>>y1>>x2>>y2>>x3>>y3;
				
				cout<<"�ﰢ���� ���� (r,g,b) ���� �Է��ϼ���: ";
				cin>>rVal>>gVal>>bVal;

				Shape* shapePtr=new Triangle(count++,x1,y1,x2,y2,x3,y3);
				shapePtr->color(rVal,gVal,bVal);
				ls.push_back(shapePtr);

				cout<<"�ﰢ��(���� ID:"<<shapePtr->GetID()<<")�� �����Ǿ����ϴ�."<<endl;
			}
			else if(selectShape=='c')   // �ﰢ�� �׸���
			{
				double ulX, ulY, lrX, lrY;
				double rVal, gVal, bVal;

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
		else if(selectMode=='2')    // ���� �����ϱ�
		{
			int numOfShape;  // ������ ������ ���� 
			cout<<"������ ������ ������ ID�� �Է��ϼ���: ";
			cin>>numOfShape;
			int* IDptr=new int[numOfShape];  // ������ ������ ID�� ������ �迭�� ���� �Ҵ�(index�� ������ ������ ����)
			for(int i=0; i<numOfShape; i++)
				cin>>IDptr[i];

			char process;  // ������ �۾��� ���� ��ȣ
			cout<<"���õ� ������ ���� ������ �۾��� �Է��ϼ���."<<endl;
			cout<<"(a) ���� �� �ٿ��ֱ�, (b) �� ������ ��������, (c) �� �ڷ� ������, (t) �̵�, (s) Ȯ�����, (d) ����: ";
			cin>>process;
			
			if(process=='a')  // ���� �� �ٿ��ֱ�
			{
				for(int i=0; i<numOfShape; i++)  // ������ ������ ������� �ݺ��� ����
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							const Shape* s=(*it);  // it�� ����Ű�� ������ ������ ����
							Shape* ref=s->copyAndPaste(count);   // ������ ���� �ٸ��� ����ϴ� �����Լ�
							ls.push_back(ref);  // ���� ������� �����ͺ����� list�� �߰�
							ref->printGenerate();
							break;
						}
			}
			else if(process=='b')   // �� ������ ��������
			{
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							ls.push_back(*it);  // it�� ����Ű�� ������ list�� �� �ڷ� ������
							ls.erase(it);   // ���� ��ġ�� ������ ����
							break;
						}
			}
			else if(process=='c')   // �� �ڷ� ������
			{
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							ls.push_front(*it);  // it�� ����Ű�� ������ list�� �� ������ ����
							ls.erase(it);   // ���� ��ġ�� ������ ����
							break;
						}
			}
			else if(process=='t')   // �̵�
			{
				double dx, dy;
				cout<<"�̵��� (dx, dy) ���� �Է��ϼ���: ";
				cin>>dx>>dy;
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							Shape *s=(*it); 
							s->translation(dx, dy);   // ������ ���� �ٸ��� ����ϴ� �����Լ�
							break;
						}
			}
			else if(process=='s')   // Ȯ�����
			{
				double p;
				cout<<"Ȯ����ҷ��� �Է��ϼ���: ";
				cin>>p;
				for(int i=0; i<numOfShape; i++)
					for(it=ls.begin(); it!=ls.end(); ++it)
						if((*it)->GetID()==IDptr[i])
						{
							Shape *s=(*it);
							s->scaling(p);    // ������ ���� �ٸ��� ����ϴ� �����Լ�
							break;
						}
			}
			else if(process=='d')   // ����
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
				s->draw(fout);  // ������ ���� �ٸ��� ����ϴ� �����Լ�
			}
	
			fout<<"showpage"<<endl;
			fout.close();
			cout<<"���� ���丮�� "<<filename<<" ������ �����Ǿ����ϴ�."<<endl;
			cout<<"���� ����� ���� �����մϴ�."<<endl;
			break;
		}
	}
}