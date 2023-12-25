#include <iostream>
#include "Engine.h"
using namespace std;
using namespace Graphics;
int main(){
	Window window = Window(860, 640, "Mincertaf");


    while (!window.ShouldClose())
    {
        window.Update([](){
                glBegin(GL_TRIANGLES);
                glVertex2f(-0.5, -0.5);
                glVertex2f(0, 0.5);
                glVertex2f(0.5, -0.5);
                glEnd();
            });
    }

	return 0;
}