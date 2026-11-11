#pragma once
// >>> native-status (generated) -- do not edit >>>
// MeshFactoryCache2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src c57578ba | roc native-status --write
// 2008-06 native RBX::ViewNew::MeshFactory<Mesh, numMeshes> static caches (inactive): definitions of the nested types
// and static members declared in ViewNew/MeshFactory.h. One instance per mesh: PBBMesh (4), SphereMesh,
// CylinderAlongXMesh, TorsoMesh, HeadMesh, WedgeMesh (1 each).
//
//   Cache       0x60 bytes (initCache 004d9750.. pushes 0x60 before the out-of-line ctor 004d91f0..004d9560):
//     +0x00  G3D::Table<RenderSurfaceTypes, G3D::Table<Vector3, Variations> >: vptr 00826b84.. (RTTI names above),
//            numBuckets +0xc = 10, node: hashCode +0, key +4, inner table +8, next +0x18
//     +0x10  boost::recursive_mutex (ctor 00563070, do_lock 00563090, do_unlock 005630e0)
//     +0x1c  std::map<DecalKey, RCP>: _Tree ctor (less&, allocator&) ICF 004f0fc0, node 0x24 (_Isnil +0x21), the
//            key at node +0xc is 0x10 bytes (find 004e8690 compares +0x18 = face), mapped RCP at node +0x1c
//     +0x3c  std::map<TextureKey, RCP>: _Tree ctor 004d8680, _Buynode 004d7770 new 0x2c (_Isnil +0x29), key 0x18
//            (find 004e8720 compares +0x1c = studsPerTile, then +0x18 face), mapped RCP at node +0x24
//     +0x5c  count (int, zeroed last in the ctor; `++count % 100 == 0` releases unused meshes, create 004ee1c3)
//   The VS2008 std::map is 0x20 bytes (aux-container proxy +0, head +0x18, size +0x1c), which gives the 0x20 stride.
//   DecalKey    size Vector3 +0, face +0xc (createDecal 004edd50 builds it on the stack: size, then face).
//   TextureKey  DecalKey base, studsPerTile Vector2 +0x10 (createTexture 004edeb0).
//   Variations  RCP meshes[numMeshes] (eh vector ctor 4 x 4 bytes for PBBMesh in 004edb20; the inner table node
//               holds it at +0x10, next at +0x10 + 4 * numMeshes: 0x20 / 0x14).
//   Both key orderings compare the Vector3 / Vector2 through G3D's `operator const float*` conversion, i.e. by
//   address (cmp / setb on the two key addresses in 004e86de and 004e8768); that is what the bytes do.
//   Names: Variations, DecalKey / TextureKey and their member order follow the 2008 RTTI and the donor MeshFactory.h;
//   Cache, cache, cacheFlag, releaseUnused and the Cache member names are descriptive (the image has no symbols for
//   them). Codegen spellings the bytes require: every body binds `Cache& c = *cache` once after call_once (the
//   flushes and lookups address everything from one register); releaseUnused binds the inner table to a reference
//   (without it the N = 1 instances align the inner loop head); create computes the variation index into a local
//   before indexing (without it PBBMesh::create swaps ebx / ebp).
#include "ViewNew/MeshFactory.h"
#include "ViewNew/QuadVolume.h"
#include <G3D/Table.h>
#include <G3D/g3dmath.h>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <map>

// G3D::Table hashes with ::hashCode(key) and compares keys with ==. The key is the 32-bit surface word itself
// (the inline lookups in 004edb20 compare node->hashCode and node->key with the same register).
inline unsigned int hashCode(const RBX::ViewNew::RenderSurfaceTypes& surfaceTypes)
{
	return surfaceTypes.data;
}

namespace RBX
{
	namespace ViewNew
	{
		inline bool operator==(const RenderSurfaceTypes& a, const RenderSurfaceTypes& b)
		{
			return a.data == b.data;
		}

		template<class Mesh, size_t numMeshes>
		class MeshFactory<Mesh, numMeshes>::DecalKey
		{
		private:
			G3D::Vector3 size;          // +0x00
			NormalId face;              // +0x0c
		public:
			DecalKey(NormalId face, const G3D::Vector3& size)
				: size(size),
				  face(face)
			{
			}
			bool operator<(const DecalKey& other) const
			{
				if (face < other.face)
					return true;
				if (face > other.face)
					return false;
				return static_cast<const float*>(size) < static_cast<const float*>(other.size);
			}
		};

		template<class Mesh, size_t numMeshes>
		class MeshFactory<Mesh, numMeshes>::TextureKey : protected MeshFactory<Mesh, numMeshes>::DecalKey
		{
		private:
			G3D::Vector2 studsPerTile;  // +0x10
		public:
			TextureKey(NormalId face, const G3D::Vector3& size, const G3D::Vector2& studsPerTile)
				: DecalKey(face, size),
				  studsPerTile(studsPerTile)
			{
			}
			bool operator<(const TextureKey& other) const
			{
				if (static_cast<const float*>(studsPerTile) < static_cast<const float*>(other.studsPerTile))
					return true;
				if (static_cast<const float*>(studsPerTile) > static_cast<const float*>(other.studsPerTile))
					return false;
				return DecalKey::operator<(other);
			}
		};

		template<class Mesh, size_t numMeshes>
		struct MeshFactory<Mesh, numMeshes>::Variations
		{
			G3D::ReferenceCountedPointer<RenderBase::Mesh> meshes[numMeshes];
		};

		template<class Mesh, size_t numMeshes>
		struct MeshFactory<Mesh, numMeshes>::Cache
		{
			G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> > meshes;          // +0x00
			boost::recursive_mutex mutex;                                                        // +0x10
			std::map<DecalKey, G3D::ReferenceCountedPointer<RenderBase::Mesh> > decalCache;      // +0x1c
			std::map<TextureKey, G3D::ReferenceCountedPointer<RenderBase::Mesh> > textureCache;  // +0x3c
			int count;                                                                           // +0x5c

			Cache()                                                                              // 004d91f0..
				: count(0)
			{
			}
		};

		template<class Mesh, size_t numMeshes>
		typename MeshFactory<Mesh, numMeshes>::Cache* MeshFactory<Mesh, numMeshes>::cache;

		template<class Mesh, size_t numMeshes>
		boost::once_flag MeshFactory<Mesh, numMeshes>::cacheFlag = BOOST_ONCE_INIT;

		template<class Mesh, size_t numMeshes>
		void MeshFactory<Mesh, numMeshes>::initCache()
		{
			cache = new Cache();
		}

		template<class Mesh, size_t numMeshes>
		void MeshFactory<Mesh, numMeshes>::releaseUnused()
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			for (typename G3D::Table<RenderSurfaceTypes, G3D::Table<G3D::Vector3, Variations> >::Iterator i = c.meshes.begin(); i != c.meshes.end(); i++)
			{
				G3D::Table<G3D::Vector3, Variations>& sizes = i->value;
				for (typename G3D::Table<G3D::Vector3, Variations>::Iterator j = sizes.begin(); j != sizes.end(); j++)
				{
					for (int k = 0; k < numMeshes; ++k)
					{
						if (j->value.meshes[k].notNull() && j->value.meshes[k].isLastReference())
							j->value.meshes[k] = NULL;
					}
				}
			}
			for (typename std::map<DecalKey, G3D::ReferenceCountedPointer<RenderBase::Mesh> >::iterator i = c.decalCache.begin(); i != c.decalCache.end(); ++i)
			{
				if (i->second.notNull() && i->second.isLastReference())
					i->second = NULL;
			}
			for (typename std::map<TextureKey, G3D::ReferenceCountedPointer<RenderBase::Mesh> >::iterator i = c.textureCache.begin(); i != c.textureCache.end(); ++i)
			{
				if (i->second.notNull() && i->second.isLastReference())
					i->second = NULL;
			}
		}

		template<class Mesh, size_t numMeshes>
		Mesh* MeshFactory<Mesh, numMeshes>::create(const G3D::Vector3& size, RenderSurfaceTypes surfaceTypes)
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			if (!c.meshes.containsKey(surfaceTypes))
				c.meshes.set(surfaceTypes, G3D::Table<G3D::Vector3, Variations>());
			G3D::Table<G3D::Vector3, Variations>& sizes = c.meshes[surfaceTypes];
			if (!sizes.containsKey(size))
				sizes.set(size, Variations());
			Variations& variations = sizes[size];
			int index = numMeshes > 1 ? G3D::iRandom(0, numMeshes - 1) : 0;   // PBBMesh: iRandom 00515780 (0, 3)
			G3D::ReferenceCountedPointer<RenderBase::Mesh>& mesh = variations.meshes[index];
			Mesh* result = static_cast<Mesh*>(mesh.pointer());
			if (result == NULL)
			{
				result = new Mesh(size, surfaceTypes);
				mesh = result;
				if (++c.count % 100 == 0)
				{
					G3D::ReferenceCountedPointer<RenderBase::Mesh> keep(mesh);
					releaseUnused();
				}
			}
			return result;
		}

		template<class Mesh, size_t numMeshes>
		Mesh* MeshFactory<Mesh, numMeshes>::createDecal(const G3D::Vector3& size, NormalId face)
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			DecalKey key(face, size);
			typename std::map<DecalKey, G3D::ReferenceCountedPointer<RenderBase::Mesh> >::iterator it = c.decalCache.find(key);
			if (it == c.decalCache.end())
			{
				Mesh* mesh = new Mesh(size, face);
				c.decalCache[key] = mesh;
				return mesh;
			}
			return static_cast<Mesh*>(it->second.pointer());
		}

		template<class Mesh, size_t numMeshes>
		Mesh* MeshFactory<Mesh, numMeshes>::createTexture(const G3D::Vector3& size, NormalId face, const G3D::Vector2& studsPerTile)
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			TextureKey key(face, size, studsPerTile);
			typename std::map<TextureKey, G3D::ReferenceCountedPointer<RenderBase::Mesh> >::iterator it = c.textureCache.find(key);
			if (it == c.textureCache.end())
			{
				Mesh* mesh = new Mesh(size, face, studsPerTile);
				c.textureCache[key] = mesh;
				return mesh;
			}
			return static_cast<Mesh*>(it->second.pointer());
		}

		template<class Mesh, size_t numMeshes>
		void MeshFactory<Mesh, numMeshes>::flushCache()
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			c.meshes.clear();
			c.decalCache.clear();
			c.textureCache.clear();
		}
	}
}
