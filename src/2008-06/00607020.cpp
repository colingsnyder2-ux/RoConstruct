// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espclaude_2508eb102f132218.cpp

// Candidate translation unit (score above; library headers required).
#define protected public
#define private public
// exe-layout OpenRBX headers: Body pv at 0x94 without updatePV, Primitive +0x28 before oldSpatialMin
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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

// SIZE 0xd0
class Body : public KernelIndex
{
public:
	Body();
	~Body();

private:
	void updatePV() const {} // exe: no lazy PV update

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

	const bool getCanThrottle() const { return canThrottle; }

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
	bool canThrottle;                           // 0x24
	Link* link;                                 // 0x28
	CoordinateFrame meInParent;                 // 0x2c
	Matrix3 moment;                             // 0x5c
	float mass;                                 // 0x80
	mutable int stateIndex;                     // 0x84
	int exBodyPad[3];                           // exe: pv at 0x94
	mutable PV pv;                              // 0x94
};

DECOMP_SIZE_ASSERT(Body, 0xd0)

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
	char exSpatialPad[0x28];     // exe: oldSpatialMin at 0x68

	SpatialNode* spatialNodes;       // 0x3c
	Vector3int32 oldSpatialMin;      // 0x40
	Vector3int32 oldSpatialMax;      // 0x4c
	mutable Extents fuzzyExtents;    // 0x58
	mutable int fuzzyExtentsStateId; // 0x70

protected:
	Geometry* geometry;          // 0x74
	Body* body;                  // 0x78
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

DECOMP_SIZE_ASSERT(Primitive, 0xd4)

} // namespace RBX

#endif // V8WORLD_PRIMITIVE_H

#ifndef V8WORLD_CONTACT_H
#define V8WORLD_CONTACT_H

#include "decomp.h"
#include "v8kernel/Connector.h"
#include "v8world/Ball.h"
#include "v8world/Block.h"
#include "v8world/Primitive.h"

#include <G3D/Vector3int16.h>
#include <vector>
#include <G3D/Array.h>

namespace RBX {

using G3D::Vector3int16;

class Kernel;

// SIZE 0x34
class __declspec(novtable) Contact : public Edge
{
public:
	Contact(Primitive* p0, Primitive* p1);

	int& steppingIndexFunc() { return steppingIndex; }

	bool step(int uiStepId);

	bool computeIsAdjacent(float spaceAllowed);

	void onPrimitiveContactParametersChanged();

private:
	virtual void putInKernel(Kernel* _kernel); // vtable+0x04
	virtual void removeFromKernel();           // vtable+0x08
	virtual EdgeType getEdgeType() const;      // vtable+0x0c

protected:
	Body* getBody(int index) const { return getPrimitive(index)->getBody(); }

	ContactConnector* createConnector();
	ContactConnector* createConnector(Body* b0, Body* b1);
	void deleteConnector(ContactConnector*& c);

	virtual void deleteAllConnectors() = 0; // vtable+0x14
	virtual bool stepContact() = 0;         // vtable+0x18

public:
	virtual bool computeIsColliding(float overlapIgnored) = 0; // vtable+0x1c

private:
	friend class BlockBlockContact;

	static bool ignoreBool;

protected:
	static int contactPairMatches;
	static int contactPairMisses;

private:
	int lastContactStep; // 0x20
	int steppingIndex;   // 0x24
	float jointK;        // 0x28
	float elasticJointK; // 0x2c
	float kFriction;     // 0x30
};

DECOMP_SIZE_ASSERT(Contact, 0x34)

// VTABLE: WEBSERVICE 0x10246ddc
// SIZE 0x38
class BallBallContact : public Contact
{
public:
	BallBallContact(Primitive* p0, Primitive* p1);

	// SYNTHETIC: WEBSERVICE 0x10108060
	// RBX::BallBallContact::`scalar deleting destructor'

	virtual ~BallBallContact() {} // vtable+0x00

private:
	Ball* ball(int index) { return static_cast<Ball*>(getPrimitive(index)->getGeometry()); }

	virtual void deleteAllConnectors();                    // vtable+0x14
	virtual bool stepContact();                            // vtable+0x18
	virtual bool computeIsColliding(float overlapIgnored); // vtable+0x1c

	ContactConnector* ballBallConnector; // 0x34
};

DECOMP_SIZE_ASSERT(BallBallContact, 0x38)

// VTABLE: WEBSERVICE 0x10246e00
// SIZE 0x38
class BallBlockContact : public Contact
{
public:
	BallBlockContact(Primitive* p0, Primitive* p1);

	// SYNTHETIC: WEBSERVICE 0x101080b0
	// RBX::BallBlockContact::`scalar deleting destructor'

	virtual ~BallBlockContact() {} // vtable+0x00

private:
	Primitive* ballPrim() { return getPrimitive(0); }
	Primitive* blockPrim() { return getPrimitive(1); }

	Ball* ball() { return static_cast<Ball*>(ballPrim()->getGeometry()); }
	Block* block() { return static_cast<Block*>(blockPrim()->getGeometry()); }

	virtual void deleteAllConnectors();                    // vtable+0x14
	virtual bool stepContact();                            // vtable+0x18
	virtual bool computeIsColliding(float overlapIgnored); // vtable+0x1c

	bool computeIsColliding(int& onBorder, Vector3int16& clip, Vector3& projectionInBlock, float overlapIgnored);

	ContactConnector* ballBlockConnector; // 0x34
};

DECOMP_SIZE_ASSERT(BallBlockContact, 0x38)

// VTABLE: WEBSERVICE 0x10246e24
// SIZE 0x78
class BlockBlockContact : public Contact
{
public:
	BlockBlockContact(Primitive* p0, Primitive* p1);

	// SYNTHETIC: WEBSERVICE 0x10108e40
	// RBX::BlockBlockContact::`scalar deleting destructor'

	static float contactPairHitRatio();

private:
	Block* block(int index) { return static_cast<Block*>(getPrimitive(index)->getGeometry()); }

	virtual void deleteAllConnectors();                    // vtable+0x14
	virtual bool stepContact();                            // vtable+0x18
	virtual bool computeIsColliding(float overlapIgnored); // vtable+0x1c

	bool getBestPlaneEdge(bool& temp, float overlapIgnored);

	ContactConnector* matchContactConnector(Body* b0, Body* b1, GeoPairType _pairType, int param0, int param1);
	void deleteUnmatchedConnectors();

	void loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1);
	void loadGeoPairPointPlane(int pointBody, int planeBody, int pointID, NormalId pointFaceID, NormalId planeFaceID);
	void loadGeoPairEdgeEdgePlane(int edgeBody, int planeBody, int edge0, int edge1);

	int computePlaneContact();
	int intersectRectQuad(Vector2& planeRect, Vector2 (&otherQuad)[4]);

	G3D::Array<ContactConnector*> connectors;  // exe: 0x34
	G3D::Array<bool> matched;                  // exe: 0x40

	int separatingAxisId; // 0x58
	int separatingBodyId; // 0x5c
	char exContactPad[0x10];                   // exe: feature at 0x64

	int feature[2]; // 0x60

	int bPlane; // 0x68
	int bOther; // 0x6c

	NormalId planeID;      // 0x70
	NormalId otherPlaneID; // 0x74
};

DECOMP_SIZE_ASSERT(BlockBlockContact, 0x78)

inline float BlockBlockContact::contactPairHitRatio()
{
	int denom = contactPairMatches + contactPairMisses;

	if (denom == 0) {
		return -1.0f;
	}

	return (float) contactPairMatches / denom;
}

// FUNCTION: WEBSERVICE 0x10107fd0
inline BallBallContact::BallBallContact(Primitive* p0, Primitive* p1) : Contact(p0, p1), ballBallConnector(NULL)
{
}

// FUNCTION: WEBSERVICE 0x10108000
inline void Contact::putInKernel(Kernel* _kernel)
{
	IPipelined::putInKernel(_kernel);

	onPrimitiveContactParametersChanged();
}

// FUNCTION: WEBSERVICE 0x10108020
inline void Contact::removeFromKernel()
{
	deleteAllConnectors();

	IPipelined::removeFromKernel();
}

// FUNCTION: WEBSERVICE 0x10108040 FOLDED
inline Edge::EdgeType Contact::getEdgeType() const
{
	return CONTACT;
}

// FUNCTION: WEBSERVICE 0x10108050 FOLDED
inline void BallBallContact::deleteAllConnectors()
{
	deleteConnector(ballBallConnector);
}

// FUNCTION: WEBSERVICE 0x10108050 FOLDED
inline void BallBlockContact::deleteAllConnectors()
{
	deleteConnector(ballBlockConnector);
}

// FUNCTION: WEBSERVICE 0x10108080
inline BallBlockContact::BallBlockContact(Primitive* p0, Primitive* p1) : Contact(p0, p1), ballBlockConnector(NULL)
{
}

// FUNCTION: WEBSERVICE 0x10108a30
inline BlockBlockContact::BlockBlockContact(Primitive* p0, Primitive* p1)
	: Contact(p0, p1), separatingAxisId(0), separatingBodyId(0)
{
	feature[0] = -1;
	feature[1] = -1;
}

} // namespace RBX

#endif // V8WORLD_CONTACT_H


#include "decomp.h"
#include "util/Math.h"
#include "util/StlExtra.h"
#include "v8kernel/Body.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"
#include "v8kernel/Kernel.h"
#include "v8world/Block.h"
#include "v8world/Primitive.h"

#include <algorithm>

namespace RBX {

int Contact::contactPairMatches;
int Contact::contactPairMisses;

// FUNCTION: WEBSERVICE 0x100d1fb0
Contact::Contact(Primitive* p0, Primitive* p1)
	: Edge(p0, p1), lastContactStep(-1), steppingIndex(-1), jointK(0), elasticJointK(0), kFriction(0)
{
}

// FUNCTION: WEBSERVICE 0x100d1fe0
bool Contact::step(int uiStepId)
{
	bool touching = stepContact();

	if (touching) {
		if (lastContactStep == -1) {
			Primitive::onNewTouch(getPrimitive(0), getPrimitive(1));
		}

		lastContactStep = uiStepId;
	}
	else {
		if (lastContactStep < uiStepId) {
			lastContactStep = -1;
		}
	}

	return touching;
}

// FUNCTION: WEBSERVICE 0x100d2030
bool Contact::computeIsAdjacent(float spaceAllowed)
{
	if (computeIsColliding(spaceAllowed)) {
		return false;
	}

	return computeIsColliding(-spaceAllowed);
}

// FUNCTION: WEBSERVICE 0x100d2070
void Contact::deleteConnector(ContactConnector*& c)
{
	if (c != NULL) {
		getKernel()->removeConnector(c);

		delete c;

		c = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x100d22b0
ContactConnector* Contact::createConnector()
{
	ContactConnector* connector = new ContactConnector(jointK, elasticJointK, kFriction);

	getKernel()->insertConnector(connector);

	return connector;
}

// FUNCTION: WEBSERVICE 0x100d2330
bool BallBallContact::computeIsColliding(float overlapIgnored)
{
	float r0 = getPrimitive(0)->getGeometry()->getRadius();
	float r1 = getPrimitive(1)->getGeometry()->getRadius();

	const Vector3& p0 = getPrimitive(0)->getBody()->getPV().position.translation;
	const Vector3& p1 = getPrimitive(1)->getBody()->getPV().position.translation;

	float dx = p1.x - p0.x;
	float dy = p1.y - p0.y;
	float dz = p1.z - p0.z;

	float radiusSum = r0 + r1;

	if (radiusSum > std::max(fabsf(dx), std::max(fabsf(dy), fabsf(dz)))) {
		return sqrtf(dx * dx + dy * dy + dz * dz) < radiusSum - overlapIgnored;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d2430
bool BallBallContact::stepContact()
{
	if (BallBallContact::computeIsColliding(0.0f)) {

		if (inKernel()) {

			if (ballBallConnector == NULL) {
				ballBallConnector = createConnector();
			}

			Ball* ball1 = ball(1);
			Ball* ball0 = ball(0);

			ContactConnector* connector = ballBallConnector;

			Body* body1 = getBody(1);
			Body* body0 = getBody(0);

			float radius0 = ball0->getRadius();
			float radius1 = ball1->getRadius();

			connector->setBallBall(body0, body1, radius0, radius0 + radius1);
		}

		return true;
	}

	deleteAllConnectors();

	return false;
}

// FUNCTION: WEBSERVICE 0x100d24c0
bool BallBlockContact::computeIsColliding(
	int& onBorder,
	G3D::Vector3int16& clip,
	Vector3& projectionInBlock,
	float overlapIgnored
)
{
	Primitive* p0 = getPrimitive(0);
	Primitive* p1 = getPrimitive(1);
	if (p0->fuzzyExtents.overlapsOrTouches(p1->fuzzyExtents)) {

		Body* ballBody = p0->getBody();
		Body* blockBody = p1->getBody();

		const PV& ballPV = ballBody->getPV();
		const PV& blockPV = blockBody->getPV();

		Vector3 blockToBall = ballPV.position.translation - blockPV.position.translation;

		projectionInBlock = blockPV.position.rotation.transpose() * blockToBall;

		((Block*) getPrimitive(1)->getGeometry())->projectToFace(projectionInBlock, clip, onBorder);

		Vector3 blockPtWorld = blockPV.position.pointToWorldSpace(projectionInBlock);

		return (blockPtWorld - ballPV.position.translation).magnitude() <
			   getPrimitive(0)->getGeometry()->getRadius() - overlapIgnored;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d25f0
bool BallBlockContact::stepContact()
{
	int onBorder;
	Vector3int16 clip;
	Vector3 projectionInBlock(0, 0, 0);

	if (computeIsColliding(onBorder, clip, projectionInBlock, 0.0f)) {

		if (inKernel()) {

			if (ballBlockConnector == NULL) {
				ballBlockConnector = createConnector();
			}

			const Vector3* offset;
			NormalId normalID;

			GeoPairType pairType = onBorder != 0 ? block()->getBallBlockInfo(onBorder, clip, offset, normalID)
												 : block()->getBallInsideInfo(projectionInBlock, offset, normalID);

			ballBlockConnector->setBallBlock(getBody(0), getBody(1), ball()->getRadius(), offset, normalID, pairType);
		}

		return true;
	}

	deleteAllConnectors();

	return false;
}

// STUB: WEBSERVICE 0x100d2710
bool BlockBlockContact::getBestPlaneEdge(bool& planeContact, float overlapIgnored)
{
	float bestPlaneLength = Math::inf();
	float bestEdgeLength = Math::inf();
	float lastPlaneLength = Math::inf();

	int lastFeature[2] = {feature[0], feature[1]};

	bool checkLastFeature = (lastFeature[0] >= 0 && lastFeature[0] < 6) || (lastFeature[1] >= 0 && lastFeature[1] < 6);

	for (int i = separatingBodyId; i < separatingBodyId + 2; i++) {

		int baseId = i % 2;
		int i1 = (i + 1) % 2;

		const CoordinateFrame& cBase = getBody(baseId)->getCoordinateFrame();
		const CoordinateFrame& cTest = getBody(i1)->getCoordinateFrame();

		const Vector3& eBase = block(baseId)->getExtent();
		const Vector3& eTest = block(i1)->getExtent();

		Vector3 pTestInBase = cBase.pointToObjectSpace(cTest.translation);

		for (int testId = separatingAxisId; testId < separatingAxisId + 3; testId++) {

			int j = testId % 3;

			Vector3 eBaseInTest = cBase.rotation.getColumn(j) * cTest.rotation;

			float length = fabsf(eBaseInTest.y * eTest.y) + fabsf(eBaseInTest.x * eTest.x) +
						   fabsf(eBaseInTest.z * eTest.z) + eBase[j] - fabsf(pTestInBase[j]);

			if (!(length > overlapIgnored)) {
				separatingBodyId = baseId;
				separatingAxisId = j;

				return false;
			}

			if (checkLastFeature) {
				if (lastFeature[baseId] % 3 == j) {
					lastPlaneLength = length;
				}
			}

			if (length < bestPlaneLength) {
				bestPlaneLength = length;

				feature[baseId] = pTestInBase[j] > 0 ? j : j + 3;
				feature[i1] = -1;

				separatingBodyId = baseId;
				separatingAxisId = j;

				planeContact = true;
			}
		}
	}

	if (checkLastFeature && (feature[0] != lastFeature[0] || feature[1] != lastFeature[1]) &&
		!(bestPlaneLength * 1.01f < lastPlaneLength)) {

		bestPlaneLength = lastPlaneLength;

		feature[0] = lastFeature[0];
		feature[1] = lastFeature[1];
	}

	const CoordinateFrame& c0 = getBody(0)->getCoordinateFrame();
	const CoordinateFrame& c1 = getBody(1)->getCoordinateFrame();

	const Vector3& extent0 = block(0)->getExtent();
	const Vector3& extent1 = block(1)->getExtent();

	Vector3 p0p1 = c1.translation - c0.translation;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			Vector3 crossAxis = c0.rotation.getColumn(i).cross(c1.rotation.getColumn(j));

			if (crossAxis.unitize() <= 0.001f) {
				return planeContact;
			}

			float p0p1inCrossAxis = p0p1.dot(crossAxis);

			Vector3 crossInBase = crossAxis * c0.rotation;
			Vector3 crossInTest = crossAxis * c1.rotation;

			float length = fabsf(crossInBase.x * extent0.x) + fabsf(crossInBase.y * extent0.y) +
						   fabsf(crossInBase.z * extent0.z) + fabsf(crossInTest.x * extent1.x) +
						   fabsf(crossInTest.y * extent1.y) + fabsf(crossInTest.z * extent1.z) - fabsf(p0p1inCrossAxis);

			if (!(length > overlapIgnored)) {
				return false;
			}

			if (length < bestEdgeLength) {
				bestEdgeLength = length;

				if (length * 10.0f < bestPlaneLength) {

					if (p0p1inCrossAxis > 0) {
						feature[0] = block(0)->getClosestEdge(c0.rotation, (NormalId) i, crossAxis) + 6;
						feature[1] = block(1)->getClosestEdge(c1.rotation, (NormalId) j, -crossAxis) + 6;
					}
					else {
						Vector3 negCrossAxis = -crossAxis;

						feature[0] = block(0)->getClosestEdge(c0.rotation, (NormalId) i, negCrossAxis) + 6;
						feature[1] = block(1)->getClosestEdge(c1.rotation, (NormalId) j, crossAxis) + 6;
					}

					planeContact = false;
				}
			}
		}
	}

	return true;
}

// FUNCTION: WEBSERVICE 0x100d2da0
void Contact::onPrimitiveContactParametersChanged()
{
	Primitive* prim0 = getPrimitive(0);
	Primitive* prim1 = getPrimitive(1);

	kFriction = std::min(prim0->getFriction(), prim1->getFriction());

	float elasticity = std::min(prim0->getElasticity(), prim1->getElasticity());

	jointK = std::min(prim0->getJointK(), prim1->getJointK());

	elasticJointK = Constants::getElasticMultiplier(elasticity) * jointK;
}

// FUNCTION: WEBSERVICE 0x100d2ea0
bool BallBlockContact::computeIsColliding(float overlapIgnored)
{
	int onBorder;
	Vector3int16 clip(0, 0, 0);
	Vector3 projectionInBlock(0, 0, 0);

	return computeIsColliding(onBorder, clip, projectionInBlock, overlapIgnored);
}

// FUNCTION: WEBSERVICE 0x100d2ef0
bool BlockBlockContact::computeIsColliding(float overlapIgnored)
{
	if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1))) {

		bool temp;

		return getBestPlaneEdge(temp, overlapIgnored);
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100d4150
void BlockBlockContact::deleteAllConnectors()
{
	for (unsigned int i = 0; i < connectors.size(); i++) {
		deleteConnector(connectors[i]);
	}

	connectors.resize(0);
	matched.resize(0);
}

// FUNCTION: WEBSERVICE 0x100d41e0
void BlockBlockContact::deleteUnmatchedConnectors()
{
	for (int i = connectors.size() - 1; i >= 0; i--) {

		if (!matched[i]) {

			ContactConnector* c = connectors[i];

			connectors.fastRemove(i);
			matched.fastRemove(i);

			deleteConnector(c);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d42f0
ContactConnector* BlockBlockContact::matchContactConnector(
	Body* b0,
	Body* b1,
	GeoPairType _pairType,
	int param0,
	int param1
)
{
	for (unsigned int i = 0; (int)i < matched.size(); i++) {

		if (!matched[i]) {

			if (connectors[i]->match(b0, b1, _pairType, param0, param1)) {

				matched[i] = true;

				contactPairMatches++;

				connectors[i]->geoPair.body0 = b0;
				connectors[i]->geoPair.body1 = b1;

				return connectors[i];
			}
		}
	}

	contactPairMisses++;

	ContactConnector* c = createConnector(b0, b1);

	connectors.append(c);
	matched.append(true);

	return c;
}

// FUNCTION: WEBSERVICE 0x100d44e0
void BlockBlockContact::loadGeoPairEdgeEdge(int b0, int b1, int edge0, int edge1)
{
	NormalId normalID0 = block(b0)->getEdgeNormal(edge0);
	NormalId normalID1 = block(b1)->getEdgeNormal(edge1);

	ContactConnector* c = matchContactConnector(getBody(b0), getBody(b1), EDGE_EDGE_PAIR, normalID0, normalID1);

	c->setEdgeEdge(
		getBody(b0),
		getBody(b1),
		block(b0)->getEdgeVertex(edge0),
		block(b1)->getEdgeVertex(edge1),
		normalID0,
		normalID1
	);
}

// FUNCTION: WEBSERVICE 0x100d45e0
void BlockBlockContact::loadGeoPairPointPlane(
	int pointBody,
	int planeBody,
	int pointID,
	NormalId pointFaceID,
	NormalId planeFaceID
)
{
	ContactConnector* c =
		matchContactConnector(getBody(pointBody), getBody(planeBody), POINT_PLANE_PAIR, pointID, planeFaceID);

	c->setPointPlane(
		getBody(pointBody),
		getBody(planeBody),
		block(pointBody)->getFaceVertex(pointFaceID, pointID),
		block(planeBody)->getFaceVertex(planeFaceID, 0),
		pointID,
		planeFaceID
	);
}

// FUNCTION: WEBSERVICE 0x100d4680
void BlockBlockContact::loadGeoPairEdgeEdgePlane(int edgeBody, int planeBody, int edge0, int edge1)
{
	NormalId normalID0 = block(edgeBody)->getEdgeNormal(edge0);
	NormalId normalID1 = block(planeBody)->getEdgeNormal(edge1);

	ContactConnector* c =
		matchContactConnector(getBody(edgeBody), getBody(planeBody), EDGE_EDGE_PLANE_PAIR, normalID0, normalID1);

	c->setEdgeEdgePlane(
		getBody(edgeBody),
		getBody(planeBody),
		block(edgeBody)->getEdgeVertex(edge0),
		block(planeBody)->getEdgeVertex(edge1),
		normalID0,
		normalID1,
		planeID,
		block(edgeBody)->getGridSize()[normalID0 % 3]
	);
}

// FUNCTION: WEBSERVICE 0x100d47b0
int BlockBlockContact::intersectRectQuad(Vector2& planeRect, Vector2 (&otherQuad)[4])
{
	bool rectCrossQuad[4][4];

	int found;

	bool quadIn[4] = {true, true, true, true};

	found = 0;

	for (int i = 3; i >= 0; i--) {

		if (otherQuad[i].y <= planeRect.y) {
			rectCrossQuad[0][i] = true;
		}
		else {
			rectCrossQuad[0][i] = false;
			quadIn[i] = false;
		}

		if (otherQuad[i].x >= -planeRect.x) {
			rectCrossQuad[1][i] = true;
		}
		else {
			rectCrossQuad[1][i] = false;
			quadIn[i] = false;
		}

		if (otherQuad[i].y >= -planeRect.y) {
			rectCrossQuad[2][i] = true;
		}
		else {
			rectCrossQuad[2][i] = false;
			quadIn[i] = false;
		}

		if (otherQuad[i].x <= planeRect.x) {
			rectCrossQuad[3][i] = true;
		}
		else {
			rectCrossQuad[3][i] = false;
			quadIn[i] = false;
		}
	}

	for (int i = 3; i >= 0; i--) {
		if (quadIn[i]) {
			loadGeoPairPointPlane(bOther, bPlane, i, otherPlaneID, planeID);

			found++;
		}
	}

	if (found == 4) {
		return 4;
	}

	bool quadCrossRect[4][4];
	bool rectIn[4] = {true, true, true, true};

	Vector2 rect[4];

	rect[0] = Vector2(planeRect.x, planeRect.y);
	rect[1] = Vector2(-planeRect.x, planeRect.y);
	rect[2] = Vector2(-planeRect.x, -planeRect.y);
	rect[3] = Vector2(planeRect.x, -planeRect.y);

	for (int i = 3; i >= 0; i--) {

		Vector2 quadEdge = otherQuad[(i + 3) % 4] - otherQuad[i];

		for (int j = 0; j < 4; j++) {

			Vector2 rectToQuad = rect[j] - otherQuad[i];

			if (rectToQuad.y * quadEdge.x - quadEdge.y * rectToQuad.x >= 0.0f) {
				quadCrossRect[i][j] = true;
			}
			else {
				quadCrossRect[i][j] = false;
				rectIn[j] = false;
			}
		}
	}

	int noneFound = found == 0;

	for (int j = 0; j < 4; j++) {
		if (rectIn[j]) {
			loadGeoPairPointPlane(bPlane, bOther, j, planeID, otherPlaneID);

			found++;
		}
	}

	if (noneFound && found == 4) {
		return found;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 0; j--) {

			if (rectCrossQuad[i][j] != rectCrossQuad[i][(j + 3) % 4]) {

				if (quadCrossRect[j][i] != quadCrossRect[j][(i + 1) % 4]) {

					loadGeoPairEdgeEdgePlane(
						bOther,
						bPlane,
						block(bOther)->faceVertexToEdge(otherPlaneID, (j + 3) % 4),
						block(bPlane)->faceVertexToEdge(planeID, i)
					);

					found++;
				}
			}
		}
	}

	return found;
}

// STUB: WEBSERVICE 0x100d4be0
int BlockBlockContact::computePlaneContact()
{
	if (feature[0] >= 0) {
		planeID = (NormalId) feature[0];
		bPlane = 0;
		bOther = 1;
	}
	else {
		planeID = (NormalId) feature[1];
		bPlane = 1;
		bOther = 0;
	}

	const CoordinateFrame& otherCoord = getBody(bOther)->getCoordinateFrame();
	const CoordinateFrame& planeCoord = getBody(bPlane)->getCoordinateFrame();

	CoordinateFrame otherToPlane = planeCoord.inverse() * otherCoord;

	Block& otherBlock = *block(bOther);
	Block& planeBlock = *block(bPlane);

	int planeFlip = planeID / 3;
	int planeAxis = planeID - 3 * planeFlip;

	otherPlaneID = Math::getClosestObjectNormalId(
		-(Vector3(
			  planeCoord.rotation[0][planeAxis],
			  planeCoord.rotation[1][planeAxis],
			  planeCoord.rotation[2][planeAxis]
		  ) *
		  (float) (1 - 2 * planeFlip)),
		otherCoord.rotation
	);

	Vector2 planeRect = planeBlock.getProjectedVertex(*planeBlock.getFaceVertex(planeID, 0), planeID);

	Vector2 otherQuad[4];

	for (int i = 0; i < 4; i++) {
		const Vector3& otherVertex = *otherBlock.getFaceVertex(otherPlaneID, i);

		Vector3 otherVertexPlaneCoords = otherToPlane.pointToWorldSpace(otherVertex);

		otherQuad[i] = otherBlock.getProjectedVertex(otherVertexPlaneCoords, planeID);
	}

	return intersectRectQuad(planeRect, otherQuad);
}

// FUNCTION: WEBSERVICE 0x100d4df0
bool BlockBlockContact::stepContact()
{
	bool planeContact;

	if (Primitive::aaBoxCollide(*getPrimitive(0), *getPrimitive(1)) && getBestPlaneEdge(planeContact, 0.0f)) {

		if (inKernel()) {

			matched.resize(0);
			matched.resize(connectors.size());

			if (planeContact) {
				computePlaneContact();
			}
			else {
				loadGeoPairEdgeEdge(0, 1, feature[0] - 6, feature[1] - 6);
			}

			deleteUnmatchedConnectors();
		}

		return true;
	}

	deleteAllConnectors();

	feature[0] = -1;
	feature[1] = -1;

	return false;
}

} // namespace RBX


