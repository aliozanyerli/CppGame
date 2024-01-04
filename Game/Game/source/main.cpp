#include <Engine.h>
using namespace Graphics;

Window window = Window(860, 640, "Mincertaf");
Triangle tri = Triangle(Vector2(0,0), Vector2(1,1));



void update(){
    tri.position.x = sin(Time.time)/2;
    tri.position.y = cos(Time.time)/2;
    tri.Render();
}



int main(){
    Timer timer("Main game");
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}