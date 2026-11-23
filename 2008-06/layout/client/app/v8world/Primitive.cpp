// =============================================================================
// Primitive.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/Primitive.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include <math.h>
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include "v8kernel/IPipelined2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Geometry2008.h"
#include "util/Guid.h"
#include "util/Vector3int32.h"
#include "util/Extents.h"
#include "util/SurfaceType.h"
#include "util/ComputeProp.h"
#include "util/NormalId.h"
#include "util/PV.h"
#include "AppUnit658/Edge.h"
#include "v8world/Joints2008.h"
#include "v8world/Contact2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"
#include "v8world/IMoving.h"
#include "v8world/World2008.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	Joint* Primitive::getNextJoint(Joint* prev) const
	{
		int i = prev->getIndex(this) + 1;
		return i < joints.edges.size() ? static_cast<Joint*>(joints.edges[i]) : NULL;
	}

	Contact* Primitive::getNextContact(Contact* prev)
	{
		int i = prev->getIndex(this) + 1;
		return i < contacts.edges.size() ? static_cast<Contact*>(contacts.edges[i]) : NULL;
	}

	void Primitive::setDragging(bool _dragging)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (dragging != _dragging)
		{
			dragging = _dragging;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	void Primitive::setAnchor(bool _anchored)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (anchored != _anchored)
		{
			anchored = _anchored;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	void Primitive::setJointAnchored(bool _jointAnchored)
	{
		bool oldAnchored = dragging || anchored || jointAnchored;
		if (jointAnchored != _jointAnchored)
		{
			jointAnchored = _jointAnchored;
			bool newAnchored = dragging || anchored || jointAnchored;
			if (newAnchored != oldAnchored && world)
			{
				if (newAnchored)
					world->onPrimitiveAddedAnchor(this);
				else
					world->onPrimitiveRemovingAnchor(this);
			}
		}
	}

	G3D::Vector3 Primitive::clipToSafeSize(const G3D::Vector3& newSize)
	{
		G3D::Vector3 answer = newSize.min(G3D::Vector3(512.0f, 512.0f, 512.0f));
		const float maxVolume = 1000000.0f;
		if (answer.x * answer.y * answer.z > maxVolume)
			answer.y = floor(maxVolume / (answer.x * answer.z));
		return answer;
	}

	void Primitive::setMassInertia(float mass)
	{
		body->setMass(mass);
		body->setMoment(geometry->getMoment(mass));
		JointK.setDirty();
	}

	void Primitive::setGridSize(const G3D::Vector3& gridSize)
	{
		G3D::Vector3 safe = clipToSafeSize(gridSize);
		if (safe != geometry->getGridSize())
		{
			fuzzyExtentsStateId = -2;
			geometry->setGridSize(safe);
			setMassInertia(geometry->getGridVolume());
			if (world)
				world->onPrimitiveExtentsChanged(this);
			JointK.setDirty();
		}
	}

	void Primitive::setPV(const PV& pv)
	{
		body->setVelocity(pv.velocity);
		setCoordinateFrame(pv.position);
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
		if (value != body->getCoordinateFrame())
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
				if (assembly->getRootClump()->getRootPrimitive() == this)
				{
					body->setCoordinateFrame(value);
					assembly->notifyMoved();
					world->onAssemblyExtentsChanged(assembly);
					if (!(dragging || anchored || jointAnchored))
						world->ticklePrimitive(this, 0);
				}
			}
		}
	}
}

#ifdef PRIMITIVE_HEADER_DECLARES_GRID_CORNER_EDGES
namespace RBX
{
	RigidJoint* Primitive::getFirstRigidAt(Edge* start)
	{
		while (start != NULL)
		{
			if (RigidJoint::isRigidJoint(start))
				return static_cast<RigidJoint*>(start);

			start = getNextJoint(static_cast<Joint*>(start));
		}

		return NULL;
	}

	Face Primitive::getFaceInWorld(NormalId objectFace)
	{
		return getFaceInObject(objectFace).toWorldSpace(body->getPV().position);
	}

	G3D::CoordinateFrame Primitive::getGridCorner() const
	{
		const G3D::CoordinateFrame& pos = body->getPV().position;
		G3D::Vector3 hVec = -(geometry->getGridSize() * 0.5f);

		return G3D::CoordinateFrame(pos.rotation, pos.pointToWorldSpace(hVec));
	}

	void Primitive::setGridCorner(const G3D::CoordinateFrame& gridCorner)
	{
		G3D::Vector3 hVec = geometry->getGridSize() * 0.5f;
		setCoordinateFrame(G3D::CoordinateFrame(gridCorner.rotation, gridCorner.pointToWorldSpace(hVec)));
	}

	void Primitive::removeEdge(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);

		if (e->getEdgeType() == Edge::JOINT)
		{
			p0->joints.removeEdge(e);
			if (p1)
				p1->joints.removeEdge(e);
		}
		else
		{
			p0->contacts.removeEdge(e);
			p1->contacts.removeEdge(e);
		}
	}

	void Primitive::insertEdge(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);

		if (e->getEdgeType() == Edge::JOINT)
		{
			p0->joints.insertEdge(e);
			if (p1)
				p1->joints.insertEdge(e);
		}
		else
		{
			p0->contacts.insertEdge(e);
			p1->contacts.insertEdge(e);
		}
	}
}
#endif

namespace RBX
{
	void EdgeList::insertEdge(Edge* e)
	{
		e->setIndex(owner, edges.size());
		edges.append(e);
		otherPrimitives.append(e->otherPrimitive(owner));
	}

	void EdgeList::removeEdge(Edge* e)
	{
		int index = e->getIndex(owner);
		Edge* lastEdge = edges.last();
		Primitive* lastPrimitive = otherPrimitives.last();
		edges[index] = lastEdge;
		otherPrimitives[index] = lastPrimitive;
		edges.popDiscard();
		otherPrimitives.popDiscard();
		lastEdge->setIndex(owner, index);
		e->setIndex(owner, -1);
	}
}

#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8kernel/Connector2008.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/Constants.h"
#include <G3D/Vector3int16.h>
#include <algorithm>

namespace RBX
{
	bool BallBlockContact::computeIsColliding(float overlapIgnored)
	{
		int onBorder;
		G3D::Vector3int16 clip;
		G3D::Vector3 projectionInBlock;
		return computeIsColliding(onBorder, clip, projectionInBlock, overlapIgnored);
	}

	void Contact::onPrimitiveContactParametersChanged()
	{
		Primitive* prim0 = getPrimitive(0);
		Primitive* prim1 = getPrimitive(1);

		kFriction = std::min(prim0->getFriction(), prim1->getFriction());
		float elasticity = std::min(prim0->getElasticity(), prim1->getElasticity());

		jointK = std::min(prim0->getJointK(), prim1->getJointK());
		elasticJointK = Constants::getElasticMultiplier(elasticity) * jointK;
	}

	int Contact::contactPairMatches;           // 0097b880 (++ by BlockBlockContact 00607d3b)
	int Contact::contactPairMisses;            // 0097b884 (++ by 00607d07)
	int Contact::contactFeatureMatches;        // 0097b888 (++ by 00607588)
	int Contact::contactFeatureMisses;         // 0097b88c (++ by 00607548)

	float Contact::contactPairHitRatio()
	{
		int sum = contactPairMatches + contactPairMisses;
		if (sum == 0)
			return -1.0f;
		else
			return (float)contactPairMatches / sum;
	}

	float Contact::contactFeatureHitRatio()
	{
		int sum = contactFeatureMatches + contactFeatureMisses;
		if (sum == 0)
			return -1.0f;
		else
			return (float)contactFeatureMatches / sum;
	}

	ContactConnector* Contact::createConnector(Body* b0, Body* b1)
	{
		ContactConnector* answer = new ContactConnector(jointK, elasticJointK, kFriction);
		answer->setBody(0, b0);
		answer->setBody(1, b1);
		getKernel()->insertConnector(answer);
		return answer;
	}

	bool Contact::step(int uiStepId)
	{
		bool result = stepContact();
		if (result)
		{
			if (lastContactStep == -1)
				Primitive::onNewTouch(getPrimitive(0), getPrimitive(1));
			lastContactStep = uiStepId;
		}
		else if (lastContactStep < uiStepId)
		{
			lastContactStep = -1;
		}
		return result;
	}

	bool Contact::computeIsAdjacent(float spaceAllowed)
	{
		if (computeIsColliding(spaceAllowed))
			return false;
		else
			return computeIsColliding(-spaceAllowed);
	}
}

void RBX::Primitive::setCanSleep(bool v) { if (v != canSleep) canSleep = v; }
void RBX::Primitive::setSurfaceType(RBX::NormalId index, RBX::SurfaceType value) { if (surfaceType[index] != value) surfaceType[index] = value; }

#define NATIVE_CLUMP_DECL

namespace RBX
{
	// 005e7560 (placeholder func_005e7560; INFERRED name): clump->assembly without the NULL check of getAssembly 005e7570
	Assembly* Primitive::getAssemblyNoCheck() const
	{
		return clump->getAssembly();
	}
}

// Identity: declared INFERRED at 005e7b20 in native-headers/v8world/Primitive2008.h; the body walks prev's slot
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h

namespace RBX
{
	Edge* Primitive::getNextEdge(Edge* prev) const
	{
		if (prev->getEdgeType() == Edge::JOINT)
		{
			int i = prev->getIndex(this) + 1;
			Edge* next = i < joints.edges.size() ? joints.edges[i] : NULL;
			if (next)
				return next;
			return contacts.edges.size() > 0 ? contacts.edges[0] : NULL;
		}
		else
		{
			int i = prev->getIndex(this) + 1;
			return i < contacts.edges.size() ? contacts.edges[i] : NULL;
		}
	}
}
