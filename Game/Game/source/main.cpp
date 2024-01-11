#include <Engine.h>
using namespace std;
using namespace Graphics;

Window window = Window(860, 640, "Demo Scene");
Quad quad;
Vector4 color;

void update(){
    color = {(float)pow(sin(Time.time),2), 0, (float)pow(cos(Time.time),2), 1};
    cout << color.x << endl;
    quad.shader.SetUniform4f("u_Color", color);
    quad.Render();
    //cout << Time.deltaTime*1000 << "ms, " << 1/Time.deltaTime << "fps\n";
}

int main(){
    while (!window.ShouldClose()){
        window.Update(update);
    }
	return 0;
}