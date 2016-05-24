#include <Layers/TileLayer.h>

namespace graphics
{
	TileLayer::TileLayer(Shader* shader):
		 Layer(new Render(), shader, appm::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f))
	{
		m_Shader->enable();
		m_Shader->setUniform("pr_matrix", m_Projection);
		m_Shader->disable();
	}

	TileLayer::~TileLayer()
	{}
}