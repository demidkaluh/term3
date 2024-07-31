#include "point.h"
#include <math.h>

class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	Circle (const Point& acenter, float aradius);
	
	Circle ();
	
	Circle(const Circle& circle);
	
	Point getCenter() const;
	
	float getRadius() const;
	
	void setCenter(const Point& center);
	
	void setRadius(const float& radius);
	
	float getArea () const;
	
	float getDistance (const Point& p) const;
	
	bool isColliding(const Circle& c) const;
	
	void move(const Point& p);
};

