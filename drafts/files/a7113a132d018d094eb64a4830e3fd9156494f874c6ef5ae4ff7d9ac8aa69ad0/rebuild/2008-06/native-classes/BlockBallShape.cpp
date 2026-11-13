// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Block::getEdgeVertex 00606b00 (inactive), `?getEdgeVertex@Block@RBX@@QBEPBVVector3@G3D@@H@Z`
// (identity-registry). It sits in the contact code range (00606xxx) and is called twice by
// BlockBlockContact::loadGeoPairEdgeEdge 00607ea0 (`ret 4`, this = Primitive +0x9c geometry, returns a vertex
// pointer stored in the GeoPair).
// The other Block / Ball / Geometry shape targets of this batch are already defined as inline in-class bodies in
// native-headers/v8world/Geometry2008.h, Block2008.h and Ball2008.h, and are not duplicated here.
//
// Unit-local redeclaration (pattern of BlockBlockContactStep.cpp): RBX::Block is copied from
// native-headers/v8world/Block2008.h (same base, fields, offsets, slots) plus the public const member
// getEdgeVertex(int), which that read-only header does not declare (proposal in the batch result).
#include "v8world/Geometry2008.h"
#include "v8kernel/Pair.h"
#include "util/NormalId.h"
#include <G3D/Vector2.h>
#include <G3D/Vector3int16.h>

namespace RBX
{
	class Block : public Geometry
	{
	private:
		const G3D::Vector3* vertices; // +0x10
		float cornerRadius;           // +0x14

	private:
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

		const G3D::Vector3* getEdgeVertex(int edgeId) const;                                                            // 00606b00

		const G3D::Vector3& getExtent() const
		{
			return *vertices;
		}
	};

	// 0084aec8: six faces of four corner indices into the eight Block vertices (24 ints, .rdata of this code range;
	// also indexed by BlockBlockContact::computePlaneContact 00608580). Values read from the binary.
	// INFERRED: name; the binary keeps no symbol for this table.
	static const int faceVertex[6][4] =
	{
		{0, 2, 3, 1},
		{0, 1, 5, 4},
		{0, 4, 6, 2},
		{4, 5, 7, 6},
		{2, 6, 7, 3},
		{1, 3, 7, 5},
	};

	// 00606b00
	const G3D::Vector3* Block::getEdgeVertex(int edgeId) const
	{
		if (edgeId < 12)
		{
			return &vertices[faceVertex[edgeId / 4][edgeId % 4]];
		}
		else
		{
			edgeId -= 12;
			return &vertices[faceVertex[edgeId / 4][edgeId + 1]];
		}
	}
}
