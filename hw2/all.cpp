#include <iostream>
#include "point.h"
#include <math.h>

using std::cout;
using std::endl;


class Circle
{
private:
	Point mCenter;
	float mRadius;

public:
	Circle (const Point& acenter, float aradius)
	{
		mCenter = acenter;
		mRadius = aradius;
	}
	
	Circle ()
	{
		Circle ({0, 0}, 1);
	}
	
	Circle(const Circle& circle)
	{
		
	}
	
	Point getCenter() const {return mCenter;}
	
	float getRadius() const {return mRadius;}
	
	void setCenter(const Point& center) {mCenter = center;}
	
	void setRadius(const float& radius) {mRadius = radius;}
	
	float getArea () const {return 3.14 * mRadius * mRadius;}
	
	float getDistance (const Point& p) const
	{
		float r0 = pow(mCenter.getX() - p.getX(), 2) + 
		pow(mCenter.getY() - p.getY(), 2);
		return pow(r0, 0.5) - mRadius;
	}
	
	bool isColliding(const Circle& c) const
	{
		float r0 = pow(mCenter.getX() - c.mCenter.getX(), 2) +
			pow(mCenter.getY() - c.mCenter.getY(), 2);
		return ((pow(r0, 0.5) - mRadius - c.mRadius) <= 0) ? true : false;
	}
	
	void move(const Point& p)
	{
		mCenter.setX(mCenter.getX() + p.getX());
		mCenter.setY(mCenter.getY() + p.getY());
	}
	
};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "Point p = " << p << endl;
	cout << "Point q = " << q << endl;
	cout << "p + q = " << p + q << endl;

/*
	Circle a {{4, 1}, 3};
	Circle b;

	cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << endl; 
	cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << endl;

	cout << "Area of a = " << a.getArea() << endl;
	cout << "Distance from point p to circle a = " << a.getDistance(p) << endl;



	cout << "Collisions:" << endl;
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;



	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.isColliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
*/

	return 0;

}
