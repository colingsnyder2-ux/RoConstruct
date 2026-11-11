#pragma once
// >>> native-status (generated) -- do not edit >>>
// BrickMeshCache2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 5045044a | roc native-status --write
// 2008-06 native RBX::ViewNew::BrickMesh static cache and shadow box helper (inactive). A new path
// (ViewNewBrickBuild2008/) that shadows no donor header; included only by native-classes/ViewNewBrickMeshBuild2008.cpp.
//
//   BrickMesh::Cache  0x30 bytes (initCache 004e5360 pushes 0x30 before the out-of-line ctor 004e5300):
//     +0x00  std::map<Lookup, Variations>: _Tree(const less&, const allocator&) ICF 00671ae0 (ret 8), head +0x18,
//            size +0x1c (flushCache 004e5670 empties it inline through _Erase 004dd430); node 0x38: key +0xc,
//            Variations +0x20 (meshes +0x24), _Isnil +0x35 (_Erase 004dd430, lower_bound 004dc590)
//     +0x20  boost::recursive_mutex (ctor 00563070, do_lock 00563090, do_unlock 005630e0)
//     +0x2c  count (int, zeroed last in the ctor; create 004e58b0: `++count % 100 == 0` -> releaseUnused 004e5710)
//   Lookup      0x14: size Vector3 +0, surfaceTypes +0xc (compared unsigned), color +0x10 (BrickColor::Number,
//               compared signed); lower_bound 004dc590 / operator[] 004ddf80 compare in that order, the size through
//               the x / y / z ordered comparison 004dc360. Names and member order follow the donor BrickMesh.h.
//   Variations  0x14: count +0 (zeroed by the default ctor in operator[] 004ddf80 before the 4 x 4 eh vector ctor),
//               meshes[4] +4 (RCP default ctor 004f0810 / dtor 00502a70; releaseUnused walks node +0x24, 4 times).
//   buildShadowBox  004e3570 (cdecl; called by the BrickMesh ctor 004e53c0 and the PBBMesh surface ctor 004f4cb0 with
//               halfSize, Mesh::shadowVertices +0x68 and Mesh::shadowIndices +0x50): reserve(8) / reserve(36), the 8
//               corners, then six quads through the unit-local appendQuad 004de1d0 (two triangles a b c / a c d).
//               The name is descriptive (no symbol).
#include "ViewNew/BrickMesh.h"
#include "ViewNew/QuadVolume.h"
#include "v8datamodel/BrickColor.h"
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/once.hpp>
#include <map>
#include <vector>

struct Lookup
{
	G3D::Vector3 size;                                // +0x00
	RBX::ViewNew::RenderSurfaceTypes surfaceTypes;    // +0x0c
	RBX::BrickColor color;                            // +0x10

	bool operator<(const Lookup& other) const;
};

struct Variations
{
	int count;                                                       // +0x00
	G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh> meshes[4];   // +0x04

	Variations()
		: count(0)
	{
	}
};

namespace RBX
{
	namespace ViewNew
	{
		struct BrickMesh::Cache
		{
			std::map<Lookup, Variations> meshes;   // +0x00
			boost::recursive_mutex mutex;          // +0x20
			int count;                             // +0x2c

			Cache()                                // 004e5300
				: count(0)
			{
			}
		};

		void buildShadowBox(const G3D::Vector3& halfSize, std::vector<G3D::Vector3>& vertices, std::vector<unsigned short>& indices); // 004e3570
	}
}
