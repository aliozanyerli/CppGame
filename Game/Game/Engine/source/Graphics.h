#pragma once

//opengl libraries
#include "pch.h"

#include "MyMath.h"
#include "MyTime.h"
#include "Shader.h"
#include "ErrorHandling.h"

using namespace std;



namespace Graphics{
	class Window{
	public:
		int wx, wy;
		char* title;
		GLFWwindow* window;

		Window(int sizeX, int sizeY, const char title[]);
		~Window();

		bool ShouldClose();
		void Update(void(*func)());
	};

	class Triangle{
	public:
		Vector2 verticies[3] = {Vector2(-0.5,-0.5), Vector2(0,0.5), Vector2(0.5,-0.5)};
		Vector2 position, scale;
		
		Triangle();
		void Render();
	private:
		unsigned int buffer;
	};

	class Quad{
	public:
		Vector2 verticies[4] = {Vector2(-0.5,-0.5), Vector2(0.5,-0.5), Vector2(0.5,0.5), Vector2(-0.5,0.5)};
		unsigned int indicies[6] = {0, 1, 2, 0, 2, 3};
		Vector2 position, scale;
		
		Quad();
		void Render();
	private:
		unsigned int buffer;
		unsigned int ibo;
	};

}