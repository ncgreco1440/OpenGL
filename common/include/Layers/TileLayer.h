#ifndef TILE_LAYER_H_
#define TILE_LAYER_H_

#include <Layers/Layer.h>
#include <Render/Render.h>
#include <Renders/renderable2D.h>
#include <Renders/renderer2D.h>
#include <utils/Shader.h>
#include <appm/appm.h>

namespace graphics
{

	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};
}

#endif
