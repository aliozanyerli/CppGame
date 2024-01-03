#pragma once

//opengl libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//c++ libraries
#include <string>
#include <vector>

#include "MyMath.h"

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
		Vector2 verticies[3];
		Vector2 position, scale;
		
		Triangle();
		Triangle(Vector2 position,Vector2 scale);
		Triangle(Vector2 verticies[3],Vector2 position,Vector2 scale);

		void Render();
	};

}