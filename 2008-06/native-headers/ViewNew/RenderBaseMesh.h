#pragma once
// >>> native-status (generated) -- do not edit >>>
// RenderBaseMesh | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 9fe56c00 | roc native-status --write
// 2008-06 native RBX::RenderBase::Mesh / Mesh::Level (inactive; base declarations for the ViewNew meshes).
// The RenderBase library bodies themselves (00547f60..0054c...) are compiled /Od and are not recovered here.
//   Mesh     vtable 0082d028 .?AVMesh@RenderBase@RBX@@ -> G3D::ReferenceCountedObject (mdisp 0); one slot (??_G 0054a9c0).
//            ctor 00548570 (out of line): ReferenceCountedObject 00472990, levels +0xc (Array ctor 0054bec0),
//            shadowSurface +0x18 (0054a9f0), two std::vector members +0x50 (_Buy 0054c500: 2-byte elements) and
//            +0x68 (_Buy 0054d940: 0xc-byte elements), once-only initStatics 00547f60 (flag 00973980),
//            debugBoundingRadius +0x4c = 0, subMesh +0x80 = NULL, +0x84 = 0.
//            dtor 00548a90 (out of line; every ViewNew mesh ??_G 004e54c0 calls it directly).
//   size     0x88: the derived meshes add no fields (BrickMesh 004e53c0 / SphereMesh 004fcfb0 only store +0x84).
//   +0x84    a per-class mesh kind set after Mesh() by each derived constructor (BrickMesh 1, SphereMesh 2, ...).
//   +0x80    an owned Ogre sub-mesh: the dtor deletes it through its non-virtual deleting destructor 0054ac70
//            (-> 006824e0, an exe-local Ogre::SubMesh subclass) and unregisters it.
//   Level    vtable 00826e4c .?AVLevel@Mesh@RenderBase@RBX@@ -> ReferenceCountedObject; header-inline ctor 004dd2e0
//            (indexArray +0xc zeroed, primitive +0x18, dirty +0x1c = true, +0x20 = -1, subMesh +0x24 = NULL);
//            size 0x28 (SphereMesh 004fcfb0 news 0x28); dtor 005489b0 out of line (??_G 004dd340).
//            Level cleanup 005486e0 sets +0x1c and deletes +0x24 like Mesh +0x80.
//   ShadowSurface +0x18 (0x34): four G3D::Array (ctors 0054bf50, 00481520, 0054bfe0, 00481520) and a
//            ReferenceCountedPointer<Level> +0x30 (0x4f0810). Array element types follow the donor RenderLib Mesh.h
//            (the Array layout does not depend on them).
#include <G3D/ReferenceCount.h>
#include <G3D/Array.h>
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/MeshAlg.h>
#include <GLG3D/RenderDevice.h>
#include <vector>

struct NativeViewNewLayout;
namespace G3D { class VAR; }

namespace Ogre
{
	class GeometryBuilder;
	class MeshPtr;
	class RbxSubMesh; // incomplete: only owned through a pointer (deleted via 0054ac70)
}

namespace RBX
{
	namespace RenderBase
	{
		class Chunk;
		class Mesh : public G3D::ReferenceCountedObject
		{
			friend struct ::NativeViewNewLayout;
			typedef G3D::Array<int> VertexList;
			static VertexList vertexRefCounts;
			static VertexList freeList;
			static G3D::MeshAlg::Geometry visibleGeometry;
			static G3D::Array<G3D::Vector2> texCoordArray;
			static G3D::Array<G3D::Vector3> tangentArray;
			static G3D::VAR vertexVAR, normalVAR, texCoordVAR, tangentVAR;
			static void computeAABounds(const std::vector<G3D::ReferenceCountedPointer<Chunk> >&, G3D::Vector3&, G3D::Vector3&); // 00547440
			static void makeVAR(); // 00548cb0
			static bool varDirty;
			static Ogre::MeshPtr sharedMesh; // inferred name; 009738b8, donor Mesh shared buffer
		public:
			class Level : public G3D::ReferenceCountedObject
			{
				friend struct ::NativeViewNewLayout;
			public:
				G3D::Array<unsigned int> indexArray;     // +0x0c
				G3D::RenderDevice::Primitive primitive;  // +0x18
				bool dirty;                              // +0x1c
				int vertexStart;                         // +0x20 (-1)
				Ogre::RbxSubMesh* subMesh;               // +0x24

			public:
				Level(G3D::RenderDevice::Primitive primitive)  // 004dd2e0
					: primitive(primitive),
					  dirty(true),
					  vertexStart(-1),
					  subMesh(NULL)
				{
				}
				void invalidate();                       // inferred name; 005486e0
				virtual ~Level();                        // 005489b0
			};
			typedef G3D::ReferenceCountedPointer<Level> LevelRef;

			class ShadowSurface
			{
			public:
				G3D::Array<G3D::MeshAlg::Edge> edgeArray;          // +0x00
				G3D::Array<G3D::Vector3> faceNormalArray;          // +0x0c
				G3D::Array<G3D::MeshAlg::Face> faceArray;          // +0x18
				G3D::Array<G3D::Vector3> geometry;                 // +0x24
				G3D::ReferenceCountedPointer<Level> dropShadowGeometry; // +0x30
			public:
				ShadowSurface();                                   // 0054a9f0
				~ShadowSurface();
			};

		protected:
			G3D::Array<G3D::ReferenceCountedPointer<Level> > levels; // +0x0c
			ShadowSurface shadowSurface;                              // +0x18
		public:
			float debugBoundingRadius;                                // +0x4c
		protected:
			// Element types from the _Buy element sizes only (2 and 0xc bytes); the names describe that, the
			// RenderBase bodies that fill them are not recovered.
			std::vector<unsigned short> shadowIndices;                // +0x50 (0x18-byte VS2008 std::vector)
			std::vector<G3D::Vector3> shadowVertices;                 // +0x68
			Ogre::RbxSubMesh* subMesh;                                // +0x80
			int meshKind;                                             // +0x84

		protected:
			void computeShadowSurface(const LevelRef& level); // donor signature; 00548150
			// Original 0054aca0 multiplies detail by level count before clamping.
			int detailIndex(double detail) const
			{
				return G3D::iClamp((int)(levels.size() * detail), 0, levels.size() - 1);
			}

			static void updateGeometry(Ogre::GeometryBuilder*); // inferred name and receiver; 005493e0
			static void initStatics(); // 00547f60; donor declaration, original call 005485f5.

			Mesh();                                                   // 00548570
		public:
			static G3D::ReferenceCountedPointer<Mesh> aggregate(const std::vector<G3D::ReferenceCountedPointer<Chunk> >&, G3D::CoordinateFrame&, float&); // 00547610
			virtual ~Mesh();                                          // 00548a90
			static void sendGeometry(const Level*, G3D::RenderDevice*); // 00548fe0
			static void beginRender(G3D::RenderDevice*, bool, bool);   // 00548ec0
			static void setShadowVertex(const G3D::Vector3&);          // 00548c60
			void computeDirectionalShadowVolume(const G3D::CoordinateFrame&, const G3D::Vector3&,
				G3D::Array<unsigned int>&, G3D::Array<G3D::Vector3>&, bool) const; // 00549050
			static void endRender(G3D::RenderDevice*);                  // 00549030

			// Donor signature; 0053f828 calls 00548f80 with hidden return and float argument.
			const G3D::ReferenceCountedPointer<Level> detailLevel(float detail) const; // 00548f80

			static unsigned int allocVertex(unsigned int i, unsigned int count);   // 00547fc0
			// cdecl statics the LevelBuilder grid template calls (004fac10..: push 4 arguments, add esp 0x10 / 4)
			static unsigned int allocVertex(const G3D::Vector3& vertex, const G3D::Vector3& normal, const G3D::Vector2& tex, bool share); // 00548000
			static void freeVertex(unsigned int index);                               // 00548640
		};
	}
}
