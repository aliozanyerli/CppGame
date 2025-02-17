#include "Graphics.h"



namespace Graphics{
	/// Window
	Window::Window(int sizeX, int sizeY, const char title[]){
		wx = sizeX;
		wy = sizeY;
		this->title = (char*)title;

        if(!glfwInit()){
            std::cout << "Init error!\n";
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(wx, wy, this->title, NULL, NULL);
        if (!window){
            std::cout << "!window error\n";
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);
        if(glewInit() != GLEW_OK){
            std::cout << "glewInit() is not ok :(\n";
        }
        std::cout << glGetString(GL_VERSION) << '\n';

		std::cout << "Created a window with title: " << '"' << this->title << '"' << " !\n";
	}
	Window::~Window(){
        glfwTerminate();
		std::cout << "Successfully destroyed " << '"' << title << '"' << " !\n";
	}
    bool Window::ShouldClose(){
        return glfwWindowShouldClose(window);
    }
    void Window::Update(void(*func)()){
        Time.calculateDelta();
        Time.updateTime();
        glClear(GL_COLOR_BUFFER_BIT);
        func();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    /// Quad
    Quad::Quad(){
        /// Setting up data
        position = {0,0};
        scale = {1,1};

        /// OpenGl setup
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);
        ib.Bind();
    }
    void Quad::Render(){
        shader.Bind();
        va.Bind();
        glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
    }

}

