#include <Engine.h>
using namespace Graphics;

Window window = Window(860, 640, "Demo Scene");
Quad quad;

void update(){
    quad.Render();
    cout << Time.deltaTime << "ms, " << 1/Time.deltaTime << "fps\n";
}

int main(){
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}