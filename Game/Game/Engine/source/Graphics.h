#pragma once

//opengl libraries
#include "pch.h"

#include "MyMath.h"
#include "MyTime.h"
#include "Shader.h"

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
		void Render();
	private:
		unsigned int buffer;
	};

	template<typename T>
	class Mesh{
		vector<T> verticies;
		vector<int> indicies;

		Mesh();
		void Render();
	private:
		unsigned int buffer;
	};

}