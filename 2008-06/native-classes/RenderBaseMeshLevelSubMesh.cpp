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
// Measured IDENTICAL (1083 B, relocs masked) with the body below when Ogre::GeometryBuilder declares
//   SubMesh* createIndices(const MeshPtr&, const unsigned short*, const unsigned*, unsigned); // 0067c020
// BLOCKED (pending guard): OgreRbx/GeometryCreate2008.h (not owned by this batch) has no such member; the existing
// 0067c020 body is a free __stdcall Ogre::createIndices (OgreGeometryIndices2008.cpp), whose callee bytes are the
// same (ecx unused) but whose symbol is not the one this caller references. Header proposal in the batch result.
#include "ViewNew/RenderBaseMesh.h"
#include "OgreRbx/GeometryCreate2008.h"
#include <OgreAxisAlignedBox.h>
#include <OgreLogManager.h>
#include <vector>

#ifdef NATIVE_GEOMETRY_CREATEINDICES_MEMBER_PENDING
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
	}
}
#endif // NATIVE_GEOMETRY_CREATEINDICES_MEMBER_PENDING
