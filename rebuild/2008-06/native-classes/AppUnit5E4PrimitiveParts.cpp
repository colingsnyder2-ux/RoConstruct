// 2008-06 v8world/Primitive.cpp rows of the application range 005e4000..005e8000 (inactive native unit) declared by the
// committed part-embedded Primitive declaration (native-headers/part-embedded/v8world/Primitive.h, read-only, put first
// on the include path as for the app-unit5ec / app-unit5f0 surface rows) and the engine-world v8world/World.h
// (read-only). /fp:fast. The bodies follow the bytes (2008 setCanCollide / setCanSleep have no drag test and
// setCanSleep no world notification). Verified by tests/record_native_app_unit5e4.py.
#undef _RELEASEASSERT
#include "v8world/Primitive.h"
#include "v8world/World.h"
#include "v8kernel/Body.h"
#include "util/NormalId.h"

namespace RBX
{
	// 005e7450: Guid::assign(Data) 005a8200 on guid +0x8 (Data passed by value), then guidSetExternally +0x10.
	void Primitive::setGuid(const Guid& value)
	{
		guid.copyDataFrom(value);
		guidSetExternally = true;
	}

	// 005e7550: clump +0x5c.
	void Primitive::setClump(Clump* set)
	{
		if (set != clump)
			clump = set;
	}

	// 005e75b0: canCollide +0xac; world +0x58 -> World 005e9460 (tail jump).
	void Primitive::setCanCollide(bool value)
	{
		if (value != canCollide)
		{
			canCollide = value;
			if (world)
				world->onPrimitiveCanCollideChanged(this);
		}
	}

	// 005e75e0: +0xab, no notification.
	void Primitive::setCanSleep(bool _canSleep)
	{
		if (_canSleep != canSleep)
			canSleep = _canSleep;
	}

	// 005e7600: friction +0xb0; World::onPrimitiveContactParametersChanged 005e9190 (tail jump).
	void Primitive::setFriction(float _friction)
	{
		if (_friction != friction)
		{
			friction = _friction;
			if (world)
				world->onPrimitiveContactParametersChanged(this);
		}
	}

	// 005e7640: elasticity +0xb4; World::onPrimitiveContactParametersChanged 005e9190 (tail jump).
	void Primitive::setElasticity(float _elasticity)
	{
		if (_elasticity != elasticity)
		{
			elasticity = _elasticity;
			if (world)
				world->onPrimitiveContactParametersChanged(this);
		}
	}

	// 005e7680: normalIdToMatrix3 005ec800, normalIdToVector3 005ec570, gridSize at geometry (+0x9c) +0x4.
	G3D::CoordinateFrame Primitive::getFaceCoordInObject(NormalId objectFace)
	{
		return G3D::CoordinateFrame(normalIdToMatrix3(objectFace), normalIdToVector3(objectFace) * geometry->getGridSize());
	}

	// 005e76f0: Face::fromExtentsSide of the local extents (+-gridSize / 2).
	Face Primitive::getFaceInObject(NormalId objectFace)
	{
		return Face::fromExtentsSide(getExtentsLocal(), objectFace);
	}

	// 005e7760: body +0xa0, Body::setVelocity 00614040 (tail jump).
	void Primitive::setVelocity(const Velocity& vel)
	{
		body->setVelocity(vel);
	}
}
