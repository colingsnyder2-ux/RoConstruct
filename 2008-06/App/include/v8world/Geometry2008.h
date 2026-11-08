#pragma once
// >>> native-status (generated) -- do not edit >>>
// Geometry2008 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 8cce7fd5 | roc native-status --write
// 2008-06 native RBX::Geometry (inactive). Declared under a non-colliding name: the original include path
// v8world/Geometry.h is reached by every unit that includes Primitive.h / PartInstance.h, so a header at that path
// would shadow the donor for nearly all recorders (see the proposal in tests/record_native_world_shapes.py).
// A unit must not include both this header and the donor v8world/Geometry.h.
// Every virtual, field and inline body below is read from the 2008-06 binary:
//   RTTI     vtable 0083f7c4 .?AVGeometry@RBX@@, no base class; 9 slots:
//            0 onSetSize 0047d410 (folded empty `ret`), 1 scalar deleting dtor 005e73b0, 2 getGeometryType 005e2790
//            (returns 3), 3 setGridSize 005e72a0, 4 getRadius 005e72c0 (`fldz; ret`), 5 getCenterToCorner 005e78c0
//            (G3D::Vector3::zero() guard 0096f050), 6 getMoment 005e72d0 (Matrix3::zero() 00513dc0 copied with
//            Matrix3::operator= 00513220), 7 getGridVolume (folded with slot 4, 005e72c0), 8 hitTest 005e72f0
//            (`xor al, al; ret 0xc`).
//   size     0x10: the static of nullGeometry 005e7870 is 0097abd4 (vtable) .. 0097abe0 (gridSize.z); Block (0x18) and
//            Ball (0x14) start their own fields at +0x10 (Primitive::newGeometry 005e7d80).
//   ctor     inline: gridSize = (0, 0, 0) (fldz; fst +4/+8/+0xc in 005e7870 and 005e7d80), then the vtable.
//   dtor     inline and empty: 005e73b0 only restores the vtable 0083f7c4 before operator delete 006a067a; the
//            nullGeometry atexit destructor 007ff9e0 only restores the vtable.
//   gridSize +0x4: setGridSize 005e72a0 copies the Vector3 to +4/+8/+0xc, then calls slot 0 (onSetSize).
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <G3D/Ray.h>

struct NativeWorldShapesLayout;

namespace RBX
{
	class Geometry
	{
		friend struct ::NativeWorldShapesLayout; // tests/NativeWorldShapesLayout.cpp offset asserts

	public:
		enum GeometryType
		{
			GEOMETRY_BALL = 1,  // Ball::getGeometryType 007286a0
			GEOMETRY_BLOCK = 2, // Block::getGeometryType 0077d810
			GEOMETRY_NONE = 3,  // Geometry::getGeometryType 005e2790
		};

	protected:
		G3D::Vector3 gridSize; // +0x4

	protected:
		virtual void onSetSize() {}                                       // slot 0

	public:
		Geometry() : gridSize() {}
		virtual ~Geometry() {}                                             // slot 1 (??_G 005e73b0)

		virtual GeometryType getGeometryType() const                       // slot 2
		{
			return GEOMETRY_NONE;
		}

		virtual void setGridSize(const G3D::Vector3& _gridSize)            // slot 3
		{
			gridSize = _gridSize;
			onSetSize();
		}

		const G3D::Vector3& getGridSize() const
		{
			return gridSize;
		}

		virtual float getRadius() const                                    // slot 4
		{
			return 0.0f;
		}

		virtual G3D::Vector3 getCenterToCorner(const G3D::Matrix3& rotation) const   // slot 5
		{
			return G3D::Vector3::zero();
		}

		virtual G3D::Matrix3 getMoment(float mass) const                   // slot 6
		{
			return G3D::Matrix3::zero();
		}

		virtual float getGridVolume() const                                // slot 7
		{
			return 0.0f;
		}

		virtual bool hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside)   // slot 8
		{
			return false;
		}

		static Geometry* nullGeometry()                                    // 005e7870 (static g 0097abd4)
		{
			static Geometry g;
			return &g;
		}
	};
}
