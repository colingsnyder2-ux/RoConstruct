// 2008-06 native RBX::RenderBase::Mesh members (inactive), the RenderBase Mesh.cpp unit 00547440..(past 0054c000).
// Built by tests/record_native_app_unit548.py with the RenderBase library profile of tests/record_native_render_scene.py
// (/Od /Ob0 /GS plus the Ogre 1.4.5 client headers) against the read-only ViewNew/RenderBaseMesh.h (ViewNew owner).
//   ShadowSurface::ShadowSurface()   0054a9f0 (Mesh() 005485c3: Array ctors 0054bf50 / 00481520 / 0054bfe0 / 00481520,
//                                              RCP<Level> ctor 004f0810)
//   ShadowSurface::~ShadowSurface()  0054aa80 (~Mesh 00548c21: members destroyed in reverse order)
// Under NATIVE_APPUNIT548_PENDING (pending-build-only, not counted): Mesh() 00548570, initStatics 00547f60,
// allocVertex 00547fc0 / 00548000, freeVertex 00548640, detailIndex 0054aca0, detailLevel 00548f80, sendGeometry
// 00548fe0, endRender 00549030 (and ??_G 0054a9c0 with the vtable). Each `xor r, r; jne` pair in the target is an
// empty release-build debugAssert (do {} while (0)); the asserted expressions are not visible in the bytes and only
// their positions are significant.
#include "ViewNew/RenderBaseMesh.h"

namespace RBX
{
	namespace RenderBase
	{
		Mesh::ShadowSurface::ShadowSurface()
		{
		}

		Mesh::ShadowSurface::~ShadowSurface()
		{
		}

#ifdef NATIVE_APPUNIT548_PENDING
		// Needs the Mesh statics the read-only ViewNew/RenderBaseMesh.h does not declare (proposal in the receipt;
		// verified against the generated out/native-layouts/app-unit548/pending/ViewNew/RenderBaseMesh.h).
		static bool init;            // 00973980 (Mesh() 005485ea / 005485fa only)
		static int vertexRefCount;   // 009738a4 (allocVertex 00547fe6 / 0054812f, freeVertex 0054866e only)

		G3D::MeshAlg::Geometry Mesh::visibleGeometry;      // 009738f0 (vertexArray +0, normalArray +0xc 009738fc)
		G3D::Array<G3D::Vector2> Mesh::texCoordArray;      // 00973934
		G3D::Array<G3D::Vector3> Mesh::tangentArray;       // 00973928
		G3D::Array<int> Mesh::vertexRefCounts;             // 009738c4
		G3D::Array<int> Mesh::freeList;                    // 009738ac
		bool Mesh::varDirty;                               // 009738a1

		Mesh::Mesh()
		{
			if (!init)
			{
				initStatics();
				init = true;
			}

			debugBoundingRadius = 0.0f;
			subMesh = NULL;
			meshKind = 0;
		}

		void Mesh::initStatics()
		{
			visibleGeometry.vertexArray.resize(1);
			visibleGeometry.normalArray.resize(1);
			texCoordArray.resize(1);
			tangentArray.resize(1);
			vertexRefCounts.resize(1);
			vertexRefCounts[0] = 1;
			freeList.clear();
		}

		unsigned int Mesh::allocVertex(unsigned int i, unsigned int count)
		{
			debugAssert(i > 0);
			vertexRefCounts[i] += count;
			vertexRefCount += count;
			return i;
		}

		unsigned int Mesh::allocVertex(const G3D::Vector3& vertex, const G3D::Vector3& normal, const G3D::Vector2& tex, bool share)
		{
			if (!varDirty)
				varDirty = true;
			vertexPoolChanged = true;

			unsigned int index;
			if (freeList.length() == 0)
			{
				index = visibleGeometry.vertexArray.size();
				debugAssert(index == visibleGeometry.normalArray.size());
				visibleGeometry.vertexArray.append(vertex);
				debugAssert(index == visibleGeometry.vertexArray.size() - 1);
				visibleGeometry.normalArray.append(normal);
				debugAssert(index == visibleGeometry.normalArray.size() - 1);
				texCoordArray.append(tex);
				debugAssert(index == texCoordArray.size() - 1);
				tangentArray.append(G3D::Vector3::zero());
				debugAssert(index == tangentArray.size() - 1);
				vertexRefCounts.append(1);
			}
			else
			{
				index = freeList.pop();
				visibleGeometry.vertexArray[index] = vertex;
				visibleGeometry.normalArray[index] = normal;
				texCoordArray[index] = tex;
				tangentArray[index] = G3D::Vector3::zero();
				debugAssert(vertexRefCounts[index] == 0);
				vertexRefCounts[index] = 1;
			}

			vertexRefCount++;
			return index;
		}

		void Mesh::freeVertex(unsigned int index)
		{
			if (!vertexRefCounts.getCArray())
				return;
			if (!vertexRefCounts.size())
				return;

			debugAssert(vertexRefCount > 0);
			vertexRefCount--;
			int refCount = vertexRefCounts[index];
			debugAssert(refCount > 0);

			if (refCount == 1)
			{
				vertexRefCounts[index] = 0;
				freeList.push(index);
			}
			else
			{
				vertexRefCounts[index] = refCount - 1;
			}
		}
		int Mesh::detailIndex(double detail) const
		{
			return G3D::iClamp((int)(levels.size() * detail), 0, levels.size() - 1);
		}

		const G3D::ReferenceCountedPointer<Mesh::Level> Mesh::detailLevel(float detail)
		{
			int index = detailIndex(detail);
			return levels[index].getPointer();
		}

		void Mesh::sendGeometry(const Level* lvl, G3D::RenderDevice* rd)
		{
			debugAssert(rd);
			if (varDirty)
				return;
			if (!lvl)
				return;

			int count = lvl->indexArray.size();
			if (count > 0)
				rd->sendIndices(lvl->primitive, lvl->indexArray);
		}

		void Mesh::endRender(G3D::RenderDevice* rd)
		{
			if (varDirty)
				return;
			rd->endIndexedPrimitives();
			debugAssert(rd);
		}
#endif
	}
}

// Template members of this unit, explicitly instantiated (Mesh() / ~Mesh() / the static vertex pool call them; with
// /Ob0 each is an out-of-line COMDAT the original links at the address the recorder binds):
//   Array<RCP<Level> > ctor 0054bec0 / dtor 0054bee0 (levels +0xc: Mesh() 005485b4, ~Mesh 00548c30)
//   vector<unsigned short> ctor 0054b2a0 / dtor 0054b310 (+0x50: 005485d2 / 00548c12)
//   vector<Vector3> ctor 0054c050 / dtor 0054c0c0 (+0x68: 005485e1 / 00548c03)
//   Array<int> (the static vertex reference counts 009738c4 and free list 009738ac; 4-byte elements, lea [x+i*4]):
//     append 0054ad70 (allocVertex 00548098), push 0054ae30 (freeVertex 005486bd), pop 0054ae50 (allocVertex
//     005480a9, push 0 = default shrink flag), operator[](int) 0054ae90 (initStatics 00547fa6, push 0),
//     operator[](unsigned) 0054aeb0 (allocVertex / freeVertex), length 0054ad50 (allocVertex 00548024), clear
//     0054ad30 (initStatics 00547fb6)
//   Array<Vector2> (the static texture coordinates 00973934; 8-byte elements): resize(int) 0054bda0 (initStatics
//     00547f82), append 0054bdc0 (allocVertex 0054806b)
template G3D::Array<G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh::Level> >::Array();
template G3D::Array<G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh::Level> >::~Array();
template std::vector<unsigned short>::vector();
template std::vector<unsigned short>::~vector();
template std::vector<G3D::Vector3>::vector();
template std::vector<G3D::Vector3>::~vector();
template void G3D::Array<int>::append(const int&);
template void G3D::Array<int>::push(const int&);
template int G3D::Array<int>::pop(bool);
template int& G3D::Array<int>::operator[](int);
template int& G3D::Array<int>::operator[](unsigned int);
template int G3D::Array<int>::length() const;
template void G3D::Array<int>::clear();
template void G3D::Array<G3D::Vector2>::resize(int);
template void G3D::Array<G3D::Vector2>::append(const G3D::Vector2&);
