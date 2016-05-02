/*************************************************************************
* Game Class
*
* Class to handle all Game specific functionality, serves as an 
* overarching wrapper for the Game program. 
*
*************************************************************************/
#ifndef GAME_H_
#define GAME_H_

#define GLFW_DLL
#include <GL\glew.h>
#include <GL\glfw3.h>
#include <iostream>
#include <GameConfig/config.h>
#include <Window.h>

using std::cout;
using std::endl;

class Game
{
public:
// Constructor and Destructor
	Game();
	~Game();
// Public Interface
	void run();
	Window& getWindow() { return _window; };
private:
// Private (Internal) Interface
	void update();
	void draw();
// Private Data Members
	Window	_window;
	float _time;
};

#endif

