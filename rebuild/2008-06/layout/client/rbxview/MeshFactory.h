// =============================================================================
// MeshFactory.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rbxview/MeshFactory.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <cstddef>
#include <boost/thread/once.hpp>
#include "util/NormalId.h"

namespace G3D
{
	class Vector2;
	class Vector3;
}

namespace RBX
{
	namespace ViewNew
	{
		class RenderSurfaceTypes;

		template<class Mesh, size_t numMeshes>
		class MeshFactory
		{
		public:
			class DecalKey;
			class TextureKey;
			struct Variations;
			struct Cache;
		private:
			static Cache* cache;
			static boost::once_flag cacheFlag;
			static void initCache();
			static void releaseUnused();
		public:
			static Mesh* create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);
			static Mesh* createDecal(const G3D::Vector3& size, NormalId face);
			static Mesh* createTexture(const G3D::Vector3& size, NormalId face, const G3D::Vector2& studsPerTile);
			static void flushCache();
		};
	}
}
