/*************************************************************************
* Game Class
*
* Class to handle all Game specific functionality, serves as an 
* overarching wrapper for the Game program. 
*
*************************************************************************/
#ifndef GAME_H_
#define GAME_H_

#include <GL/glew.h>
#include <GL/glfw3.h>
#include <iostream>
#include <GameConfig/config.h>
#include <GameConfig/Window.h>
#include <appm/appm.h>
#include <utils/Shader.h>

#include <buffers/buffer.h>
#include <buffers/indexbuffer.h>
#include <buffers/vertexarray.h>

#include <Renders/renderable2D.h>
#include <Renders/simple2Drenderer.h>


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

