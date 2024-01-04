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
        {verticies[0] = Vector2(-0.5,-0.5);
        verticies[1] = Vector2(0,0.5);
        verticies[2] = Vector2(0.5,-0.5);
        position = Vector2(0, 0);
        scale = Vector2(1, 1);}

        /// OpenGl setup
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), verticies, GL_STATIC_DRAW);
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);
    }
    void Triangle::Render(){
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }



    /// Mesh
    template<typename T>
    Mesh<T>::Mesh(){
        /// OpenGl setup
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER, verticies.size()*sizeof(T), verticies, GL_STATIC_DRAW);
    }
    template<typename T>
    void Mesh<T>::Render(){
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    
}

