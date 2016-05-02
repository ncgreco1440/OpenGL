#include "Game.h"

Game::Game()
{
	cout << "Game Created!" << endl;
}


Game::~Game()
{
	cout << "Game Destroyed!" << endl;
}


void Game::run()
{
	cout << "Game is running" << endl;
	// Game Initialization
	while (!glfwWindowShouldClose(_window.getGLFWwindowHandle()))
		update();
	cout << "Game has exited as requested by the player" << endl;
}

void Game::update()
{
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glfwSwapBuffers(_window.getGLFWwindowHandle());
}

void Game::draw()
{
	// Draw...
}
