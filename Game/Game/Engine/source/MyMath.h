#pragma once



/// Vectors
class Vector2{
public:
	float x, y;
	Vector2(){x=0,y=0;}
	Vector2(float x, float y);
};
class Vector3{
public:
	float x, y, z;
	Vector3(float x, float y, float z);
};

class Vector2d{
public:
	double x, y;
	Vector2d(){x=0,y=0;}
	Vector2d(double x, double y);
};
class Vector3d{
public:
	double x, y, z;
	Vector3d(double x, double y, double z);
};