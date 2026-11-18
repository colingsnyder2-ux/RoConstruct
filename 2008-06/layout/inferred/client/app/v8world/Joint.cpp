#include "v8world/Joints2008.h"
#include "v8world/World2008.h"
#include "util/Math.h"

namespace RBX
{
	Joint::Joint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0,
	             const G3D::CoordinateFrame& _jointCoord1)
		: Edge(prim0, prim1),
		  jointOwner(NULL),
		  active(false)
	{
		jointCoord0 = Math::snapToGrid(_jointCoord0, 0.1f);
		jointCoord1 = Math::snapToGrid(_jointCoord1, 0.1f);
	}

	Joint::Joint()
		: Edge(NULL, NULL),
		  jointOwner(NULL),
		  active(false),
		  jointCoord0(),
		  jointCoord1()
	{
	}

	Joint::~Joint()
	{
	}

	void Joint::setPrimitive(int i, Primitive* p)
	{
		if (p != getPrimitive(i))
		{
			World* world = getWorld();
			if (world && getPrimitive(i))
				world->onJointPrimitiveNulling(this, getPrimitive(i));
			Edge::setPrimitive(i, p);
			if (world && p)
				world->onJointPrimitiveSet(this, p);
		}
	}

	void Joint::setJointCoord(int i, const G3D::CoordinateFrame& c)
	{
		if (c != getJointCoord(i))
		{
			if (i == 0)
				jointCoord0 = c;
			else
				jointCoord1 = c;

			World* world = getWorld();
			if (world)
			{
				world->removeJoint(this);
				world->insertJoint(this);
			}
		}
	}

	bool Joint::canBuildJointLoose(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		return canBuildJoint(p0, p1, nId0, nId1, 0.05f, 0.05f);
	}

	bool Joint::canBuildJointTight(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1)
	{
		return canBuildJoint(p0, p1, nId0, nId1, 0.01f, 0.01f);
	}
}
