// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded
// 2008-06 native RBX::Rocket control path (inactive): onEvent 00632e10 (Listener<RunService, Stepped> slot 0, `this`
// is the Listener subobject at +0x138). Same original unit as native-classes/Rocket.cpp / BodyMovers.cpp
// (0062e090..00633101), so it uses the BodyMovers.cpp profile (part-embedded PartInstance.h). Donor tools/rbxgs
// v8datamodel/Gyro.cpp Rocket::onEvent. onGoalChanged 0062e0f0 is already inline in native-headers/v8datamodel/Rocket.h
// (not duplicated here).
// Parked (see the batch result): computeForce 0062fc00 and turn 0062e530 read the 2008 Body (Body::updatePV 00599360,
// root +0x10, cofm +0x28 / Cofm::getMass 0065ff10 or mass +0x8c, pv translation +0xb8, velocity +0xc4), declared only
// by native-headers/v8kernel/Body2008.h, while this unit reaches the donor v8kernel/Body.h through BodyMovers.h
// (v8kernel/Connector.h) and PartInstance.h (v8world/World.h); turn also needs Body::getBranchTorque /
// getBranchIBodyV3, which Body2008.h does not declare (the BodyGyro.cpp proposal).
#include "v8datamodel/Rocket.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 00632e10: BodyMover::onEvent 0062fae0, then weak_ptr<PartInstance>::lock 005cab00 on part +0x140 (twice),
	// PartInstance::getCoordinateFrame 00598cb0, CoordinateFrame::pointToWorldSpace 004766a0 for the target,
	// SignalDescriptor::findSignalInstance 0056b620 and signal0::operator() 004b5950 (event_ReachedTarget 0097c81c).
	void Rocket::onEvent(const RunService* source, Stepped event)
	{
		BodyMover::onEvent(source, event);

		if (world && part.lock() && active && !firedEvent)
		{
			G3D::Vector3 pos = part.lock()->getCoordinateFrame().translation;
			G3D::Vector3 targetWorld = target.get() ? target->getCoordinateFrame().pointToWorldSpace(targetOffset) : targetOffset;
			pos = pos - targetWorld;
			if (pos.squaredMagnitude() <= targetRadius * targetRadius)
			{
				Rocket::event_ReachedTarget.fire(this);
				firedEvent = true;
			}
		}
	}
}
