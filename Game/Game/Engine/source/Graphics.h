#pragma once

//opengl libraries
#include "pch.h"

#include "MyMath.h"
#include "MyTime.h"
#include "Shader.h"
#include "Buffers/VertexBuffer.h"
#include "Buffers/IndexBuffer.h"
#include "Buffers/VertexArray.h"

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


	class Quad{
	public:
		Vector2 verticies[4] = {Vector2(-0.5,-0.5), Vector2(0.5,-0.5), Vector2(0.5,0.5), Vector2(-0.5,0.5)};
		unsigned int indicies[6] = {0, 1, 2, 0, 2, 3};
		Vector2 position, scale;
		Shader shader = Shader("Engine/Assets/Shaders/Basic.shader");
		
		Quad();
		void Render();
	private:
		VertexBuffer vb = VertexBuffer(verticies, 4*sizeof(Vector2));
		IndexBuffer ib = IndexBuffer(indicies, 6);
		VertexArray va;
		VertexBufferLayout layout;
	};

}