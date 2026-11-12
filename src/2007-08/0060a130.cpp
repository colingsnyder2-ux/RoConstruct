// from server: 100% by EspClaude
// from server: 58% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_claude_77a572c0dee127a0.cpp

// Candidate translation unit (score above; library headers required).
#ifndef V8KERNEL_BODY_H
#define V8KERNEL_BODY_H

#include "decomp.h"
#include "util/IndexArray.h"
#include "util/Math.h"
#include "util/PV.h"
#include "util/Velocity.h"
#include "v8kernel/Cofm.h"
#include "v8kernel/KernelIndex.h"
#include "v8kernel/SimBody.h"

#include <G3D/CoordinateFrame.h>
#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>

namespace RBX {

class Kernel;
class KernelData;
class Link;

using G3D::CoordinateFrame;
using G3D::Matrix3;
using G3D::Vector3;

// SIZE 0xcc
class Body : public KernelIndex
{
public:
	Body();
	~Body();

private:
	void updatePV() const;

public:
	Body* getParent() const { return parent; }

	Body* getRoot() { return root; }

	float getMass() const { return mass; }

	float getBranchMass() const { return cofm != NULL ? cofm->getMass() : mass; }

	int numChildren() const { return children.size(); }

	Body* getChild(int index) const { return children[index]; }

	const Vector3& getCofmOffset() const { return cofm != NULL ? cofm->getCofmInBody() : Vector3::zero(); }

	const Vector3& getPos() const
	{
		updatePV();
		return pv.position.translation;
	}

	Matrix3 getIBody() const { return moment; }

	Matrix3 getBranchIBody() const { return cofm != NULL ? cofm->getMoment() : moment; }

	Vector3 getIBodyV3() const { return Math::toDiagonal(getIBody()); }
	Vector3 getBranchIBodyV3() const { return Math::toDiagonal(getBranchIBody()); }

	const Vector3& getBranchForce() const
	{
		const SimBody* simBody = getRootSimBody();

		return simBody != NULL ? simBody->getForce() : Vector3::zero();
	}

	const Vector3& getBranchTorque() const
	{
		const SimBody* simBody = getRootSimBody();

		return simBody != NULL ? simBody->getTorque() : Vector3::zero();
	}

	Matrix3 getIWorld() const { return Math::momentToWorldSpace(getIBody(), getPV().position.rotation); }

	Matrix3 getBranchIWorld() const { return Math::momentToWorldSpace(getBranchIBody(), getPV().position.rotation); }

	Matrix3 getIWorldAtPoint(const Vector3& point) const;

	float kineticEnergy() const;

	void step(float dt, bool throttling);

	CoordinateFrame getBranchCofmCoordinateFrame() const;

	const Velocity& getVelocity() const
	{
		updatePV();
		return pv.velocity;
	}
	Matrix3 getBranchIWorldAtPoint(const Vector3& point) const;

	const PV& getPV() const
	{
		updatePV();
		return pv;
	}

	void setPv(const PV& value);

	int getStateIndex() const
	{
		updatePV();
		return stateIndex;
	}

	const CoordinateFrame& getCoordinateFrame() const
	{
		updatePV();
		return pv.position;
	}

	static Body* getWorldBody();

	static int getNextStateIndex();

	void advanceStateIndex();

	void makeCofmDirty();

	Vector3 getBranchCofmPos() const;

	void accumulateForceAtBranchCofm(const Vector3& force);
	void accumulateForce(const Vector3& force, const Vector3& worldPos);
	void accumulateTorque(const Vector3& torque);
	void resetAccumulators();

	void setParent(Body* value);
	void setMeInParent(Link* value);
	void setMeInParent(const CoordinateFrame& value);

	void setCoordinateFrame(const CoordinateFrame& value);
	void setVelocity(const Velocity& velocity);
	void setMass(float value);
	void setMoment(const Matrix3& value);

private:
	friend class Kernel;
	friend class KernelData;

	void onChildAdded(Body* child);
	void onChildRemoved(Body* child);

	void resetRoot(Body* value);

	Body* calcRoot();

	SimBody* getRootSimBody() { return root->simBody; }
	const SimBody* getRootSimBody() const { return root->simBody; }

	int& getIndex() { return index; }

	int& getKernelIndex() { return kernelIndex; }

	Body* root;                                 // 0x04
	Body* parent;                               // 0x08
	mutable int index;                          // 0x0c
	IndexArray<Body, &Body::getIndex> children; // 0x10
	Cofm* cofm;                                 // 0x1c
	SimBody* simBody;                           // 0x20
	// 2007-08: one 4-byte field fewer between simBody (0x20) and moment; target reads moment at 0x58, pv.velocity.rotational.y at 0xc4
	Link* link;                                 // 0x24
	CoordinateFrame meInParent;                 // 0x28
	Matrix3 moment;                             // 0x58
	float mass;                                 // 0x7c
	mutable int stateIndex;                     // 0x80
	mutable PV pv;                              // 0x84
};

DECOMP_SIZE_ASSERT(Body, 0xcc)

// FUNCTION: WEBSERVICE 0x100ea020
inline void Body::accumulateForceAtBranchCofm(const Vector3& force)
{
	SimBody* simBody = getRootSimBody();

	if (simBody != NULL) {
		simBody->accumulateForceCofm(force);
	}
}

inline void Body::accumulateForce(const Vector3& force, const Vector3& worldPos)
{
	SimBody* simBody = getRootSimBody();

	if (simBody != NULL) {
		simBody->accumulateForce(force, worldPos);
	}
}

inline void Body::accumulateTorque(const Vector3& torque)
{
	SimBody* simBody = getRootSimBody();

	if (simBody != NULL) {
		simBody->accumulateTorque(torque);
	}
}

// FUNCTION: WEBSERVICE 0x10118c80
inline void Body::resetAccumulators()
{
	SimBody* simBody = getRootSimBody();
	if (simBody != NULL) {
		simBody->resetAccumulators();
	}
}

// SYNTHETIC: WEBSERVICE 0x10225130
// `RBX::Body::getWorldBody'::`2'::`dynamic atexit destructor for 'b''

// FUNCTION: WEBSERVICE 0x101049e0
inline Body* Body::calcRoot()
{
	return parent != NULL ? parent->calcRoot() : this;
}

// clang-format off
// FUNCTION: WEBSERVICE 0x100e9fe0
// RBX::Body::getBranchIBodyV3
// FUNCTION: WEBSERVICE 0x100ea1c0
// RBX::Body::getBranchTorque
// clang-format on

} // namespace RBX

#endif // V8KERNEL_BODY_H

#ifndef V8WORLD_PRIMITIVE_H
#define V8WORLD_PRIMITIVE_H

#include "decomp.h"
#include "util/ComputeProp.h"
#include "util/Extents.h"
#include "util/Face.h"
#include "util/Guid.h"
#include "util/NormalId.h"
#include "util/Vector3int32.h"
#include "v8world/Geometry.h"
#include "v8world/IPipelined.h"
#include "v8world/SurfaceData.h"

#include <G3D/CoordinateFrame.h>
#include <G3D/Ray.h>
#include <G3D/Vector3.h>
#include <algorithm>
#include <cmath>
#include <cstddef>

namespace RBX {

class Anchor;
class Assembly;
class Body;
class Clump;
class Contact;
class Controller;
class IMoving;
class Joint;
class Primitive;
class RigidJoint;
class SpatialNode;
class Velocity;
class World;

using G3D::CoordinateFrame;
using G3D::Ray;
using G3D::Vector3;

namespace Sim {

enum EdgeState
{
	UNDEFINED = 0,
	STEPPING = 1,
	SLEEPING = 2,
	TOUCHING = 3,
	TOUCHING_SLEEPING = 4,
};

} // namespace Sim

// SIZE 0x20
class __declspec(novtable) Edge : public IPipelined
{
public:
	enum EdgeType
	{
		JOINT = 0,
		CONTACT = 1,
	};

	Edge(Primitive* prim0, Primitive* prim1);

	virtual EdgeType getEdgeType() const = 0;                   // vtable+0x0c
	virtual void setPrimitive(int index, Primitive* primitive); // vtable+0x10

	Edge* getNext(const Primitive* primitive) const { return primitive == prim0 ? next0 : next1; }

	void setNext(Primitive* primitive, Edge* edge)
	{
		if (primitive == prim0) {
			next0 = edge;
		}
		else {
			next1 = edge;
		}
	}

	Primitive* getPrimitive(int index) const { return (&prim0)[index]; }

	Primitive* otherPrimitive(const Primitive* primitive) const { return primitive == prim0 ? prim1 : prim0; }

	bool getInEdgeList() const { return inEdgeList; }
	void setInEdgeList(bool value) { inEdgeList = value; }

	Sim::EdgeState getEdgeState() const { return edgeState; }
	void setEdgeState(Sim::EdgeState value) { edgeState = value; }

private:
	Sim::EdgeState edgeState; // 0x08
	Primitive* prim0;         // 0x0c
	Primitive* prim1;         // 0x10
	Edge* next0;              // 0x14
	Edge* next1;              // 0x18
	bool inEdgeList;          // 0x1c
};

DECOMP_SIZE_ASSERT(Edge, 0x20)

// SIZE 0x08
class EdgeList
{
public:
	static void insertEdge(Primitive* primitive, Edge* edge, EdgeList& list);
	static void removeEdge(Primitive* primitive, Edge* edge, EdgeList& list);

	EdgeList() : first(NULL), num(0) {}

	Edge* first; // 0x00
	int num;     // 0x04
};

DECOMP_SIZE_ASSERT(EdgeList, 0x08)

// VTABLE: WEBSERVICE 0x102376a4
// SIZE 0xd4
class Primitive : public IPipelined
{
public:
	Primitive(Geometry::GeometryType geometryType);

	static bool disableSleep;

private:
	friend class SpatialHash;
	friend class World;

	static bool ignoreBool;

	Guid guid;                   // 0x08
	bool guidSetExternally;      // 0x10
	unsigned int sizeMultiplier; // 0x14
	EdgeList contacts;           // 0x18
	EdgeList joints;             // 0x20
	int worldIndex;              // 0x28
	World* world;                // 0x2c
	Clump* clump;                // 0x30
	int clumpDepth;              // 0x34
	int traverseId;              // 0x38

	SpatialNode* spatialNodes;       // 0x3c
	char pad_40[0x20]; // 0x40 (2007-08: geometry at 0x60, body at 0x64 per target [prim+0x64])

protected:
	Geometry* geometry;          // 0x60
	Body* body;                  // 0x64
	IMoving* myOwner;            // 0x7c
	Anchor* anchorObject;        // 0x80
	bool dragging;               // 0x84
	bool anchored;               // 0x85
	bool canCollide;             // 0x86
	bool canSleep;               // 0x87
	float friction;              // 0x88
	float elasticity;            // 0x8c
	SurfaceType surfaceType[6];  // 0x90
	SurfaceData* surfaceData[6]; // 0xa8
	Controller* controller;      // 0xc0

	ComputeProp<float, Primitive> JointK; // 0xc4

	static Geometry* newGeometry(Geometry::GeometryType geometryType);

public:
	virtual ~Primitive(); // vtable+0x00

	// SYNTHETIC: WEBSERVICE 0x100a8740
	// RBX::Primitive::`scalar deleting destructor'

	Body* getBody() const { return body; }
	// FUNCTION: WEBSERVICE 0x1009a860
	Extents getExtentsWorld() const
	{
		const Vector3 corner = geometry->getGridSize() * 0.5f;

		return Extents(-corner, corner).toWorldSpace(getCoordinateFrame());
	}

	const Geometry* getGeometry() const { return geometry; }
	Geometry* getGeometry() { return geometry; }

	const Vector3& getGridSize() const { return geometry->getGridSize(); }
	Geometry::GeometryType getPrimitiveType() const { return geometry->getGeometryType(); }

	Clump* getClump() const { return clump; }
	IMoving* getOwner() const { return myOwner; }
	const bool getCanSleep() const { return canSleep; }
	Anchor* getAnchorObject() { return anchorObject; }
	bool getAnchor() const { return anchorObject != NULL; }

	bool getDragging() const { return dragging; }
	const bool getCanCollide() const { return canCollide; }
	float getFriction() const { return friction; }
	float getElasticity() const { return elasticity; }

	const Guid& getGuid() const;
	void setGuid(const Guid& value);

	int& worldIndexFunc() { return worldIndex; }

	unsigned int getSizeMultiplier() const { return sizeMultiplier; }
	void setSizeMultiplier(unsigned int multiplier);

	static void insertEdge(Edge* edge);
	static void removeEdge(Edge* edge);

	void setClump(Clump* value);

	int getClumpDepth() const { return clumpDepth; }
	void setClumpDepth(int value) { clumpDepth = value; }

	Assembly* getAssembly() const;

	void setDragging(bool value);
	void setAnchor(bool value);
	void setCanSleep(bool value);
	void setCanCollide(bool value);
	void setFriction(float value);
	void setElasticity(float value);

	const CoordinateFrame& getCoordinateFrame() const;
	void setVelocity(const Velocity& velocity);

	static void onNewTouch(Primitive* p0, Primitive* p1);

	bool hitTest(const Ray& ray, Vector3& hitPoint, bool& inside);

	CoordinateFrame getFaceCoordInObject(NormalId normalId);
	Face getFaceInObject(NormalId normalId);
	Face getFaceInWorld(NormalId normalId);

protected:
	float computeJointK() const;

private:
	Extents computeFuzzyExtents() const;

public:
	const Extents& getFastFuzzyExtents() const;

	void setSurfaceData(NormalId normalId, const SurfaceData& value);
	void setSurfaceType(NormalId normalId, SurfaceType surfaceType);

	SurfaceType getSurfaceType(NormalId normalId) const { return surfaceType[normalId]; }

	float getJointK() const { return JointK; }

	const SurfaceData& getSurfaceData(NormalId normalId) const
	{
		return surfaceData[normalId] != NULL ? *surfaceData[normalId] : SurfaceData::empty();
	}

	Controller* getController() { return controller; }

	CoordinateFrame getGridCorner() const;
	void setGridCorner(const CoordinateFrame& corner);

	void setCoordinateFrame(const CoordinateFrame& value);

private:
	Vector3 clipToSafeSize(const Vector3& size);

public:
	void setGridSize(const Vector3& size);

	void setController(Controller* value);
	void setPrimitiveType(Geometry::GeometryType geometryType);

	// FUNCTION: WEBSERVICE 0x100a8240
	virtual float getRadius() const { return geometry->getRadius(); } // vtable+0x0c

private:
	RigidJoint* getFirstRigidAt(Edge* edge);

public:
	Edge* getFirstEdge() const;
	Edge* getNextEdge(Edge* edge) const;
	Joint* getFirstJoint() const;
	Joint* getNextJoint(Joint* joint) const;
	Contact* getFirstContact();
	Contact* getNextContact(Contact* contact);
	RigidJoint* getFirstRigid();
	RigidJoint* getNextRigid(RigidJoint* joint);

	static Joint* getJoint(Primitive* p0, Primitive* p1);
	static Contact* getContact(Primitive* p0, Primitive* p1);

	// FUNCTION: WEBSERVICE 0x100d21e0
	static bool aaBoxCollide(const Primitive& p0, const Primitive& p1)
	{
		Vector3 delta = p0.getCoordinateFrame().translation - p1.getCoordinateFrame().translation;

		float r0 = p0.getRadius();
		float r1 = p1.getRadius();

		if (r0 + r1 < std::max(fabsf(delta.x), std::max(fabsf(delta.y), fabsf(delta.z)))) {
			return false;
		}

		const Extents& e1 = p1.getFastFuzzyExtents();
		const Extents& e0 = p0.getFastFuzzyExtents();

		return e0.overlapsOrTouches(e1);
	}

	static Primitive* downstreamPrimitive(Joint* joint);
};

DECOMP_SIZE_ASSERT(Primitive, 0xc0)

} // namespace RBX

#endif // V8WORLD_PRIMITIVE_H

#include "v8world/Joint.h"

#include "decomp.h"
#include "util/Face.h"
#include "util/Math.h"
#include "v8world/Primitive.h"
#include "v8kernel/Body.h"
#include "v8world/World.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x100d7b80
CoordinateFrame Joint::align(Primitive* pMove, Primitive* pStay)
{
	return CoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x101019b0 FOLDED
bool Joint::joinsFace(Primitive* primitive, NormalId normalId) const
{
	return false;
}

// FUNCTION: WEBSERVICE 0x1011e870
Joint::~Joint()
{
}

// FUNCTION: WEBSERVICE 0x1011e880
void Joint::setJointOwner(IJointOwner* value)
{
	jointOwner = value;
}

// FUNCTION: WEBSERVICE 0x1011e890
bool Joint::canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, float angleMax, float planarMax)
{
	if (!Math::fuzzyAxisAligned(p0->getBody()->getCoordinateFrame().rotation, p1->getBody()->getCoordinateFrame().rotation, angleMax)) {
		return false;
	}

	Face f0 = p0->getFaceInWorld(nId0);
	Face f1 = p1->getFaceInWorld(nId1);

	if (!Face::hasOverlap(f0, f1, 0.35f)) {
		return false;
	}

	return Face::overlapWithinPlanes(f0, f1, planarMax) ? true : false;
}

// FUNCTION: WEBSERVICE 0x1011e940
bool Joint::canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
{
	return canBuildJoint(p0, p1, nId0, nId1, 0.01f, 0.01f);
}

// FUNCTION: WEBSERVICE 0x1011e970
bool Joint::canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
{
	return canBuildJoint(p0, p1, nId0, nId1, 0.05f, 0.05f);
}

// FUNCTION: WEBSERVICE 0x1011e9a0
Joint::Joint(
	Primitive* prim0,
	Primitive* prim1,
	const CoordinateFrame& _jointCoord0,
	const CoordinateFrame& _jointCoord1
)
	: Edge(prim0, prim1), jointOwner(NULL), active(false)
{
	jointCoord0 = Math::snapToGrid(_jointCoord0, 0.1f);
	jointCoord1 = Math::snapToGrid(_jointCoord1, 0.1f);
}

// FUNCTION: WEBSERVICE 0x1011ea80
Joint::Joint() : Edge(NULL, NULL), jointOwner(NULL), active(false)
{
}

// FUNCTION: WEBSERVICE 0x1011eac0
void Joint::setPrimitive(int i, Primitive* p)
{
	if (p != getPrimitive(i)) {

		World* world = getWorld();

		if (world != NULL && getPrimitive(i) != NULL) {
			world->onJointPrimitiveNulling(this, getPrimitive(i));
		}

		Edge::setPrimitive(i, p);

		if (world != NULL && p != NULL) {
			world->onJointPrimitiveSet(this, p);
		}
	}
}

// FUNCTION: WEBSERVICE 0x1011eb30
void Joint::setJointCoord(int i, const CoordinateFrame& c)
{
	if (c != getJointCoord(i)) {
		if (i == 0) {
			jointCoord0 = c;
		}
		else {
			jointCoord1 = c;
		}

		if (World* world = getWorld()) {
			world->removeJoint(this);
			world->insertJoint(this);
		}
	}
}

} // namespace RBX
