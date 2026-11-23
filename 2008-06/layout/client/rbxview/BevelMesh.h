// =============================================================================
// BevelMesh.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/BevelMesh.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
