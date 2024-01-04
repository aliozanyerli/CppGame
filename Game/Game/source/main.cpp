#include <Engine.h>
using namespace Graphics;

Window window = Window(860, 640, "Demo Scene");
Triangle triangle = Triangle();
Shader shader = Shader("Engine/Shaders/Basic.shader");

void update(){
    triangle.Render();
}


int main(){
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}