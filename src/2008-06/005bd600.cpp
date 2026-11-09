// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8datamodel/Gyro.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Gyro.h"

#include "v8datamodel/PartInstance.h"
#include "v8kernel/Body.h"
#include "v8kernel/SimBody.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"

namespace RBX {

char sRocket[] = "RocketPropulsion";

char sBodyVelocity[] = "BodyVelocity";

char sBodyPosition[] = "BodyPosition";

char sBodyThrust[] = "BodyThrust";

char sBodyForce[] = "BodyForce";

char sBodyGyro[] = "BodyGyro";

// FUNCTION: WEBSERVICE 0x100ea340
BodyMover::~BodyMover()
{
}

// FUNCTION: WEBSERVICE 0x100ea3b0
void BodyMover::onEvent(const RunService* source, Stepped event)
{
	if (preventBodySleep()) {
		world->ticklePrimitive(part->getPrimitive(), true);
	}
}

// STUB: WEBSERVICE 0x100ea7c0
void BodyGyro::computeOrientation(Body* body)
{
	STUB(0x100ea7c0);
}

// STUB: WEBSERVICE 0x100eaaf0
void BodyGyro::computeBalance(Body* body)
{
	STUB(0x100eaaf0);
}

// STUB: WEBSERVICE 0x100eaf60
void BodyPosition::computeForce(float dt, bool throttling)
{
	Body* body = part->getPrimitive()->getBody();

	Vector3 positionForce = (position - body->getPV().position.translation) * kP;

	Vector3 goalForce = positionForce + body->getPV().velocity.linear * -kD;

	lastForce = goalForce * body->getRoot()->getBranchMass();

	lastForce = lastForce.clamp(-maxForce, maxForce);

	body->getRoot()->accumulateForceAtBranchCofm(lastForce);
}

// FUNCTION: WEBSERVICE 0x100eb0c0
void BodyVelocity::computeForce(float dt, bool throttling)
{
	Body* body = part->getPrimitive()->getBody();

	Vector3 goalForce = (velocity - body->getPV().velocity.linear) * kP;

	lastForce = goalForce * body->getRoot()->getBranchMass();

	lastForce = lastForce.clamp(-maxForce, maxForce);

	body->getRoot()->accumulateForceAtBranchCofm(lastForce);
}

// FUNCTION: WEBSERVICE 0x100eb1e0
void BodyForce::computeForce(float dt, bool throttling)
{
	part->getPrimitive()->getBody()->getRoot()->accumulateForceAtBranchCofm(force);
}

// FUNCTION: WEBSERVICE 0x100eb240
void BodyThrust::computeForce(float dt, bool throttling)
{
	Body* body = part->getPrimitive()->getBody();

	Vector3 worldForce = body->getPV().position.vectorToWorldSpace(force);
	Vector3 worldPos = body->getPV().position.pointToWorldSpace(location);

	body->accumulateForce(worldForce, worldPos);
}

// STUB: WEBSERVICE 0x100ebb10
void Rocket::computeForce(float dt, bool throttling)
{
	STUB(0x100ebb10);
}

// STUB: WEBSERVICE 0x100ebfb0
void BodyGyro::computeForce(float dt, bool throttling)
{
	Body* body = part->getPrimitive()->getBody();

	computeBalance(body);
	computeOrientation(body);
}

// FUNCTION: WEBSERVICE 0x100ed7b0
bool BodyVelocity::preventBodySleep()
{
	return velocity != G3D::Vector3::zero();
}

// STUB: WEBSERVICE 0x100ed840
BodyForce::BodyForce() : force(G3D::Vector3::unitY())
{
}

// FUNCTION: WEBSERVICE 0x100ed950 FOLDED
bool BodyForce::preventBodySleep()
{
	return force != G3D::Vector3::zero();
}

// FUNCTION: WEBSERVICE 0x100ed950 FOLDED
bool BodyThrust::preventBodySleep()
{
	return force != G3D::Vector3::zero();
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::BodyForce, RBX::BodyMover, RBX::sBodyForce>;
template class RBX::Reflection::
	Described<RBX::BodyForce, RBX::sBodyForce, RBX::FactoryProduct<RBX::BodyForce, RBX::BodyMover, RBX::sBodyForce> >;
template class RBX::DescribedCreatable<RBX::BodyForce, RBX::BodyMover, RBX::sBodyForce>;

template class RBX::FactoryProduct<RBX::BodyGyro, RBX::BodyMover, RBX::sBodyGyro>;
template class RBX::Reflection::
	Described<RBX::BodyGyro, RBX::sBodyGyro, RBX::FactoryProduct<RBX::BodyGyro, RBX::BodyMover, RBX::sBodyGyro> >;
template class RBX::DescribedCreatable<RBX::BodyGyro, RBX::BodyMover, RBX::sBodyGyro>;

template class RBX::FactoryProduct<RBX::BodyPosition, RBX::BodyMover, RBX::sBodyPosition>;
template class RBX::Reflection::Described<
	RBX::BodyPosition,
	RBX::sBodyPosition,
	RBX::FactoryProduct<RBX::BodyPosition, RBX::BodyMover, RBX::sBodyPosition> >;
template class RBX::DescribedCreatable<RBX::BodyPosition, RBX::BodyMover, RBX::sBodyPosition>;

template class RBX::FactoryProduct<RBX::BodyThrust, RBX::BodyMover, RBX::sBodyThrust>;
template class RBX::Reflection::Described<
	RBX::BodyThrust,
	RBX::sBodyThrust,
	RBX::FactoryProduct<RBX::BodyThrust, RBX::BodyMover, RBX::sBodyThrust> >;
template class RBX::DescribedCreatable<RBX::BodyThrust, RBX::BodyMover, RBX::sBodyThrust>;

template class RBX::FactoryProduct<RBX::BodyVelocity, RBX::BodyMover, RBX::sBodyVelocity>;
template class RBX::Reflection::Described<
	RBX::BodyVelocity,
	RBX::sBodyVelocity,
	RBX::FactoryProduct<RBX::BodyVelocity, RBX::BodyMover, RBX::sBodyVelocity> >;
template class RBX::DescribedCreatable<RBX::BodyVelocity, RBX::BodyMover, RBX::sBodyVelocity>;

template class RBX::FactoryProduct<RBX::Rocket, RBX::BodyMover, RBX::sRocket>;
template class RBX::Reflection::
	Described<RBX::Rocket, RBX::sRocket, RBX::FactoryProduct<RBX::Rocket, RBX::BodyMover, RBX::sRocket> >;
template class RBX::DescribedCreatable<RBX::Rocket, RBX::BodyMover, RBX::sRocket>;
