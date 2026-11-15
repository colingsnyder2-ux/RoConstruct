#pragma once
// 2008-06 native RBX::Block (inactive); non-colliding name, see v8world/Geometry2008.h.
//   RTTI     vtable 0083f7ec .?AVBlock@RBX@@ -> Geometry (mdisp 0); 9 slots: 0 onSetSize 00648fd0, 1 ??_G 005e73b0
//            (folded with Geometry's: the destructor is empty), 2 getGeometryType 0077d810 (folded `mov eax, 2`),
//            3 setGridSize 005e72a0 (inherited), 4 getRadius 004e5b70, 5 getCenterToCorner 00648270, 6 getMoment
//            005e7390 (-> getMomentHollow 006477b0), 7 getGridVolume 006478f0, 8 hitTest 00647f40.
//   size     0x18: Primitive::newGeometry 005e7d80 news 0x18 for GEOMETRY_BLOCK.
//   ctor     inline (005e7d80): gridSize = 0, cornerRadius (+0x14) = 0, vertices (+0x10) = NULL, vtable 0083f7ec.
//   vertices +0x10: onSetSize 00648fd0 stores BlockTemplate::getVertices 00648f30 (eight Vector3 of a shared
//            0x60-byte BlockTemplate); getPlanePoint 00647990 / getEdgePoint 00647900 / projectToFace 00647b90 /
//            getBallInsideInfo 00647ab0 index it.
//   cornerRadius +0x14: onSetSize stores vertices[0].magnitude() (fsqrt); getRadius 004e5b70 and getCenterToCorner
//            00648270 read it.
#include "v8world/Geometry2008.h"
// GeoPairType (getBallInsideInfo / getBallBlockInfo): the 2008 GeoPair2008.h, not the donor v8kernel/Pair.h (which
// pulls the donor Body.h and cannot share a unit with Body2008.h / GeoPair2008.h, e.g. BlockBlockContactStep.cpp).
#include "v8world/GeoPair2008.h"
#include "util/NormalId.h"
#include <G3D/Vector2.h>
#include <G3D/Vector3int16.h>
#include <functional>
#include <map>

namespace RBX
{
	class Block : public Geometry
	{
		friend struct ::NativeWorldShapesLayout;

	private:
		const G3D::Vector3* vertices; // +0x10
		float cornerRadius;           // +0x14

	private:
		// inlined into getBallBlockInfo 00647a20
		const G3D::Vector3* getCornerPoint(const G3D::Vector3int16& clip) const
		{
			return &vertices[((clip.x <= 0) * 2 + (clip.y <= 0)) * 2 + (clip.z <= 0)];
		}
		const G3D::Vector3* getEdgePoint(const G3D::Vector3int16& clip, NormalId& normalID) const;    // 00647900
		const G3D::Vector3* getPlanePoint(const G3D::Vector3int16& clip, NormalId& normalID) const;   // 00647990
		G3D::Matrix3 getMomentHollow(float mass) const;                                              // 006477b0
		virtual void onSetSize();                                                                    // 00648fd0

	public:
		Block() : vertices(NULL), cornerRadius(0.0f) {}

		virtual bool hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside);   // 00647f40

		virtual GeometryType getGeometryType() const     // 0077d810 (folded)
		{
			return GEOMETRY_BLOCK;
		}

		virtual float getRadius() const                  // 004e5b70
		{
			return cornerRadius;
		}

		virtual G3D::Vector3 getCenterToCorner(const G3D::Matrix3& rotation) const;   // 00648270

		virtual G3D::Matrix3 getMoment(float mass) const // 005e7390
		{
			return getMomentHollow(mass);
		}

		virtual float getGridVolume() const;             // 006478f0

		void projectToFace(G3D::Vector3& ray, G3D::Vector3int16& clip, int& onBorder);                                   // 00647b90
		GeoPairType getBallInsideInfo(const G3D::Vector3& ray, const G3D::Vector3*& offset, NormalId& normalID);         // 00647ab0
		GeoPairType getBallBlockInfo(int onBorder, G3D::Vector3int16 clip, const G3D::Vector3*& offset, NormalId& normalID); // 00647a20
		int getClosestEdge(const G3D::Matrix3& rotation, NormalId normalID, G3D::Vector3& crossAxis);                   // 00647d10
		G3D::Vector2 getProjectedVertex(const G3D::Vector3& vertex, NormalId normalID);                                  // 00647c70

		const G3D::Vector3& getExtent() const
		{
			return *vertices;
		}

		// donor v8world/Block.h inline, computed twice by BlockBlockContact::loadGeoPairEdgeEdge 00607ea0
		// (00607ea6..00607ed9 / 00607edb..00607f0f).
		NormalId getEdgeNormal(int edge)
		{
			int answer = edge / 4 + 3 * (edge % 2);
			if (edge > 12)
				answer = (answer + 3) % 6;
			return (NormalId)answer;
		}
		// 00606b00 (?getEdgeVertex@Block@RBX@@QBEPBVVector3@G3D@@H@Z, `ret 4`; called by loadGeoPairEdgeEdge 00607ea0
		// on Primitive +0x9c). Body: native-classes/BlockBallShape.cpp.
		const G3D::Vector3* getEdgeVertex(int edge) const;   // 00606b00
	};
}
