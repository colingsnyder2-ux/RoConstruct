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
// RBX::RenderBase::Mesh::Level::makeSWSubMesh 00549a50 (3779 B, /Od, thiscall ret 8): see the comment at its body.
#include "ViewNew/RenderBaseMesh.h"
#include "OgreRbx/GeometryCreate2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include <OgreAxisAlignedBox.h>
#include <OgreLogManager.h>
#include <vector>
#include <map>
#include <stdio.h>

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
		// (00515ea0), no 32-bit indices, shadowIndices.size() / 3 triangles, and two local bounds (minimum ebp-0xc,
		// maximum ebp-0x18) that are not used afterwards. The 2007 analog is openrbx RenderLibNew Mesh::FUN_005324e0.
		// INFERRED: the method name (registry placeholder func_0054a920). INFERRED: the bounds are float[3] like
		// makeHWSubMesh's: the /Od target constructs nothing for them and the exe imports no Ogre::Vector3 default
		// constructor (an Ogre::Vector3 local calls the import twice; forceinline on OgreVector3.h does not remove it
		// at /Ob0); the casts only adapt them to the INFERRED Vector3* parameters of createIndexed.
		// Batch 37: byte-identical to 0054a920 (148 B, relocs masked); uncredited while the registry name is a placeholder.
		void Mesh::makeShadowSubMesh(Ogre::GeometryBuilder* engine)
		{
			if (shadowVertices.size() && shadowIndices.size())
			{
				float maximum[3];
				float minimum[3];
				subMesh = engine->createIndexed(&shadowVertices[0][0], shadowVertices.size(), NULL, NULL, NULL,
				                                &shadowIndices[0], NULL, shadowIndices.size() / 3,
				                                reinterpret_cast<Ogre::Vector3*>(minimum), reinterpret_cast<Ogre::Vector3*>(maximum));
			}
		}

		// INFERRED name (the 2007 analog g_unk0x00958798): the sub-mesh name counter 00973998 read by makeSWSubMesh.
		static int subMeshNameCounter = 0;

		// 00549a50 (/Od, thiscall ret 8). Only caller RenderNew::RenderScene::render 007ab0a0 (call 007ab9c7, ecx = the
		// detail Level, arguments (engine, &AxisAlignedBox local)), taken when VisualEngine +0x7f5 is false (007ab2ea).
		// The software counterpart of makeHWSubMesh; 2007 analog openrbx RenderLibNew Mesh::Level::FUN_00533160, whose
		// receiver is Ogre::VisualEngine. Evidence for the 2008 receiver: the same pointer ([ebp+8]) is the ecx of the
		// /Od accessor 0054acf0 (mov al, [ecx+0x7f4]: VisualEngine::useLargeVertexBuffer, OgreRbx/VisualEngine2008.h)
		// at 00549c3e / 0054a747 / 0054a789 / 0054a7b4 and of 0067c130 (createIndexed, ret 0x28) at 0054a837.
		//   * sprintf(char[8], "m%d" 0082cf98, counter 00973998++); the name is not used afterwards.
		//   * map<unsigned, unsigned> (ctor 00540a80, find 0054c3f0, end 005409b0, [] 0054c2d0, size 0054e3a0, dtor
		//     0054ad10) numbers the distinct indices in order of first use; vector<unsigned> unique(size) (0054c150).
		//   * 32-bit (vector<unsigned> 004293d0 / resize 005163e0) or 16-bit (vector<unsigned short> 0054b2a0 / resize
		//     005163f0 / [] 00515ea0 / dtor 0054b310) indices, QUADS (5) as (a, b, d, d, b, c) or TRIANGLES (2).
		//   * positions (verts) / normals (vector<float>, size * 3) from visibleGeometry 009738f0 / 009738fc, texture
		//     coordinates (size * 2) from texCoordArray 00973934.
		//   * the result of createIndexed goes to subMesh +0x24; bounds through AxisAlignedBox::setMinimum / setMaximum;
		//     dirty = false.
		// INFERRED: the method name (registry placeholder func_00549a50); the bounds are float[3] (no Vector3 ctor call,
		// as in makeShadowSubMesh). INFERRED local names: VC9 /Od orders function-scope locals by a hash of their names
		// (later declaration first within a bucket; measured with int-only probe units), so the names and declaration
		// order were chosen to reproduce the original frame (ref -0x10, min -0x1c, map -0x3c, verts -0x54, cookie -0x58,
		// name -0x60, inds32 -0x78, k -0x7c, texCoords -0x94, unique -0xac, ind16 -0xc4, c -0xc8, max -0xd4, normals
		// -0xec); vmap / verts / c / ind16 / min / max follow the earlier archived draft of this body. The createIndexed call goes through Ogre::GeometryBuilder, the receiver name the
		// committed 0067c130 body (OgreGeometryIndexed2008.cpp) and its inferred identity use; the object really is the
		// VisualEngine (see the proposal to merge GeometryBuilder into VisualEngine), so the cast changes no code.
		void Mesh::Level::makeSWSubMesh(Ogre::VisualEngine* engine, Ogre::AxisAlignedBox& bounds)
		{
			float min[3];
			char name[8];
			sprintf(name, "m%d", subMeshNameCounter++);
			G3D::Array<unsigned int>& vertexIndices = indexArray;
			std::vector<unsigned int> inds32;
			std::vector<unsigned short> ind16;
			std::vector<float> verts;
			std::vector<float> normals;
			float max[3];
			std::vector<float> texCoords;
			int k;
			std::map<unsigned int, unsigned int> vmap;
			unsigned int c = 0;
			for (int i = 0; i < vertexIndices.size(); ++i)
			{
				if (vmap.find(vertexIndices[i]) == vmap.end())
				{
					vmap[vertexIndices[i]] = c;
					++c;
				}
			}
			std::vector<unsigned int> unique(vmap.size());
			for (int i = 0; i < vertexIndices.size(); ++i)
				unique[vmap[vertexIndices[i]]] = vertexIndices[i];

			if (engine->getUseLargeVertexBuffer())
			{
				if (primitive == G3D::RenderDevice::QUADS)
				{
					inds32.resize(vertexIndices.size() / 4 * 6);
					for (k = 0; k < vertexIndices.size(); k += 4)
					{
						int quad = k / 4;
						inds32[quad * 6] = vmap[vertexIndices[quad * 4]];
						inds32[quad * 6 + 1] = vmap[vertexIndices[quad * 4 + 1]];
						inds32[quad * 6 + 2] = vmap[vertexIndices[quad * 4 + 3]];
						inds32[quad * 6 + 3] = vmap[vertexIndices[quad * 4 + 3]];
						inds32[quad * 6 + 4] = vmap[vertexIndices[quad * 4 + 1]];
						inds32[quad * 6 + 5] = vmap[vertexIndices[quad * 4 + 2]];
					}
					verts.resize(unique.size() * 3);
					normals.resize(unique.size() * 3);
					texCoords.resize(unique.size() * 2);
					for (k = 0; k < (int)unique.size(); ++k)
					{
						int j;
						for (j = 0; j < 3; ++j)
						{
							verts[k * 3 + j] = visibleGeometry.vertexArray[unique[k]][j];
							normals[k * 3 + j] = visibleGeometry.normalArray[unique[k]][j];
						}
						for (j = 0; j < 2; ++j)
							texCoords[k * 2 + j] = texCoordArray[unique[k]][j];
					}
				}
				else if (primitive == G3D::RenderDevice::TRIANGLES)
				{
					inds32.resize(vertexIndices.size());
					for (k = 0; k < vertexIndices.size(); ++k)
						inds32[k] = vmap[vertexIndices[k]];
					verts.resize(unique.size() * 3);
					normals.resize(unique.size() * 3);
					texCoords.resize(unique.size() * 2);
					for (k = 0; k < (int)unique.size(); ++k)
					{
						int j;
						for (j = 0; j < 3; ++j)
						{
							verts[k * 3 + j] = visibleGeometry.vertexArray[unique[k]][j];
							normals[k * 3 + j] = visibleGeometry.normalArray[unique[k]][j];
						}
						for (j = 0; j < 2; ++j)
							texCoords[k * 2 + j] = texCoordArray[unique[k]][j];
					}
				}
			}
			else
			{
				if (primitive == G3D::RenderDevice::QUADS)
				{
					ind16.resize(vertexIndices.size() / 4 * 6);
					for (k = 0; k < vertexIndices.size(); k += 4)
					{
						int quad = k / 4;
						ind16[quad * 6] = vmap[vertexIndices[quad * 4]];
						ind16[quad * 6 + 1] = vmap[vertexIndices[quad * 4 + 1]];
						ind16[quad * 6 + 2] = vmap[vertexIndices[quad * 4 + 3]];
						ind16[quad * 6 + 3] = vmap[vertexIndices[quad * 4 + 3]];
						ind16[quad * 6 + 4] = vmap[vertexIndices[quad * 4 + 1]];
						ind16[quad * 6 + 5] = vmap[vertexIndices[quad * 4 + 2]];
					}
					verts.resize(unique.size() * 3);
					normals.resize(unique.size() * 3);
					texCoords.resize(unique.size() * 2);
					for (k = 0; k < (int)unique.size(); ++k)
					{
						int j;
						for (j = 0; j < 3; ++j)
						{
							verts[k * 3 + j] = visibleGeometry.vertexArray[unique[k]][j];
							normals[k * 3 + j] = visibleGeometry.normalArray[unique[k]][j];
						}
						for (j = 0; j < 2; ++j)
							texCoords[k * 2 + j] = texCoordArray[unique[k]][j];
					}
				}
				else if (primitive == G3D::RenderDevice::TRIANGLES)
				{
					ind16.resize(vertexIndices.size());
					for (k = 0; k < vertexIndices.size(); ++k)
						ind16[k] = vmap[vertexIndices[k]];
					verts.resize(unique.size() * 3);
					normals.resize(unique.size() * 3);
					texCoords.resize(unique.size() * 2);
					for (k = 0; k < (int)unique.size(); ++k)
					{
						int j;
						for (j = 0; j < 3; ++j)
						{
							verts[k * 3 + j] = visibleGeometry.vertexArray[unique[k]][j];
							normals[k * 3 + j] = visibleGeometry.normalArray[unique[k]][j];
						}
						for (j = 0; j < 2; ++j)
							texCoords[k * 2 + j] = texCoordArray[unique[k]][j];
					}
				}
			}
			subMesh = reinterpret_cast<Ogre::GeometryBuilder*>(engine)->createIndexed(
				&verts[0], unique.size(), &normals[0], NULL, &texCoords[0],
				engine->getUseLargeVertexBuffer() ? NULL : &ind16[0],
				engine->getUseLargeVertexBuffer() ? &inds32[0] : NULL,
				engine->getUseLargeVertexBuffer() ? inds32.size() / 3 : ind16.size() / 3,
				reinterpret_cast<Ogre::Vector3*>(min), reinterpret_cast<Ogre::Vector3*>(max));
			bounds.setMinimum(min[0], min[1], min[2]);
			bounds.setMaximum(max[0], max[1], max[2]);
			dirty = false;
		}
	}
}
