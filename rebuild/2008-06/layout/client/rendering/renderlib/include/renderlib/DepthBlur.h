// =============================================================================
// DepthBlur.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/renderlib/include/renderlib/DepthBlur.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Rect2D.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Shader.h>
#include <GLG3D/Texture.h>

namespace RBX
{
	namespace Render
	{
		class DepthBlur
		{
		private:
			G3D::ReferenceCountedPointer<G3D::Shader> shader;
			G3D::ReferenceCountedPointer<G3D::Texture> depth;
			G3D::ReferenceCountedPointer<G3D::Texture> color;
		private:
			void allocateTextures(const G3D::Rect2D& screenRect);
		public:
			//DepthBlur(const DepthBlur&);
			DepthBlur();

			void apply(G3D::RenderDevice* rd);

			~DepthBlur();
			//DepthBlur& operator=(const DepthBlur&);
		};
	}
}
