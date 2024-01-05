#include "Graphics.h"


namespace Graphics{
	/// Window
	Window::Window(int sizeX, int sizeY, const char title[]){
		wx = sizeX;
		wy = sizeY;
		this->title = (char*)title;

        if(!glfwInit()){
            cout << "Init error!\n";
            return;
        }
        window = glfwCreateWindow(wx, wy, this->title, NULL, NULL);
        if (!window){
            cout << "!window error\n";
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);
        if(glewInit() != GLEW_OK){
            cout << "glewInit() is not ok :(\n";
        }
        cout << glGetString(GL_VERSION) << endl;

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
        Time.calculateDelta();
        Time.updateTime();
        glClear(GL_COLOR_BUFFER_BIT);
        func();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    
    /// Triangle
    Triangle::Triangle(){
        /// Setting up data
        position = Vector2(0, 0);
        scale = Vector2(1, 1);

        /// OpenGl setup
        glCall(glGenBuffers(1, &buffer));
        glCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        glCall(glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), verticies, GL_STATIC_DRAW));
        
        glCall(glEnableVertexAttribArray(0));
        glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0));
    }
    void Triangle::Render(){
        glCall(glDrawArrays(GL_TRIANGLES, 0, 3));
    }



    /// Quad
    Quad::Quad(){
        /// Setting up data
        position = Vector2(0, 0);
        scale = Vector2(1, 1);

        /// OpenGl setup
        glCall(glGenBuffers(1, &buffer));
        glCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        glCall(glBufferData(GL_ARRAY_BUFFER, 4*2*sizeof(float), verticies, GL_STATIC_DRAW));
        
        glCall(glEnableVertexAttribArray(0));
        glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0));

        glCall(glGenBuffers(1, &ibo));
        glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
        glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(unsigned int), indicies, GL_STATIC_DRAW));
    }
    void Quad::Render(){
        glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
    }

}

