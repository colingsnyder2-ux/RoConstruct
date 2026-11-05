// 2008-06 native RBX::RenderBase::RenderSceneBase (inactive). The base members are compiled in the optimized
// Render::RenderScene unit (document-swap flags, /O2), out of line: ctor 00504fd0, dtor 005039d0, ??_G 00503a30 and
// the presetLighting default 005039e0.
#include "RenderLib/RenderScene2008.h"
#include <exception>

namespace RBX
{
	namespace RenderBase
	{
		RenderSceneBase::RenderSceneBase()
			: colorClearValue(0.5f, 0.5f, 1.0f, 1.0f),
			  shadingQuality(-1.0f),
			  meshDetail(-1.0f)
		{
		}

		RenderSceneBase::~RenderSceneBase()
		{
		}

		void RenderSceneBase::presetLighting(G3D::ReferenceCountedPointer<G3D::Sky> sky, G3D::LightingParameters skyParameters,
		                                     G3D::Color3 ambientTop, G3D::Color3 ambientBottom)
		{
			throw std::exception("shouldn't be here");
		}
	}
}
