#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class rectangle
{
private:
	float upleftX, upleftY, lowrightX, lowrightY;
	float red, green, blue;
public:
	rectangle(float ulX, float ulY, float lrX, float lrY)
		: upleftX(ulX), upleftY(ulY), lowrightX(lrX), lowrightY(lrY)
	{}
	void color(float r, float g, float b);
};

#endif