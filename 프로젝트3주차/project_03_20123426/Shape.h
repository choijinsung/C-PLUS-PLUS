#ifndef __SHAPE_H_
#define __SHAPE_H_

#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class Shape // 원, 삼각형, 사각형 class는 도형 class(도형이 가진 특성)을 상속
{
private:
	int id; // 만들어진 도형의 번호
	double red, green, blue; // 도형의 색깔
public:
	
	/* Shape을 상속하는 class 내에서는 동일한 기능을 하는 함수들 */
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

	/* Shape을 상속하는 각각의 class 내에서 서로 다른 기능을 하는 함수들 */
	virtual Shape* copyAndPaste(int& cnt) const = 0;
	virtual void translation(const double& dx, const double& dy) { }
	virtual void scaling(const double& ratio) { }
	virtual void printGenerate() const { }
	virtual void draw(ofstream& fout) const = 0;
};

#endif