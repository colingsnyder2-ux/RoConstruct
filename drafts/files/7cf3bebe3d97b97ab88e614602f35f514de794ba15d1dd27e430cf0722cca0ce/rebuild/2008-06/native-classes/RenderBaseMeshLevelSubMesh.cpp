// native-flags: /Od /Ob0 /GS /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 native RBX::RenderBase::Mesh::Level::makeHWSubMesh 00549610 (inactive; 1083 bytes, /Od like the rest of the
// RenderBase library block 00547f60..0054c..., flags copied from RenderBaseMeshUpdate2008.cpp).
// Identity evidence: thiscall, ret 8, its only caller is RenderNew::RenderScene::render 007ab0a0 (call 007aba67 with
// ecx = the detail Level from Mesh::detailLevel 00548f80, arguments (engine, &AxisAlignedBox local)). The body reads
// Level::dirty +0x1c, primitive +0x18, indexArray +0xc and writes vertexStart +0x20 / dirty; the name comes from its
// own log string 0082cf70 "RBX makeHWSubMesh: should not be here" (Ogre::LogManager::logMessage, LML_NORMAL).
//   * QUADS (5): a local std::vector<unsigned int> (ctor 004293d0, resize 005163e0, [] 004c6ce0, size 00445290,
//     dtor 0067fb10) gets indexArray.size() / 4 * 6 entries, each quad (a, b, c, d) as (a, b, d, d, b, c).
//   * 0067c020 (the hardware index buffer helper, OgreGeometryIndices2008.cpp) is called with ecx = engine and
//     (&Mesh::sharedMesh 009738b8, NULL, indices, count / 3): a thiscall GeometryBuilder member.
//   * on success vertexStart = sharedMesh->getNumSubMeshes() - 1 and dirty = false.
//   * bounds: two float[3] (1e9f 0082d030 / -1e9f 0082d02c) over visibleGeometry.vertexArray (009738f0) through
//     indexArray, then AxisAlignedBox::setExtents.
// Measured IDENTICAL (1083 B, relocs masked) in batch 36 against a scratch header; batch 37 adds the member
//   SubMesh* createIndices(const MeshPtr&, const unsigned short*, const unsigned*, unsigned); // 0067c020
// to Ogre::GeometryBuilder (OgreRbx/GeometryCreate2008.h) and turns the 0067c020 body into that member, so the
// former NATIVE_GEOMETRY_CREATEINDICES_MEMBER_PENDING guard is gone.
// RBX::RenderBase::Mesh shadow sub-mesh 0054a920 (148 B, /Od, thiscall ret 4): see the comment at its body.
#include "ViewNew/RenderBaseMesh.h"
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreAxisAlignedBox.h>
#include <OgreLogManager.h>
#include <vector>

namespace RBX
{
	namespace RenderBase
	{
		// 00549610
		void Mesh::Level::makeHWSubMesh(Ogre::GeometryBuilder* builder, Ogre::AxisAlignedBox& bounds)
		{
			if (dirty)
			{
				std::vector<unsigned int> indices;
				Ogre::SubMesh* subMesh;
				if (primitive == G3D::RenderDevice::QUADS)
				{
					indices.resize(indexArray.size() / 4 * 6);
					for (int i = 0; i < indexArray.size(); i += 4)
					{
						int quad = i / 4;
						indices[quad * 6] = indexArray[quad * 4];
						indices[quad * 6 + 1] = indexArray[quad * 4 + 1];
						indices[quad * 6 + 2] = indexArray[quad * 4 + 3];
						indices[quad * 6 + 3] = indexArray[quad * 4 + 3];
						indices[quad * 6 + 4] = indexArray[quad * 4 + 1];
						indices[quad * 6 + 5] = indexArray[quad * 4 + 2];
					}
					subMesh = builder->createIndices(sharedMesh, NULL, &indices[0], indices.size() / 3);
				}
				else
				{
					subMesh = builder->createIndices(sharedMesh, NULL, &indexArray[0], indexArray.size() / 3);
				}
				if (subMesh)
				{
					vertexStart = sharedMesh->getNumSubMeshes() - 1;
					dirty = false;
				}
				float minimum[3] = {1e9f, 1e9f, 1e9f};
				float maximum[3] = {-1e9f, -1e9f, -1e9f};
				const float* vertices = &visibleGeometry.vertexArray[0][0];
				for (int i = 0; i < indexArray.size(); ++i)
				{
					int k = indexArray[i] * 3;
					if (minimum[0] > vertices[k]) minimum[0] = vertices[k];
					if (minimum[1] > vertices[k + 1]) minimum[1] = vertices[k + 1];
					if (minimum[2] > vertices[k + 2]) minimum[2] = vertices[k + 2];
					if (maximum[0] < vertices[k]) maximum[0] = vertices[k];
					if (maximum[1] < vertices[k + 1]) maximum[1] = vertices[k + 1];
					if (maximum[2] < vertices[k + 2]) maximum[2] = vertices[k + 2];
				}
				bounds.setExtents(minimum[0], minimum[1], minimum[2], maximum[0], maximum[1], maximum[2]);
			}
			else
				Ogre::LogManager::getSingleton().logMessage("RBX makeHWSubMesh: should not be here");
		}

		// 0054a920 (/Od, thiscall ret 4). Only caller RenderScene::render 007ab0a0 (call 007ab7fd, taken when the stencil
		// shadow setting is on and Mesh +0x80 is NULL). When both shadow vectors are non-empty (size() tests 004dc410 on
		// +0x68 and 004dc3f0 on +0x50) it builds the owned sub-mesh +0x80 through engine 0067c130
		// (GeometryBuilder::createIndexed, ret 0x28): vertices &shadowVertices[0][0] (0054c120, 0043d880), count
		// shadowVertices.size(), no normals / colours / texture coordinates, 16-bit indices &shadowIndices[0]
		// (00515ea0), no 32-bit indices, shadowIndices.size() / 3 triangles, and two local Ogre::Vector3 bounds
		// (ebp-0xc, ebp-0x18) that are not used afterwards. The 2007 analog is openrbx RenderLibNew Mesh::FUN_005324e0.
		// INFERRED: the method name (registry placeholder func_0054a920).
		void Mesh::makeShadowSubMesh(Ogre::GeometryBuilder* engine)
		{
			if (shadowVertices.size() && shadowIndices.size())
			{
				Ogre::Vector3 minimum;
				Ogre::Vector3 maximum;
				subMesh = engine->createIndexed(&shadowVertices[0][0], shadowVertices.size(), NULL, NULL, NULL,
				                                &shadowIndices[0], NULL, shadowIndices.size() / 3, &minimum, &maximum);
			}
		}
	}
}
