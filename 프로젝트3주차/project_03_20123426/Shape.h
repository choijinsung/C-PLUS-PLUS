#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Shape // ��, �ﰢ��, �簢�� class�� ���� class(������ ���� Ư��)�� ���
{
private:
	int id; // ������� ������ ��ȣ
	double red, green, blue; // ������ ����
public:
	
	/* Shape�� ����ϴ� class �������� ������ ����� �ϴ� �Լ��� */
	Shape(int num) : id(num) { } 
	int GetID() const { return id; }
	void SetID(int num) { id=num; }
	double GetRed() const { return red; }
	double GetGreen() const { return green; }
	double GetBlue() const { return blue; }
	void color(const double& r, const double& g, const double& b)
	{
		red=r, green=g, blue=b;
	}

	/* Shape�� ����ϴ� ������ class ������ ���� �ٸ� ����� �ϴ� �Լ��� */
	virtual Shape* copyAndPaste(int& cnt) const = 0;
	virtual void translation(const double& dx, const double& dy) { }
	virtual void scaling(const double& ratio) { }
	virtual void printGenerate() const { }
	virtual void draw(ofstream& fout) const = 0;
};

#endif