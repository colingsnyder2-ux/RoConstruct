// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; };
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame {
public:
	Matrix3 rotation;
	Vector3 translation;
	CoordinateFrame(const CoordinateFrame& o) : rotation(o.rotation), translation(o.translation) {}
	CoordinateFrame operator*(const CoordinateFrame& other) const;
	CoordinateFrame toObjectSpace(const CoordinateFrame& c) const;
};
}
namespace RBX {
enum NormalId { NORM_X = 0 };
enum SurfaceType { NO_SURFACE = 0, GLUE = 1 };
namespace Math { G3D::CoordinateFrame snapToGrid(const G3D::CoordinateFrame& snap, float grid); }
class Face {
public:
	G3D::Vector3 c0, c1, c2, c3;
	Face projectOverlapOnMe(const Face& other) const;
	Face toObjectSpace(const G3D::CoordinateFrame& cf) const;
	Face toWorldSpace(const G3D::CoordinateFrame& cf) const;
	void snapToGrid(float grid);
	static bool cornersAligned(const Face& f0, const Face& f1, float tolerance);
};
class Primitive {
public:
	char pad[0xfc];
	SurfaceType surfaceType[6];
	SurfaceType getSurfaceType(NormalId id) const { return surfaceType[id]; }
	Face getFaceInWorld(NormalId id);
	const G3D::CoordinateFrame& getCoordinateFrame() const;
	G3D::CoordinateFrame getFaceCoordInObject(NormalId id) const;
};
class Joint {
public:
	static bool canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
};
class GlueJoint : public Joint {
public:
	GlueJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1, const Face& overlap);
	char data[0x100];
	static bool compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		SurfaceType s0 = p0->getSurfaceType(nId0);
		SurfaceType s1 = p1->getSurfaceType(nId1);
		return s0 == GLUE || s1 == GLUE;
	}
	static GlueJoint* canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
};
GlueJoint* GlueJoint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
{
	if (!compatibleSurfaces(p0, p1, nId0, nId1) || !canBuildJointLoose(p0, p1, nId0, nId1))
		return 0;

	Face f0 = p0->getFaceInWorld(nId0);
	Face f1 = p1->getFaceInWorld(nId1);

	Face overlapOn0 = f0.projectOverlapOnMe(f1);
	Face overlapOn1 = f1.projectOverlapOnMe(f0);

	Face offsetInP0 = overlapOn0.toObjectSpace(p0->getCoordinateFrame());
	Face offsetInP1 = overlapOn1.toObjectSpace(p1->getCoordinateFrame());

	offsetInP0.snapToGrid(0.1f);
	offsetInP1.snapToGrid(0.1f);

	Face offset0World = offsetInP0.toWorldSpace(p0->getCoordinateFrame());
	Face offset1World = offsetInP1.toWorldSpace(p1->getCoordinateFrame());

	if (!Face::cornersAligned(offset0World, offset1World, 0.05f))
		return 0;

	G3D::CoordinateFrame jointCoord0 = p0->getFaceCoordInObject(nId0);
	G3D::CoordinateFrame jointCoord0InWorld = p0->getCoordinateFrame() * jointCoord0;
	G3D::CoordinateFrame jc0InP1 = p1->getCoordinateFrame().toObjectSpace(jointCoord0InWorld);
	G3D::CoordinateFrame jointCoord1 = Math::snapToGrid(jc0InP1, 0.1f);
	Face overlapInJoint0 = offsetInP0.toObjectSpace(jointCoord0);

	return new GlueJoint(p0, p1, jointCoord0, jointCoord1, overlapInJoint0);
}
}
