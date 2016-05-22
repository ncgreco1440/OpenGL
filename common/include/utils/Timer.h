#ifndef TIMER_H_
#define TIMER_H_

#define __WINDOWS_PLATFORM__ 0

#if __WINDOWS_PLATFORM__
#include <Windows.h>
#else
#include <GL/glew.h>
#include <GL/glfw3.h>
#endif
#include <iostream>

namespace utils
{
	class Timer
	{
	private:
		//LARGE_INTEGER m_start;
		//double m_frequency;
		//double m_time;
		double m_prev_time;
		unsigned int m_framecount;
		//char m_draw_calls;
		double m_last_fps_update;
		double m_fps;
	public:
		Timer():m_prev_time(glfwGetTime()), m_last_fps_update(0), m_fps(0.0), m_framecount(0)
		{
			/*LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_start);*/
		}

		void reset()
		{
			//QueryPerformanceCounter(&m_start);
		}

		void operator()()
		{
			double now = glfwGetTime();
			double frame_time = now - m_prev_time;
			m_prev_time = now;
			m_last_fps_update += frame_time;
			if (m_last_fps_update >= 1.0f)
			{
				std::cout << m_framecount << " fps" << std::endl;
				//std::cout << frame_time << std::endl;
				m_framecount = 0;
				m_last_fps_update = 0.0;
			}
			m_framecount++;
		}

		double frametime()
		{
			double now = glfwGetTime();
			double frame_time = now - m_prev_time;
			return frame_time;
		}

		double elapsed()
		{
			return glfwGetTime();
		}
	};
}

#endif
