#include <iostream>
#include <cstdio>
#include <math.h>

#include "point.h"
#include "circle.h"

using std::cout;
using std::endl;


Circle::Circle (const Point& acenter, float aradius)
{
	mCenter = acenter;
	mRadius = aradius;
}
	
Circle::Circle ()
{
	Circle ({0, 0}, 1);
}
	
Circle::Circle(const Circle& circle)
{
	mCenter.setX(circle.mCenter.getX());		
	mCenter.setY(circle.mCenter.getY());
	
	mRadius = circle.mRadius;		
}
	
Point Circle::getCenter() const {return mCenter;}
	
float Circle::getRadius() const {return mRadius;}
	
void Circle::setCenter(const Point& center) {mCenter = center;}
	
void Circle::setRadius(const float& radius) {mRadius = radius;}
	
float Circle::getArea () const {return 3.14 * mRadius * mRadius;}
	
float Circle::getDistance (const Point& p) const
{
	float r0 = pow(mCenter.getX() - p.getX(), 2) + 
	pow(mCenter.getY() - p.getY(), 2);
	return pow(r0, 0.5) - mRadius;
}
	
bool Circle::isColliding(const Circle& c) const
{
	float r0 = pow(mCenter.getX() - c.mCenter.getX(), 2) +
		pow(mCenter.getY() - c.mCenter.getY(), 2);
	return ((pow(r0, 0.5) - mRadius - c.mRadius) <= 0) ? true : false;
}
	
void Circle::move(const Point& p)
{
	mCenter.setX(mCenter.getX() + p.getX());
	mCenter.setY(mCenter.getY() + p.getY());
}


int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "Point p = " << p << endl;
	cout << "Point q = " << q << endl;
	cout << "p + q = " << p + q << endl;


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

	getchar();
	return 0;

}
	

