// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Primitive.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Primitive.h"

#include "decomp.h"
#include "util/Face.h"
#include "util/Velocity.h"
#include "v8kernel/Body.h"
#include "v8kernel/Constants.h"
#include "v8world/Anchor.h"
#include "v8world/Assembly2.h"
#include "v8world/Ball.h"
#include "v8world/Block.h"
#include "v8world/Contact.h"
#include "v8world/Controller.h"
#include "v8world/Geometry.h"
#include "v8world/IMoving.h"
#include "v8world/Joint.h"
#include "v8world/RigidJoint.h"
#include "v8world/World.h"

#include <cmath>
#include <cstddef>

namespace RBX {

// GLOBAL: WEBSERVICE 0x102f9959
// GLOBAL: ROBLOX 0x0095f4e5
bool Primitive::disableSleep = false;

// FUNCTION: WEBSERVICE 0x100a77d0
// FUNCTION: ROBLOX 0x005f6090
void Primitive::setSizeMultiplier(unsigned int value)
{
	if (value != sizeMultiplier && world == NULL) {
		sizeMultiplier = value;
	}
}

// FUNCTION: WEBSERVICE 0x100a77f0
// FUNCTION: ROBLOX 0x006bb570
const Guid& Primitive::getGuid() const
{
	return guid;
}

// FUNCTION: WEBSERVICE 0x100a7800
// FUNCTION: ROBLOX 0x005f60b0
void Primitive::setGuid(const Guid& value)
{
	guid.copyDataFrom(value);
	guidSetExternally = true;
}

// FUNCTION: WEBSERVICE 0x100a7820
// FUNCTION: ROBLOX 0x005f60d0
Primitive* Primitive::downstreamPrimitive(Joint* j)
{
	Primitive* answer = j->getPrimitive(0);
	Primitive* other = j->getPrimitive(1);

	if (other != NULL && answer->clumpDepth <= other->clumpDepth) {
		answer = other;
	}

	return answer;
}

void EdgeList::insertEdge(Primitive* primitive, Edge* edge, EdgeList& list)
{
	Edge* first = list.first;

	edge->setNext(primitive, first);
	list.first = edge;
	list.num++;
}

// FUNCTION: WEBSERVICE 0x100a7840
// FUNCTION: ROBLOX 0x005f60f0
void EdgeList::removeEdge(Primitive* p, Edge* e, EdgeList& list)
{
	Edge* previous = list.first;

	if (previous == e) {
		list.first = e->getNext(p);
	}
	else {
		while (previous->getNext(p) != e) {
			previous = previous->getNext(p);
		}

		previous->setNext(p, e->getNext(p));
	}

	list.num--;
}

// FUNCTION: WEBSERVICE 0x100a78c0
// FUNCTION: ROBLOX 0x005f6170
void Primitive::insertEdge(Edge* e)
{
	Primitive* prim0 = e->getPrimitive(0);
	Primitive* prim1 = e->getPrimitive(1);

	if (e->getEdgeType() == Edge::JOINT) {
		EdgeList::insertEdge(prim0, e, e->getPrimitive(0)->joints);

		if (prim1 != NULL) {
			EdgeList::insertEdge(prim1, e, e->getPrimitive(1)->joints);
		}
	}
	else {
		EdgeList::insertEdge(prim0, e, e->getPrimitive(0)->contacts);
		EdgeList::insertEdge(prim1, e, e->getPrimitive(1)->contacts);
	}
}

// FUNCTION: WEBSERVICE 0x100a7960
// FUNCTION: ROBLOX 0x005f6210
void Primitive::removeEdge(Edge* e)
{
	Primitive* prim0 = e->getPrimitive(0);
	Primitive* prim1 = e->getPrimitive(1);

	if (e->getEdgeType() == Edge::JOINT) {
		EdgeList::removeEdge(prim0, e, e->getPrimitive(0)->joints);

		if (prim1 != NULL) {
			EdgeList::removeEdge(prim1, e, e->getPrimitive(1)->joints);
		}
	}
	else {
		EdgeList::removeEdge(prim0, e, e->getPrimitive(0)->contacts);
		EdgeList::removeEdge(prim1, e, e->getPrimitive(1)->contacts);
	}
}

// FUNCTION: WEBSERVICE 0x100a79d0
// FUNCTION: ROBLOX 0x005f6280
Edge* Primitive::getFirstEdge() const
{
	Edge* edge = joints.first;

	if (edge == NULL) {
		edge = contacts.first;
	}

	return edge;
}

// FUNCTION: WEBSERVICE 0x100a79e0
// FUNCTION: ROBLOX 0x005f6290
Edge* Primitive::getNextEdge(Edge* e) const
{
	Edge* next = e->getNext(this);

	if (next != NULL) {
		return next;
	}

	if (e->getEdgeType() == Edge::JOINT) {
		return contacts.first;
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a7a10
// FUNCTION: ROBLOX 0x005f62c0
void Primitive::onNewTouch(Primitive* p0, Primitive* p1)
{
	Clump* clump0 = p0->clump;
	Clump* clump1 = p1->clump;

	if (p0->myOwner->reportTouches()) {
		if (clump0->getSleepStatus() == Sim::AWAKE || clump1->getSleepStatus() == Sim::AWAKE) {
			p0->world->onPrimitiveTouched(p0, p1);
		}
	}

	clump0 = p1->clump;
	clump1 = p0->clump;

	if (p1->myOwner->reportTouches()) {
		if (clump0->getSleepStatus() == Sim::AWAKE || clump1->getSleepStatus() == Sim::AWAKE) {
			p1->world->onPrimitiveTouched(p1, p0);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a7a90
// FUNCTION: ROBLOX 0x005f6340
void Primitive::setClump(Clump* set)
{
	if (set != clump) {
		clump = set;
	}
}

// FUNCTION: WEBSERVICE 0x100a7aa0
// FUNCTION: ROBLOX 0x005f6350
Assembly* Primitive::getAssembly() const
{
	if (clump != NULL) {
		return clump->getRootAssembly();
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a7ab0
// FUNCTION: ROBLOX 0x005f6360
float Primitive::computeJointK() const
{
	return Constants::getJointK(getGridSize(), getPrimitiveType() == Geometry::GEOMETRY_BALL);
}

// FUNCTION: WEBSERVICE 0x100a7ae0
// FUNCTION: ROBLOX 0x005f6390
void Primitive::setCanSleep(bool _canSleep)
{
	if (_canSleep != canSleep) {
		canSleep = _canSleep;

		if (world != NULL) {
			world->onPrimitiveCanSleepChanged(this);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a7b10
// FUNCTION: ROBLOX 0x005f63c0
void Primitive::setCanCollide(bool _canCollide)
{
	bool wasCollideable = !dragging && canCollide;

	if (canCollide != _canCollide) {
		canCollide = _canCollide;

		if (world != NULL) {
			bool isCollideable = !dragging && canCollide;

			if (wasCollideable != isCollideable) {
				world->onPrimitiveCanCollideChanged(this);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a7b70
// FUNCTION: ROBLOX 0x005f6420
void Primitive::setFriction(float _friction)
{
	if (_friction != friction) {
		friction = _friction;

		if (world != NULL) {
			world->onPrimitiveContactParametersChanged(this);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a7bb0
// FUNCTION: ROBLOX 0x005f6460
void Primitive::setElasticity(float _elasticity)
{
	if (_elasticity != elasticity) {
		elasticity = _elasticity;

		if (world != NULL) {
			world->onPrimitiveContactParametersChanged(this);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a7bf0
// FUNCTION: ROBLOX 0x005f64a0
CoordinateFrame Primitive::getFaceCoordInObject(NormalId objectFace)
{
	return CoordinateFrame(normalIdToMatrix3(objectFace), normalIdToVector3(objectFace) * geometry->getGridSize());
}

// FUNCTION: WEBSERVICE 0x100a7c60
// FUNCTION: ROBLOX 0x005f6510
Face Primitive::getFaceInObject(NormalId objectFace)
{
	Vector3 half = geometry->getGridSize() * 0.5f;

	return Face::fromExtentsSide(Extents(-half, half), objectFace);
}

// FUNCTION: WEBSERVICE 0x100a7cd0
// FUNCTION: ROBLOX 0x005f6580
void Primitive::setVelocity(const Velocity& vel)
{
	body->setVelocity(vel);
}

// FUNCTION: WEBSERVICE 0x100a7ce0
// FUNCTION: ROBLOX 0x005f6590
void Primitive::setSurfaceData(NormalId id, const SurfaceData& newSurfaceData)
{
	if (surfaceData[id] == NULL && newSurfaceData.isEmpty()) {
		return;
	}

	if (surfaceData[id] != NULL && *surfaceData[id] == newSurfaceData) {
		return;
	}

	if (newSurfaceData.isEmpty()) {
		delete surfaceData[id];
		surfaceData[id] = NULL;
	}
	else {
		if (surfaceData[id] == NULL) {
			surfaceData[id] = new SurfaceData();
		}

		*surfaceData[id] = newSurfaceData;
	}
}

// FUNCTION: WEBSERVICE 0x100a7dc0
// FUNCTION: ROBLOX 0x005f6670
void Primitive::setSurfaceType(NormalId id, SurfaceType newSurfaceType)
{
	if (this->surfaceType[id] != newSurfaceType) {
		this->surfaceType[id] = newSurfaceType;
	}
}

// FUNCTION: WEBSERVICE 0x100a7e80
// FUNCTION: ROBLOX 0x005f6730
Extents Primitive::computeFuzzyExtents() const
{
	const Matrix3& rotation = body->getCoordinateFrame().rotation;
	const Vector3& translation = body->getCoordinateFrame().translation;

	Extents extents = Extents::fromCenterCorner(translation, geometry->getCenterToCorner(rotation));
	extents.expand(0.01f);

	return extents;
}

// FUNCTION: WEBSERVICE 0x100a7f40
// FUNCTION: ROBLOX 0x005f67f0
const Extents& Primitive::getFastFuzzyExtents() const
{
	if (fuzzyExtentsStateId != body->getStateIndex()) {
		fuzzyExtents = computeFuzzyExtents();
		fuzzyExtentsStateId = body->getStateIndex();
	}

	return fuzzyExtents;
}

// FUNCTION: WEBSERVICE 0x100a7fb0 FOLDED
// FUNCTION: ROBLOX 0x005f6860 FOLDED
Joint* Primitive::getFirstJoint() const
{
	return static_cast<Joint*>(joints.first);
}

// FUNCTION: WEBSERVICE 0x100a7fc0
// FUNCTION: ROBLOX 0x005f6870
Contact* Primitive::getFirstContact()
{
	return static_cast<Contact*>(contacts.first);
}

// FUNCTION: WEBSERVICE 0x100a7fd0 FOLDED
// FUNCTION: ROBLOX 0x005f6880 FOLDED
Contact* Primitive::getNextContact(Contact* prev)
{
	return static_cast<Contact*>(prev->getNext(this));
}

// FUNCTION: WEBSERVICE 0x100a7fd0 FOLDED
// FUNCTION: ROBLOX 0x005f6880 FOLDED
Joint* Primitive::getNextJoint(Joint* prev) const
{
	return static_cast<Joint*>(prev->getNext(this));
}

// FUNCTION: WEBSERVICE 0x100a7ff0
// FUNCTION: ROBLOX 0x005f68a0
RigidJoint* Primitive::getFirstRigidAt(Edge* start)
{
	while (start != NULL) {
		if (RigidJoint::isRigidJoint(start)) {
			return static_cast<RigidJoint*>(start);
		}

		start = getNextEdge(start);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a8060
// FUNCTION: ROBLOX 0x005f6910
RigidJoint* Primitive::getFirstRigid()
{
	return getFirstRigidAt(getFirstEdge());
}

// FUNCTION: WEBSERVICE 0x100a8080
// FUNCTION: ROBLOX 0x005f6930
RigidJoint* Primitive::getNextRigid(RigidJoint* prev)
{
	return getFirstRigidAt(getNextEdge(prev));
}

// FUNCTION: WEBSERVICE 0x100a80c0
// FUNCTION: ROBLOX 0x005f6970
Joint* Primitive::getJoint(Primitive* p0, Primitive* p1)
{
	Primitive* shortest = p0->joints.num < p1->joints.num ? p0 : p1;

	for (Joint* joint = shortest->getFirstJoint(); joint != NULL; joint = shortest->getNextJoint(joint)) {
		if ((p0 == joint->getPrimitive(0) && p1 == joint->getPrimitive(1)) ||
			(p0 == joint->getPrimitive(1) && p1 == joint->getPrimitive(0))) {
			return joint;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a8110
// FUNCTION: ROBLOX 0x005f69c0
Contact* Primitive::getContact(Primitive* p0, Primitive* p1)
{
	Primitive* shortest = p0->contacts.num < p1->contacts.num ? p0 : p1;

	for (Contact* contact = shortest->getFirstContact(); contact != NULL; contact = shortest->getNextContact(contact)) {
		if ((p0 == contact->getPrimitive(0) && p1 == contact->getPrimitive(1)) ||
			(p0 == contact->getPrimitive(1) && p1 == contact->getPrimitive(0))) {
			return contact;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100a8160
// FUNCTION: ROBLOX 0x005f6a10
Geometry* Primitive::newGeometry(Geometry::GeometryType geometryType)
{
	switch (geometryType) {
	case Geometry::GEOMETRY_BALL:
		return new Ball();
	case Geometry::GEOMETRY_BLOCK:
		return new Block();
	default:
		return Geometry::nullGeometry();
	}
}

// FUNCTION: WEBSERVICE 0x100a81d0
// FUNCTION: ROBLOX 0x005f6a80
Primitive::~Primitive()
{
	if (geometry->getGeometryType() != Geometry::GEOMETRY_NONE) {
		delete geometry;
		delete body;
	}

	for (int i = 0; i < 6; i++) {
		delete surfaceData[i];
	}
}

// FUNCTION: WEBSERVICE 0x100a8250
// FUNCTION: ROBLOX 0x005f6b00
bool Primitive::hitTest(const Ray& worldRay, Vector3& worldHitPoint, bool& inside)
{
	Ray localRay = body->getCoordinateFrame().toObjectSpace(worldRay);
	Vector3 localHitPoint;

	if (geometry->hitTest(localRay, localHitPoint, inside)) {
		worldHitPoint = body->getCoordinateFrame().pointToWorldSpace(localHitPoint);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100a8320
// FUNCTION: ROBLOX 0x005f6bd0
void Primitive::setAnchor(bool _anchored)
{
	bool have = anchorObject != NULL;

	anchored = _anchored;

	bool wanted = _anchored || dragging;

	if (wanted != have) {
		if (wanted) {
			anchorObject = new Anchor(this);

			if (world != NULL) {
				world->onPrimitiveAddedAnchor(this);
			}
		}
		else {
			delete anchorObject;
			anchorObject = NULL;

			if (world != NULL) {
				world->onPrimitiveRemovedAnchor(this);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a83b0
// FUNCTION: ROBLOX 0x005f6c60
Face Primitive::getFaceInWorld(NormalId objectFace)
{
	return getFaceInObject(objectFace).toWorldSpace(body->getCoordinateFrame());
}

// FUNCTION: WEBSERVICE 0x100a83f0
// FUNCTION: ROBLOX 0x005f6ca0
void Primitive::setCoordinateFrame(const CoordinateFrame& cFrame)
{
	if (cFrame != body->getCoordinateFrame()) {
		Assembly* assembly = getAssembly();

		if (assembly == NULL) {
			body->setCoordinateFrame(cFrame);
			myOwner->notifyMoved();

			if (world != NULL) {
				world->onPrimitiveExtentsChanged(this);
			}
		}
		else if (assembly->getAssemblyPrimitive() == this) {
			body->setCoordinateFrame(cFrame);
			assembly->notifyMoved();
			world->onAssemblyExtentsChanged(assembly);

			if (!anchored) {
				world->ticklePrimitive(this, false);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a8490
// FUNCTION: ROBLOX 0x005f6d40
const CoordinateFrame& Primitive::getCoordinateFrame() const
{
	return body->getCoordinateFrame();
}

// FUNCTION: WEBSERVICE 0x100a84b0
// FUNCTION: ROBLOX 0x005f6d60
CoordinateFrame Primitive::getGridCorner() const
{
	const CoordinateFrame& gridCorner = body->getCoordinateFrame();

	return CoordinateFrame(gridCorner.rotation, gridCorner.pointToWorldSpace(-(geometry->getGridSize() * 0.5f)));
}

// FUNCTION: WEBSERVICE 0x100a8570
// FUNCTION: ROBLOX 0x005f6e20
Primitive::Primitive(Geometry::GeometryType geometryType)
	: guidSetExternally(false), sizeMultiplier(1), worldIndex(-1), world(NULL), clump(NULL), clumpDepth(-1),
	  traverseId(-1), spatialNodes(NULL), oldSpatialMin(), oldSpatialMax(), fuzzyExtents(), fuzzyExtentsStateId(-2),
	  geometry(newGeometry(geometryType)), body(new Body()), myOwner(NULL), anchorObject(NULL), dragging(false),
	  anchored(false), canCollide(true), canSleep(true), friction(0), elasticity(0.75f),
	  controller(NullController::getStaticNullController()), JointK(this, &Primitive::computeJointK)
{
	for (int i = 0; i < 6; i++) {
		surfaceType[i] = NO_SURFACE;
		surfaceData[i] = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x100a8760
// FUNCTION: ROBLOX 0x005f7010
Vector3 Primitive::clipToSafeSize(const Vector3& newSize)
{
	Vector3 answer = newSize.min(Vector3(512.0f, 512.0f, 512.0f));

	if (answer.x * answer.y * answer.z > 1000000.0f) {
		answer.y = floor(1000000.0f / (answer.x * answer.z));
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x100a8810
// FUNCTION: ROBLOX 0x005f70c0
void Primitive::setGridSize(const Vector3& gridSize)
{
	Vector3 protectedSize = clipToSafeSize(gridSize);

	if (protectedSize != geometry->getGridSize()) {
		fuzzyExtentsStateId = -2;
		geometry->setGridSize(protectedSize);

		float volume = geometry->getGridVolume();
		body->setMass(volume);
		body->setMoment(geometry->getMoment(volume));

		JointK.setDirty();

		if (world != NULL) {
			world->onPrimitiveExtentsChanged(this);
		}

		JointK.setDirty();
	}
}

// FUNCTION: WEBSERVICE 0x100a88d0
// FUNCTION: ROBLOX 0x005f7180
void Primitive::setDragging(bool _dragging)
{
	if (dragging != _dragging) {
		bool wasCollideable = !dragging && canCollide;

		dragging = _dragging;
		setAnchor(anchored);

		if (world != NULL) {
			bool isCollideable = !dragging && canCollide;

			if (isCollideable != wasCollideable) {
				world->onPrimitiveCanCollideChanged(this);
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100a8940
// FUNCTION: ROBLOX 0x005f71f0
void Primitive::setGridCorner(const CoordinateFrame& gridCorner)
{
	Vector3 gridCenter = geometry->getGridSize() * 0.5f;

	setCoordinateFrame(CoordinateFrame(gridCorner.rotation, gridCorner.pointToWorldSpace(gridCenter)));
}

// FUNCTION: ROBLOX 0x005f72a0
void Primitive::setPV(const PV& pv)
{
	body->setVelocity(pv.velocity);
	setCoordinateFrame(pv.position);
}

// FUNCTION: WEBSERVICE 0x100a89f0
// FUNCTION: ROBLOX 0x005f72d0
void Primitive::setController(Controller* _controller)
{
	if (_controller == NULL) {
		_controller = NullController::getStaticNullController();
	}

	if (controller != _controller) {
		controller = _controller;
	}
}

// FUNCTION: WEBSERVICE 0x100a8a20
// FUNCTION: ROBLOX 0x005f7300
void Primitive::setPrimitiveType(Geometry::GeometryType geometryType)
{
	if (geometry->getGeometryType() != geometryType) {
		Vector3 oldSize = geometry->getGridSize();

		delete geometry;
		geometry = newGeometry(geometryType);

		if (world != NULL) {
			world->onPrimitiveGeometryTypeChanged(this);
		}

		setGridSize(oldSize);
		JointK.setDirty();
	}
}

} // namespace RBX
