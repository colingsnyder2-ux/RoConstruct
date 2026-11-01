#pragma float_control(precise, off)
#include "v8world/Primitive.h"
#include "v8world/Geometry.h"
#include "v8world/Assembly.h"
#include "v8world/Ball.h"
#include "v8world/Block.h"
#include "v8world/World.h"
#include <cmath>

namespace RBX 
{
	bool Primitive::ignoreBool = false;
	bool Primitive::disableSleep = false;

	#pragma warning (push)
	#pragma warning (disable : 4355) // warning C4355: 'this' : used in base member initializer list
	Primitive::Primitive(Geometry::GeometryType geometryType) :
		guidSetExternally(false),
		world(NULL),
		clump(NULL),
		spatialNodes(NULL),
		unknown0x14(1),
		contacts(this),
		joints(this),
		worldIndex(-1),
		clumpDepth(-1),
		traverseId(-1),
		fuzzyExtentsStateId(-2),
		geometry(newGeometry(geometryType)),
		body(new Body),
		elasticity(0.75f),
		friction(0.0f),
		myOwner(NULL),
		dragging(false),
		anchored(false),
		flag0xaa(false),
		canCollide(true),
		canSleep(false),
		JointK(this, &Primitive::computeJointK),
		controller(NullController::getStaticNullController())
	{
		for (int i = 0; i < 6; i++) 
		{
			surfaceType[i] = NO_SURFACE;
			surfaceData[i] = NULL;
		}
	}
	#pragma warning (pop)

	Primitive::~Primitive()
	{
		Geometry::GeometryType type = geometry->getGeometryType();

		if (type != Geometry::GEOMETRY_NONE) {
			delete geometry;
			delete body;
		}

		for (int i = 0; i < 6; i++)
			delete surfaceData[i];

	}

	G3D::Vector3 Primitive::clipToSafeSize(const G3D::Vector3& newSize)
	{
		G3D::Vector3 r = newSize.min(G3D::Vector3(512.0f, 512.0f, 512.0f));

		if (r.x * r.y * r.z > 1e+6f) 
		{
			r.y = floorf(1e+6f / (r.x * r.z));
		}

		return r;
	}

	float Primitive::computeJointK() const 
	{
		Geometry::GeometryType type = geometry->getGeometryType();
		return Constants::getJointK(geometry->getGridSize(), type == Geometry::GEOMETRY_BALL);
	}

	void Primitive::setGuid(const Guid& value) 
	{
		                 ;
		guid.copyDataFrom(value);
		guidSetExternally = true;
	}

	void Primitive::setClump(Clump* set)
	{
		if (set != clump)
		{
			clump = set;
		}
	}

	const G3D::CoordinateFrame& Primitive::getCoordinateFrame() const
	{
		return body->getPV().position;
	}
	
	G3D::CoordinateFrame Primitive::getGridCorner() const
	{
		const G3D::CoordinateFrame& pos = body->getPV().position;
		G3D::Vector3 hVec = -(geometry->getGridSize() * 0.5f);

		return G3D::CoordinateFrame(pos.rotation, pos.pointToWorldSpace(hVec));
	}

	void Primitive::setGridCorner(const G3D::CoordinateFrame& gridCorner)
	{
		G3D::Vector3 hVec = geometry->getGridSize() * 0.5;
		setCoordinateFrame(G3D::CoordinateFrame(gridCorner.rotation, gridCorner.pointToWorldSpace(hVec)));
	}

	void Primitive::setVelocity(const Velocity& vel)
	{
		body->setVelocity(vel);
	}

	float Primitive::getPlanarSize() const
	{
		return Math::planarSize(geometry->getGridSize());
	}

	bool Primitive::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint, bool& inside) 
	{
		G3D::Ray localRay = body->getPV().position.toObjectSpace(worldRay);
		G3D::Vector3 localHitPoint;

		if (geometry->hitTest(localRay, localHitPoint, inside))
		{
			worldHitPoint = body->getPV().position.pointToWorldSpace(localHitPoint);
			return true;
		}
		else return false;
	}

	Face Primitive::getFaceInObject(NormalId objectFace)
	{
		return Face::fromExtentsSide(getExtentsLocal(), objectFace);
	}

	Face Primitive::getFaceInWorld(NormalId objectFace)
	{
		return getFaceInObject(objectFace).toWorldSpace(body->getPV().position);
	}

	G3D::CoordinateFrame Primitive::getFaceCoordInObject(NormalId objectFace)
	{
		return G3D::CoordinateFrame(normalIdToMatrix3(objectFace), normalIdToVector3(objectFace) * geometry->getGridSize());
	}

	void Primitive::setSurfaceType(NormalId id, SurfaceType newSurfaceType)
	{
		if (surfaceType[id] != newSurfaceType)
			surfaceType[id] = newSurfaceType;
	}

	void Primitive::setSurfaceData(NormalId id, const SurfaceData& newSurfaceData)
	{
		if (!surfaceData[id] && newSurfaceData.isEmpty())
			return;

		if (surfaceData[id] && *surfaceData[id] == newSurfaceData)
			return;

		if (newSurfaceData.isEmpty())
		{
			                          ;
			delete surfaceData[id];
			surfaceData[id] = NULL;
			return;
		}
		else if (!surfaceData[id])
		{
			surfaceData[id] = new SurfaceData;
		}

		*surfaceData[id] = newSurfaceData;
	}

	Edge* Primitive::getFirstEdge() const
	{
		return joints.edges.size() ? joints.first() : contacts.first();
	}

	Joint* Primitive::getFirstJoint() const
	{
		return rbx_static_cast<Joint*>(joints.first());
	}

	Contact* Primitive::getFirstContact()
	{
		return rbx_static_cast<Contact*>(contacts.first());
	}

	RigidJoint* Primitive::getFirstRigid()
	{
		return getFirstRigidAt(joints.first());
	}

	RigidJoint* Primitive::getNextRigid(RigidJoint* prev)
	{
		return getFirstRigidAt(getNextEdge(prev));
	}

	Geometry* Primitive::newGeometry(Geometry::GeometryType geometryType)
	{
		switch (geometryType)
		{
			case Geometry::GEOMETRY_BLOCK: return new Block;
			case Geometry::GEOMETRY_BALL: return new Ball;
			default: return Geometry::nullGeometry();
		}
	}

	void newTouch(Primitive* touch, Primitive* touchOther)
	{
		Clump* clumpTouch = touch->getClump();
		Clump* clumpOTouch = touchOther->getClump();

		RBXASSERT(clumpTouch);
		RBXASSERT(clumpOTouch);

		if (touch->getOwner()->reportTouches() && 
			((!clumpTouch->getAnchored() && clumpTouch->getSleepStatus() == Sim::AWAKE) ||
			(!clumpOTouch->getAnchored() && clumpOTouch->getSleepStatus() == Sim::AWAKE)))
		{
			touch->getWorld()->onPrimitiveTouched(touch, touchOther);
		}
	};

	void Primitive::onNewTouch(Primitive* p0, Primitive* p1)
	{
		newTouch(p0, p1);
		newTouch(p1, p0);
	}

	Assembly* Primitive::getAssembly() const 
	{
		return clump ? clump->getAssembly() : NULL;
	}

	void Primitive::setPrimitiveType(Geometry::GeometryType geometryType)
	{

		if (geometry->getGeometryType() != geometryType)
		{
			G3D::Vector3 oldSize = geometry->getGridSize();
			if (geometry)
				delete geometry;

			geometry = newGeometry(geometryType);

			if (world)
				world->onPrimitiveGeometryTypeChanged(this);

			setGridSize(oldSize);
			JointK.setDirty();
		}
	}

	void Primitive::setCoordinateFrame(const G3D::CoordinateFrame& value)
	{
		if (value != body->getPV().position)
		{
			Assembly* assembly = getAssembly();
			if (!assembly)
			{
				body->setCoordinateFrame(value);
				myOwner->notifyMoved();
				if (world)
					world->onPrimitiveExtentsChanged(this);
			}
			else
			{
				RBXASSERT(world);
				if (assembly->getMainPrimitive() == this)
				{
					body->setCoordinateFrame(value);
					assembly->notifyMoved();
					world->onAssemblyExtentsChanged(assembly);
					if (!anchored)
						world->ticklePrimitive(this);
				}
			}
		}
	}

	void Primitive::setDragging(bool _dragging)
	{
		bool wasAnchored = dragging || anchored || flag0xaa;
		if (dragging != _dragging)
		{
			dragging = _dragging;
			bool isAnchored = dragging || anchored || flag0xaa;
			if (isAnchored != wasAnchored && world)
			{
				if (isAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	void Primitive::setAnchor(bool _anchored)
	{
		bool wasAnchored = dragging || anchored || flag0xaa;
		if (anchored != _anchored)
		{
			anchored = _anchored;
			bool isAnchored = dragging || anchored || flag0xaa;
			if (isAnchored != wasAnchored && world)
			{
				if (isAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	void Primitive::setFlag0xaa(bool value)
	{
		bool wasAnchored = dragging || anchored || flag0xaa;
		if (flag0xaa != value)
		{
			flag0xaa = value;
			bool isAnchored = dragging || anchored || flag0xaa;
			if (isAnchored != wasAnchored && world)
			{
				if (isAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	void Primitive::setPV(const PV& pv)
	{
		body->setVelocity(pv.velocity);
		setCoordinateFrame(pv.position);
	}

	void Primitive::setCanCollide(bool value)
	{
		if (value != canCollide)
		{
			canCollide = value;
			if (world)
				world->onPrimitiveCanCollideChanged(this);
		}
	}

	void Primitive::setCanSleep(bool _canSleep)
	{
		if (_canSleep != canSleep)
			canSleep = _canSleep;
	}

	void Primitive::setFriction(float _friction)
	{
		if (_friction != friction)
		{
			friction = _friction;
			if (world)
				world->onPrimitiveContactParametersChanged(this);
		}
	}

	void Primitive::setElasticity(float _elasticity)
	{
		if (_elasticity != elasticity)
		{
			elasticity = _elasticity;
			if (world)
				world->onPrimitiveContactParametersChanged(this);
		}
	}

	void Primitive::setGridSize(const G3D::Vector3& gridSize) // 100% match when Body::setMoment is set as __declspec(noinline)
	{
		G3D::Vector3 protectedSize = clipToSafeSize(gridSize);

		if (protectedSize != geometry->getGridSize())
		{
			fuzzyExtentsStateId = -2;
			geometry->setGridSize(protectedSize);
			setMassInertia(geometry->getGridVolume());

			if (world)
				world->onPrimitiveExtentsChanged(this);

			JointK.setDirty();
		}
	}

	void Primitive::setMassInertia(float mass)
	{
		body->setMass(mass);
		body->setMoment(geometry->getMoment(mass));
		JointK.setDirty();
	}

	bool Primitive::aaBoxCollide(const Primitive& p0, const Primitive& p1)
	{
		G3D::Vector3 delta = p0.getCoordinateFrame().translation - p1.getCoordinateFrame().translation;
		float r0 = p0.getRadius();
		float r1 = p1.getRadius();
		
		if (r0 + r1 < Math::longestVector3Component(delta))
			return false;

		const Extents& f1 = p1.getFastFuzzyExtents();
		const Extents& f0 = p0.getFastFuzzyExtents();
		return f0.overlapsOrTouches(f1);
	}

	Extents Primitive::computeFuzzyExtents() const
	{
		Extents ext = Extents::fromCenterCorner(body->getPV().position.translation, geometry->getCenterToCorner(body->getPV().position.rotation));
		ext.expand(0.01f);

		return ext;
	}

	void Primitive::setController(Controller* _controller)
	{
		if (!_controller)
			_controller = NullController::getStaticNullController();

		if (controller != _controller)
			controller = _controller;
	}

	const Extents& Primitive::getFastFuzzyExtents() const
	{
		if (fuzzyExtentsStateId != body->getStateIndex())
		{
			fuzzyExtents = computeFuzzyExtents();
			fuzzyExtentsStateId = body->getStateIndex();
		}

		return fuzzyExtents;
	}

	Joint* Primitive::getNextJoint(Joint* prev) const
	{
		return rbx_static_cast<Joint*>(joints.next(prev));
	}

	Contact* Primitive::getNextContact(Contact* prev)
	{
		int i = prev->getIndex(this) + 1;
		return i < contacts.edges.size() ? rbx_static_cast<Contact*>(contacts.edges[i]) : NULL;
	}

	Edge* Primitive::getNextEdge(Edge* e) const
	{
		if (Joint::isJoint(e))
		{
			Edge* next = joints.next(e);
			return next ? next : contacts.first();
		}
		return contacts.next(e);
	}

	Joint* Primitive::getJoint(Primitive* p0, Primitive* p1)
	{
		Primitive* least = p0->getNumJoints2() < p1->getNumJoints2() ? p0 : p1;

		for (Joint* current = least->getFirstJoint(); current != NULL; current = least->getNextJoint(current))
		{
			if (p0 == current->getPrimitive(0) && p1 == current->getPrimitive(1) || p0 == current->getPrimitive(1) && p1 == current->getPrimitive(0))
			   return current;
		}
		return NULL;
	}

	Contact* Primitive::getContact(Primitive* p0, Primitive* p1)
	{
		Primitive* least = p0->getNumContacts() < p1->getNumContacts() ? p0 : p1;

		for (Contact* current = least->getFirstContact(); current != NULL; current = least->getNextContact(current))
		{
			if (p0 == current->getPrimitive(0) && p1 == current->getPrimitive(1) || p0 == current->getPrimitive(1) && p1 == current->getPrimitive(0))
			   return current;
		}
		return NULL;
	}

	RigidJoint* Primitive::getFirstRigidAt(Edge* start)
	{
		for (Edge* current = start; current != NULL; current = getNextEdge(current))
		{
			if (RigidJoint::isRigidJoint(current))
				return rbx_static_cast<RigidJoint*>(current);
		}
		return NULL;
	}

	int Primitive::countNumJoints() const
	{
		int counter = 0;
		for (Joint* current = getFirstJoint(); current != NULL; current = getNextJoint(current))
		{
			Joint::JointType type = current->getJointType();
			if (type != Joint::FREE_JOINT && type != Joint::ANCHOR_JOINT)
				counter++;
		}
		return counter;
	}

	void Primitive::insertEdge(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);

		if (Joint::isJoint(e))
		{
			e->getPrimitive(0)->joints.insertEdge(e);

			if (p1)
				e->getPrimitive(1)->joints.insertEdge(e);
			else
				RBXASSERT(rbx_static_cast<Joint*>(e)->getJointType() == Joint::ANCHOR_JOINT || rbx_static_cast<Joint*>(e)->getJointType() == Joint::FREE_JOINT);
		}
		else
		{
			e->getPrimitive(0)->contacts.insertEdge(e);
			e->getPrimitive(1)->contacts.insertEdge(e);
		}
	}

	void Primitive::removeEdge(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);

		if (Joint::isJoint(e))
		{
			e->getPrimitive(0)->joints.removeEdge(e);

			if (p1)
				e->getPrimitive(1)->joints.removeEdge(e);
			else
				RBXASSERT(rbx_static_cast<Joint*>(e)->getJointType() == Joint::ANCHOR_JOINT || rbx_static_cast<Joint*>(e)->getJointType() == Joint::FREE_JOINT);
		}
		else
		{
			e->getPrimitive(0)->contacts.removeEdge(e);
			e->getPrimitive(1)->contacts.removeEdge(e);
		}
	}

	void EdgeList::insertEdge(Edge* e)
	{
		e->setIndex(owner, edges.size());
		edges.append(e);
		neighbors.append(e->otherPrimitive(owner));
	}

	void EdgeList::removeEdge(Edge* e)
	{
		int index = e->getIndex(owner);
		Edge* lastEdge = edges.last();
		Primitive* lastNeighbor = neighbors.last();
		edges[index] = lastEdge;
		neighbors[index] = lastNeighbor;
		edges.popDiscard();
		neighbors.popDiscard();
		lastEdge->setIndex(owner, index);
		e->setIndex(owner, -1);
	}

	Edge* EdgeList::first() const
	{
		return edges.size() > 0 ? edges[0] : NULL;
	}

	Edge* EdgeList::next(Edge* e) const
	{
		int i = e->getIndex(owner) + 1;
		return i < edges.size() ? edges[i] : NULL;
	}
}
namespace RBX {
    // 0x5e7420: int +0x14, guarded by world +0x58 (clump is +0x5c).
    void Primitive::setUnknown0x14(int value)
    {
        if (value != unknown0x14 && !world)
            unknown0x14 = value;
    }
}
