#pragma once
// 2008-06 native RBX::ViewNew::MeshFactory<Mesh, numMeshes> (inactive): the empty second base of the cached meshes.
//   RTTI     .?AV?$MeshFactory@VSphereMesh@ViewNew@RBX@@$00@ViewNew@RBX@@ (and WedgeMesh / TorsoMesh / HeadMesh /
//            CylinderAlongXMesh with $00 = 1, PBBMesh with $03 = 4) is the last base class descriptor of each mesh,
//            mdisp 0x89, no fields (the meshes are 0x8c: the factories push 0x8c before their constructors).
//   Static caches: only declared here (no instance fields). The nested types are proven by the RTTI of the cache
//   tables, e.g. 00826b84 .?AV?$Table@VRenderSurfaceTypes@ViewNew@RBX@@V?$Table@VVector3@G3D@@UVariations@?$MeshFactory@
//   VPBBMesh@ViewNew@RBX@@$03@ViewNew@RBX@@@G3D@@@G3D@@. Their definitions and the create / flush bodies are in
//   native-headers/ViewNewPartMesh2008/MeshFactoryCache2008.h (included by native-classes/ViewNewPartMesh2008.cpp).
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
