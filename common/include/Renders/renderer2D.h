#ifndef RENDERER_2D_H_
#define RENDERER_2D_H_

#include <GL/glew.h>
#include <Renders/renderable2D.h>
#include <appm/appm.h>
#include <vector>

class Renderer2D
{
protected:
	std::vector<appm::mat4> m_Transformation_Stack;
	const appm::mat4* m_Transformation_Back;
protected:
	Renderer2D()
	{
		m_Transformation_Stack.push_back(appm::mat4::identity());
		m_Transformation_Back = &m_Transformation_Stack.back();
	}
public:
	void push(const appm::mat4& matrix, bool or = false)
	{
		if (or)
			m_Transformation_Stack.push_back(matrix);
		else
			m_Transformation_Stack.push_back(m_Transformation_Stack.back() * matrix);
		m_Transformation_Back = &m_Transformation_Stack.back();
	}

	void pop()
	{
		if(m_Transformation_Stack.size() > 1)
			m_Transformation_Stack.pop_back();
		m_Transformation_Back = &m_Transformation_Stack.back();
		//TODO: add log
	}

    virtual ~Renderer2D() {};
	virtual void begin() {}
	virtual void end() {}
    virtual void submit(const Renderable2D* renderable) = 0;
    virtual void flush() = 0;
};

#endif