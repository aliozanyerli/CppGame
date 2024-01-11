#pragma once



/// Vectors
struct Vector2{
	float x = 0.0;
	float y = 0.0;
	Vector2 operator+(Vector2 v){
		return {x+v.x, y+v.y};
	}
	Vector2 operator-(Vector2 v){
		v.x -= x;
		v.y -= y;
		return v;
	}
	Vector2 operator*(float f){
		return {x*f, y*f};
	}
	Vector2 operator/(float f){
		return {x/f, y/f};
	}
};
struct Vector3{
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	Vector3 operator+(Vector3 v){
		return {x+v.x, y+v.y, z+v.z};
	}
	Vector3 operator-(Vector3 v){
		return {x-v.x, y-v.y, z-v.z};
	}
	Vector3 operator*(float f){
		return {x*f, y*f, z*f};
	}
	Vector3 operator/(float f){
		return {x/f, y/f, z/f};
	}
};
struct Vector4{
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	float w = 0.0;
	Vector4 operator+(Vector4 v){
		return {x+v.x, y+v.y, z+v.z, w+v.w};
	}
	Vector4 operator-(Vector4 v){
		return {x-v.x, y-v.y, z-v.z, w-v.w};
	}
	Vector4 operator*(float f){
		return {x*f, y*f, z*f, w*f};
	}
	Vector4 operator/(float f){
		return {x/f, y/f, z/f, w/f};
	}
};