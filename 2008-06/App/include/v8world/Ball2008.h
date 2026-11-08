#pragma once
// >>> native-status (generated) -- do not edit >>>
// Ball2008 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d12fc9ab | roc native-status --write
// 2008-06 native RBX::Ball (inactive); non-colliding name, see v8world/Geometry2008.h.
//   RTTI     vtable 0083f814 .?AVBall@RBX@@ -> Geometry (mdisp 0); 9 slots: 0 onSetSize 00649190, 1 ??_G 005e73b0
//            (folded with Geometry's: the destructor is empty), 2 getGeometryType 007286a0 (folded `mov eax, 1`),
//            3 setGridSize 005e72a0 (inherited), 4 getRadius 005e73d0, 5 getCenterToCorner 005e73e0, 6 getMoment
//            005e7400 (-> getMomentSolid 00649130), 7 getGridVolume 00649170, 8 hitTest 006491a0.
//   size     0x14: Primitive::newGeometry 005e7d80 news 0x14 for GEOMETRY_BALL.
//   ctor     inline (005e7d80): Geometry's gridSize = 0, realRadius (+0x10) = 0, vtable 0083f814.
//   realRadius +0x10: onSetSize 00649190 stores gridSize.x * 0.5f; getRadius 005e73d0 / getCenterToCorner 005e73e0 /
//            getMomentSolid 00649130 / hitTest 006491a0 read it.
#include "v8world/Geometry2008.h"

namespace RBX
{
	class Ball : public Geometry
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		float realRadius; // +0x10

	private:
		G3D::Matrix3 getMomentSolid(float mass) const;   // 00649130
		virtual void onSetSize();                        // 00649190

	public:
		Ball() : realRadius(0.0f) {}

		virtual bool hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside);   // 006491a0

		virtual GeometryType getGeometryType() const     // 007286a0 (folded)
		{
			return GEOMETRY_BALL;
		}

		virtual float getRadius() const                  // 005e73d0
		{
			return realRadius;
		}

		virtual G3D::Vector3 getCenterToCorner(const G3D::Matrix3& rotation) const   // 005e73e0
		{
			return G3D::Vector3(realRadius, realRadius, realRadius);
		}

		virtual G3D::Matrix3 getMoment(float mass) const // 005e7400
		{
			return getMomentSolid(mass);
		}

		virtual float getGridVolume() const;             // 00649170
	};
}
