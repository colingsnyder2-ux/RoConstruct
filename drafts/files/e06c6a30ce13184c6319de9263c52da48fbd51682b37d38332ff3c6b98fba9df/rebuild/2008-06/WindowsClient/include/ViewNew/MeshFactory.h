#pragma once
// 2008-06 native RBX::ViewNew::MeshFactory<Mesh, numMeshes> (inactive): the empty second base of the cached meshes.
//   RTTI     .?AV?$MeshFactory@VSphereMesh@ViewNew@RBX@@$00@ViewNew@RBX@@ (and WedgeMesh / TorsoMesh / HeadMesh /
//            CylinderAlongXMesh with $00 = 1, PBBMesh with $03 = 4) is the last base class descriptor of each mesh,
//            mdisp 0x89, no fields (the meshes stay 0x88 bytes).
//   The factory's static caches and create functions live in other units and are not declared here.
#include <cstddef>
#include <boost/thread/once.hpp>

namespace RBX
{
	namespace ViewNew
	{
		template<class Mesh, size_t numMeshes>
		class MeshFactory
		{
		public:
			// Nested types defined out of line by the cache recovery unit
			// (native-headers/ViewNewPartMesh2008/MeshFactoryCache2008.h): DecalKey (Vector3 + face),
			// TextureKey (DecalKey + Vector2), Variations (RCP meshes[numMeshes]) and Cache
			// (G3D::Table + recursive_mutex + two std::maps + count, 0x60 bytes, ctor 004d91f0..).
			// Declarations only - the definitions stay in the recovery header.
			class DecalKey;
			class TextureKey;
			struct Variations;
			struct Cache;

		protected:
			static Cache* cache;                                        // 004d9750 initCache news 0x60
			static boost::once_flag cacheFlag;                          // BOOST_ONCE_INIT
			static void initCache();
		public:
			static void releaseUnused();                                // 004daf50..
			static Mesh* create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes);           // 004ec220..
			static Mesh* createDecal(const G3D::Vector3& size, NormalId face);                        // 004edd50..
			static Mesh* createTexture(const G3D::Vector3& size, NormalId face, const G3D::Vector2& studsPerTile);  // 004edeb0..
			static void flushCache();                                   // 004db400..
		};
	}
}
