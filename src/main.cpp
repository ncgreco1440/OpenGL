#define OPENGL_STATIC_IBS

#ifdef OPENGL_STATIC_LIBS
#define GLEW_STATIC
#else
#define GLFW_DLL
#endif

#include <Game.h>

int main()
{
	Game game;
	game.run();
    return 0;
}