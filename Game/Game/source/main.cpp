#include <Engine.h>
using namespace std;
using namespace Graphics;

Window window = Window(860, 640, "Demo Scene");
Quad quad;

void update(){
    quad.Render();
    cout << Time.deltaTime*1000 << "ms, " << 1/Time.deltaTime << "fps\n";
}

int main(){
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}