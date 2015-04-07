#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

class triangle
{
private:
	float xpos1, ypos1, xpos2, ypos2, xpos3, ypos3;
	float red, green, blue;
public:
	triangle(float x1, float y1, float x2, float y2, float x3, float y3) 
		: xpos1(x1), ypos1(y1), xpos2(x2), ypos2(y2), xpos3(x3), ypos3(y3)
	{}
	void color(float r, float g, float b);
};

#endif