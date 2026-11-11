#pragma once
// >>> native-status (generated) -- do not edit >>>
// BevelMesh | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3feab9f0 | roc native-status --write
// 2008-06 native RBX::ViewNew::BevelMesh / BevelMesh::Builder (inactive).
//   BevelMesh  RTTI base of WedgeMesh 008270e8 and TorsoMesh 00827124 (-> RenderBase::Mesh -> ReferenceCountedObject,
//              all mdisp 0); no vtable of its own is referenced (never constructed as a complete object).
//   Builder    vtable 00827088 .?AVBuilder@BevelMesh@ViewNew@RBX@@ -> LevelBuilder (mdisp 0); slot 0 build 00501040,
//              slots 1..6 pure (_purecall). Base of WedgeBuilder 008270a8 and TorsoBuilder 00827100.
//              bevel +0x20 (float; build 00501040 tests 0 < [this+0x20]); sizeof 0x24 (implicit copy constructor
//              004f6e30 copies +0x04..+0x20 and stores 00827088).
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

				// The builder as its own vertex function (the builder-as-functor grid instances 004f6fa0 / 004f7390 /
				// 004fa190 pass a copy of it): inline, no out-of-line copy in the image (the strips 004f66d0.. compare
				// x and y with 0 and step them towards the centre by bevel).
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
