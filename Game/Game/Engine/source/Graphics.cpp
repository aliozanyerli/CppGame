#include "Graphics.h"


//c++ libraries
#include <iostream>

//my libraries



namespace Graphics{
	Window::Window(int sizeX, int sizeY, const char title[]){
		wx = sizeX;
		wy = sizeY;
		this->title = (char*)title;

        
        if(!glfwInit()){
            cout << "Init error!\n";
            return;
        }

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(wx, wy, this->title, NULL, NULL);
        if (!window)
        {
            cout << "!window error\n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(window);


		cout << "Created a window with title: " << '"' << this->title << '"' << " !\n";
	}

	Window::~Window(){
        glfwTerminate();
		cout << "Successfully destroyed " << '"' << title << '"' << " !\n";
	}
    bool Window::ShouldClose(){
        return glfwWindowShouldClose(window);
    }

    void Window::Update(void(*func)()){
        glClear(GL_COLOR_BUFFER_BIT);
        func();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

