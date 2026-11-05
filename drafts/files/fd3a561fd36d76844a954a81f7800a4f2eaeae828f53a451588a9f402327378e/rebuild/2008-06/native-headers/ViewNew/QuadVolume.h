#pragma once
// 2008-06 native RBX::ViewNew::LevelBuilder / RenderSurfaceTypes (inactive).
//   LevelBuilder  vtable 008270c8 .?AVLevelBuilder@ViewNew@RBX@@ (no bases); 7 slots: 0 build 00500d30, 1..6 the
//                 pure buildTop / buildBottom / buildLeft / buildRight / buildFront / buildBack (_purecall).
//                 Not novtable: the ctor 00500d80 stores 008270c8.
//   ctor 00500d80 (level&, Vector3 size by value, RenderSurfaceTypes; ret 0x14): halfSize +0x04 = size * 0.5f,
//                 surfaceTypes +0x10, level +0x14 (ReferenceCountedPointer, setPointer 00598fa0 ICF),
//                 textureScale +0x18 = (2, 2) (constant 0081c434); sizeof 0x20 (BevelMesh::Builder adds +0x20).
//   buildFace 00500ca0 switches (jump table) NormalId -> the face slot; build 00500d30 calls the six face slots in order 1..6; appendQuadFromVertexIndices 00500de0 (3) / 00500eb0 (4)
//   switch on level->primitive (TRIANGLES 2, QUADS 5) and append Mesh::allocVertex(i, 1) results to
//   level->indexArray (Array<unsigned>::append 00500690 / 004dc6a0); appendQuadFromIndexArray 00500fd0 / 00501000
//   map through level->indexArray and tail-jump to them.
//   RenderSurfaceTypes  one 32-bit word (+0x10), three bits per face (the buildFace templates read (data >> 3*face) & 7).
#include "ViewNew/RenderBaseMesh.h"
#include "util/NormalId.h"
#include <G3D/Vector2int16.h>

namespace RBX
{
	namespace ViewNew
	{
		enum RenderSurfaceType
		{
			FLAT,
			STUDS,
			INLET,
			WELD,
			GLUE
		};

		class RenderSurfaceTypes
		{
		public:
			unsigned int data;
		public:
			RenderSurfaceTypes()
				: data(0)
			{
			}
		};

		class LevelBuilder
		{
			friend struct ::NativeViewNewLayout;
		public:
			enum Purpose
			{
				Surface,
				Decal,
				Shadow
			};
		protected:
			const G3D::Vector3 halfSize;                                             // +0x04
			const RenderSurfaceTypes surfaceTypes;                                   // +0x10
			const G3D::ReferenceCountedPointer<RenderBase::Mesh::Level> level;       // +0x14
		public:
			G3D::Vector2 textureScale;                                               // +0x18

		protected:
			LevelBuilder(G3D::ReferenceCountedPointer<RenderBase::Mesh::Level>& level, G3D::Vector3 size, RenderSurfaceTypes surfaceTypes); // 00500d80
		public:
			virtual void build(Purpose purpose);                                     // 00500d30
			void buildFace(NormalId normalId, Purpose purpose);                      // 00500ca0

			virtual void buildTop(Purpose purpose) = 0;
			virtual void buildBottom(Purpose purpose) = 0;
			virtual void buildLeft(Purpose purpose) = 0;
			virtual void buildRight(Purpose purpose) = 0;
			virtual void buildFront(Purpose purpose) = 0;
			virtual void buildBack(Purpose purpose) = 0;
		protected:
			// Per-face grid builder (template instances 004fbdb0.., one per face and vertex function; not recovered
			// here: the face builders call them, bound to the addresses their call sites use).
			template<NormalId id, class Function>
			void buildFace(Function function, G3D::Vector2int16 divisions, Purpose purpose);

			// Builder-as-functor overload (instances 004f7bd0 / 004f7c80 WedgeBuilder, 004faa30 TorsoBuilder): copies
			// the builder argument, narrows the two counts to a Vector2int16 in the first count's slot and calls the
			// grid template (ret 0x30 / 0x34: builder by value, two counts, purpose).
			template<NormalId id, class Builder>
			void buildFace(Builder builder, const unsigned int x, const unsigned int y, Purpose purpose)
			{
				buildFace<id>(builder, G3D::Vector2int16(x, y), purpose);
			}

			void appendQuadFromIndexArray(int a, int b, int c, int d);               // 00501000
			void appendQuadFromIndexArray(int a, int b, int c);                      // 00500fd0
			void appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c, unsigned int d); // 00500eb0
			void appendQuadFromVertexIndices(unsigned int a, unsigned int b, unsigned int c);                 // 00500de0
		};
	}
}
