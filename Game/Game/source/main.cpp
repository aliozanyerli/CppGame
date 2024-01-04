#include <Engine.h>
using namespace Graphics;

Window window = Window(860, 640, "Mincertaf");
Triangle triangle = Triangle();

string vs = R"glsl(
#version 330 core

layout(location = 0) in vec4 position;

void main(){
   gl_Position = position;
}
)glsl";
string fs = R"glsl(
#version 330 core

layout(location = 0) out vec4 color;

void main(){
   color = vec4(1.0, 0.0, 0.0, 1.0);
}
)glsl";
Shader shader = Shader(vs, fs);


void update(){
    triangle.Render();
}



int main(){
    Timer timer("Main game");
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}