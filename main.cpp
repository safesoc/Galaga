#include <iostream>
#include "SDL_Plotter.h"

using namespace std;

void drawShip(int x, int y, SDL_Plotter& g, int R, int G, int B);

const int SHIP_WIDTH = 30;
const int SHIP_HEIGHT = 30;
const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 750;
const int SPEED = 7;

int main(int argc, char ** argv)
{

    SDL_Plotter g(SCREEN_WIDTH,SCREEN_HEIGHT);
    int x = SCREEN_WIDTH/2, y = SCREEN_HEIGHT - 2*SHIP_HEIGHT;
    char key;

    while (!g.getQuit())
    {

		if(g.kbhit()){
			key = g.getKey();
			switch (key){
                case RIGHT_ARROW: drawShip(x, y, g, 255, 255, 255);
                                    if (x + SPEED < SCREEN_WIDTH - SHIP_WIDTH)
                                        x += SPEED;
                                    break;
                case LEFT_ARROW: drawShip(x, y, g, 255, 255, 255);
                                    if (x - SPEED - SHIP_WIDTH > 0)
                                        x -= SPEED;
                                    break;
			}
		}

		drawShip(x, y, g, 220, 20, 20);

		g.update();
    }
}

void drawShip(int cx, int cy, SDL_Plotter& g, int R, int G, int B)
{
    //draw top
    for(int y = cy - SHIP_HEIGHT/2; y < cy - SHIP_HEIGHT/6; y++){
        for(int x = cx - SHIP_WIDTH/6; x < cx + SHIP_WIDTH/6; x++){
            g.plotPixel(x,y,R,G,B);
        }
    }

    //draw bottom
    for(int y = cy - SHIP_HEIGHT/6; y < cy + SHIP_HEIGHT/3; y++){
        for(int x = cx - SHIP_WIDTH/2; x < cx + SHIP_WIDTH/2; x++){
            g.plotPixel(x,y,R,G,B);
        }
    }
}
