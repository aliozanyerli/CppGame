#include <Engine.h>
using namespace Graphics;

Window window = Window(860, 640, "Demo Scene");
Quad quad;
Shader shader = Shader("Engine/Shaders/Basic.shader");

void update(){
    quad.Render();
}


int main(){
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}