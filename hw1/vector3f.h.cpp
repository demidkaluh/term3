#include <iostream>
#include <math.h>

#define nichego 


typedef struct Vector3f
{
	float x;
	float y;
	float z;
} Vector3f;


Vector3f operator + (const Vector3f& a, const Vector3f& b)
{
	Vector3f c = {a.x + b.x, a.y + b.y, a.z + b.z};
	return c;
}


Vector3f operator - (const Vector3f& a, const Vector3f& b)
{
	Vector3f c = {a.x - b.x, a.y - b.y, a.z - b.z};
	return c;
}


Vector3f operator * (const Vector3f& a, const float& b)
{
	Vector3f c = {a.x * b, a.y * b, a.z * b};
	return c;
}


Vector3f operator * (const float& b, const Vector3f& a)
{
	return a * b;
}


Vector3f operator / (const Vector3f& a, const float& b)
{
	Vector3f c = {a.x / b, a.y / b, a.z / b};
	return c;
}


float operator * (const Vector3f& a, const Vector3f& b)
{
	float sm = a.x * b.x + a.y * b.y + a.z * b.z;
	return sm;
}


Vector3f operator + (const Vector3f& a)
{
	nichego
	return a;
}

Vector3f operator - (const Vector3f& a)
{
	return a * (-1);
}


bool operator == (const Vector3f& a, const Vector3f& b)
{
	return ((a.x == b.x) and (a.y == b.y) and (a.z == b.z))? true : false;
}


bool operator != (const Vector3f& a, const Vector3f& b)
{
	return (a == b) == false;
}


void operator += ( Vector3f& a, const Vector3f& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}


void operator -= ( Vector3f& a, const Vector3f& b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
}


void operator /= ( Vector3f& a, const float& b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
}


std::ostream& operator << (std::ostream& cout, const Vector3f& a)
{
	cout << "(" << a.x << ", " << a.y << ", " << a.z << ")";
	return cout;
}


/*std::istream& operator >> (std::istream& cin, const Vector3f& a)
{
	cin >> a.x >> a.y >> a.z;
	return cin;
}*/


float norm(const Vector3f& a)
{
	return a.x * a.x + a.y * a.y + a.z * a.z;
}


float squaredNorm(const Vector3f& a)
{
	return sqrt(norm(a));
}


void normalize(Vector3f& a)
{
	a = a / norm(a);
}


