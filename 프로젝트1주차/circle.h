#ifndef _CIRCLE_H_
#define _CIRCLE_H_

class circle
{
private:
	float xpos, ypos;
	float radius;
	float red, green, blue;
public:
	circle(float x, float y, float r) : xpos(x), ypos(y), radius(r)
	{}
	void color(float r, float g, float b);
};

#endif