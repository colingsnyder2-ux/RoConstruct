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
