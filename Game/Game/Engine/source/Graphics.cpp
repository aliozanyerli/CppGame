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
        verticies[0] = Vector2(-0.5,-0.5);
        verticies[1] = Vector2(0,0.5);
        verticies[2] = Vector2(0.5,-0.5);
        position = Vector2(0, 0);
        scale = Vector2(1, 1);
    }
    Triangle::Triangle(Vector2 verticies[3],Vector2 position,Vector2 scale){
        this->verticies[0] = verticies[0];
        this->verticies[1] = verticies[1];
        this->verticies[2] = verticies[2];
        this->position = position;
        this->scale = scale;
    }
    Triangle::Triangle(Vector2 position, Vector2 scale){
        verticies[0] = Vector2(-0.5,-0.5);
        verticies[1] = Vector2(0,0.5);
        verticies[2] = Vector2(0.5,-0.5);
        this->position = position;
        this->scale = scale;
    }
    void Triangle::Render(){
        glBegin(GL_TRIANGLES);
        glVertex2f(position.x+verticies[0].x*scale.x, position.y+verticies[0].y*scale.y);
        glVertex2f(position.x+verticies[1].x*scale.x, position.y+verticies[1].y*scale.y);
        glVertex2f(position.x+verticies[2].x*scale.x, position.y+verticies[2].y*scale.y);
        glEnd();
    }
    
}

