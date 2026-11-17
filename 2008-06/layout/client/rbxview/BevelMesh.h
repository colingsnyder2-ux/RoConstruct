#pragma once
#include "ViewNew/QuadVolume.h"

namespace RBX
{
	namespace ViewNew
	{
		class BevelMesh : public RenderBase::Mesh
		{
		public:
			class Builder : public LevelBuilder
			{
				friend struct ::NativeViewNewLayout;
			protected:
				const float bevel;                   // +0x20
			protected:
				Builder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes, float bevel)
					: LevelBuilder(level, size, surfaceTypes),
					  bevel(bevel)
				{
				}
			public:
				virtual void build(Purpose purpose); // 00501040

				void operator()(G3D::Vector3& vertex, G3D::Vector3&, G3D::Vector2&, const G3D::Vector3&, const G3D::Vector2int16&)
				{
					if (vertex.x > 0)
						vertex.x -= bevel;
					else
						vertex.x += bevel;
					if (vertex.y > 0)
						vertex.y -= bevel;
					else
						vertex.y += bevel;
				}
			};
		};
	}
}
