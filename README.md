# OpenGL Start-Up Application v. 1.1.0 (Non-Stable)
###Last Updated: (05/01/16)  

###Please check the Issues section for any problems

This is meant to be a simple start up project for those interested in quickly diving into an OpenGL
environment to create OpenGL rendered applications without the hassle of bloating your main().

This project is meant to be compatible with any OS.  
This has currently been tested to work properly with...
- Windows 10
- OS X El Capitan

**YOU ARE RESPONSIBLE FOR YOUR OWN EXTERNAL LIBRARIES**  
The reason for this is because many like to compile their own libraries that are then custom tailored to their processor. Also, because this is meant to be compatiable with a multitude of OSes I do not want to bloat the common/lib folder with .dll, .lib, .dylib, and .a files in which only a few get used. As such, I will provide the headers within common/include and anyone else can provide their own libraries within common/lib.  

The libraries REQUIRED are...  
- [GLFW](http://www.glfw.org/download.html)
- [GLEW](http://glew.sourceforge.net/)  
- [SOIL](http://www.lonesock.net/soil.html) (For a lighter solution, the less efficient [**picopng**](http://lodev.org/lodepng/picopng.cpp) is provided with it's header and implementation, no external library is needed)

This is still a work in progress. More to come...
