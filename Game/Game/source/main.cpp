#include <Engine.h>
using namespace Graphics;

Window window = Window(860, 640, "Mincertaf");
Triangle tri = Triangle(Vector2(0,0), Vector2(1,1.5));

double time;
void update(){
    tri.position.x = sin(time)/2;
    tri.Render();
    time += 0.01;
}

int main(){
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}