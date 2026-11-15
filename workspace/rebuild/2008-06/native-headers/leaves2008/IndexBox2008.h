#pragma once
// 2008-06 native RBX::IndexBox (inactive). Declared under a non-colliding name (donor util/IndexBox.h describes a
// non-polymorphic IndexBox); a unit must not include both headers.
// Every field and slot below is read from the 2008-06 binary:
//   RTTI     vtable 0084d1cc .?AVIndexBox@RBX@@ (no bases), one slot: scalar deleting destructor 0066f8e0.
//   ctor     007bbed0 IndexBox(const Vector3& min, const Vector3& max), ret 8: vtable, eight Vector3 corners
//            +0x04..+0x63 zeroed by Vector3() and then assigned max/min component-wise (corner i at +0x04 + 12 * i).
//   dtor     0066f8d0 (inline virtual, emitted as a COMDAT next to AssemblyStage): stores the vtable only.
//   statics  INDEXBOX_FACE_TO_NORMAL 00875da0 (6x3 floats), INDEXBOX_FACE_TO_VERTEX 00875de8 (6x4 ints, read by
//            getFaceCorners 007bbe30), INDEXBOX_EDGE_TO_VERTEX_AND_NORMALS 00875e48 (12x4), INDEXBOX_FACE_EDGE_TO_NORMAL
//            00875f08 (6x4); contents equal the donor tables.
#include <G3D/Vector3.h>

struct NativeLeaves2008Layout;

namespace RBX
{
	class IndexBox
	{
		friend struct ::NativeLeaves2008Layout;

	private:
		G3D::Vector3 corner[8];        // +0x04

	public:
		static const float INDEXBOX_FACE_TO_NORMAL[6][3];
		static const int INDEXBOX_FACE_TO_VERTEX[6][4];
		static const int INDEXBOX_EDGE_TO_VERTEX_AND_NORMALS[12][4];
		static const int INDEXBOX_FACE_EDGE_TO_NORMAL[6][4];

	public:
		IndexBox(const G3D::Vector3& min, const G3D::Vector3& max);   // 007bbed0
		virtual ~IndexBox()                                          // 0066f8d0 (??_G 0066f8e0)
		{
		}

		void getFaceCorners(int f, G3D::Vector3& v0, G3D::Vector3& v1, G3D::Vector3& v2, G3D::Vector3& v3) const;   // 007bbe30
	};
}
