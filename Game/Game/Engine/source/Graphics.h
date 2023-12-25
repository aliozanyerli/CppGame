#pragma once

//opengl libraries
#include <GLFW/glfw3.h>

//c++ libraries
#include <string>

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
}