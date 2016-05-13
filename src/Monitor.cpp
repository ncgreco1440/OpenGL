#include <GameConfig/Monitor.h>
#include <GameConfig/config.h>

void Monitor::initMonitor()
{
	_glfwMonitor = glfwGetPrimaryMonitor();
	if (_glfwMonitor == 0)
	{
		glfwTerminate();
		gcnfg::fatal_error(-1, "A Primary Monitor was not detected, Program Terminated with exit code -1");
	}
	_name = glfwGetMonitorName(_glfwMonitor);
	_videoMode = glfwGetVideoMode(_glfwMonitor);
	_res_width = _videoMode->width;
	_res_height = _videoMode->height;
	_gammaRamp = glfwGetGammaRamp(_glfwMonitor);
	glfwGetMonitorPhysicalSize(_glfwMonitor, &_phys_width, &_phys_height);
	_dpi = _videoMode->width / (_phys_width / 25.4);
}

void Monitor::printMonitorStats() const
{
	std::cout << "============\tPrimary Monitor\t============" << std::endl;
	std::cout << "*** Name: " << _name << std::endl;
	std::cout << "*** Width: " << (_phys_width / 10) * 0.3937 << "\"" << std::endl;
	std::cout << "*** Height: " << (_phys_height / 10) * 0.397 << "\"" << std::endl;
	std::cout << "============\tVideo Mode\t============" << std::endl;
	std::cout << "*** Refresh Rate: " << _videoMode->refreshRate << "\n";
	std::cout << "*** Red Bits: " << _videoMode->redBits << "\n";
	std::cout << "*** Green Bits: " << _videoMode->greenBits << "\n";
	std::cout << "*** Blue Bits: " << _videoMode->blueBits << "\n";
	std::cout << "*** Height: " << _videoMode->height << "\n";
	std::cout << "*** Width: " << _videoMode->width << "\n";
	std::cout << "============================================" << std::endl;
	std::cout << "============\tGamma Ramp\t============" << std::endl;
	std::cout << "*** size: " << _gammaRamp->size << std::endl;
	std::cout << "*** red: " << _gammaRamp->red << std::endl;
	std::cout << "*** green: " << _gammaRamp->green << std::endl;
	std::cout << "*** blue: " << _gammaRamp->blue << std::endl;
	std::cout << "============================================" << std::endl;
}