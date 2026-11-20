// 2008-06 native RBX::Rocket (inactive); evidence in native-headers/v8datamodel/Rocket.h. The original compiles it
// in the BodyMover unit (0062e090..00633101), so it uses the same unit profile (see
// tests/record_native_body_movers.py). Verified by tests/record_native_body_movers.py.
#include "v8datamodel/Rocket.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "Network/Players.h"

namespace RBX
{
	char sRocket[] = "RocketPropulsion"; // 0095c740

	// Template members the shared headers only declare (same definitions as BodyMovers.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	// DescribedCreatable(Arg0Type) is defined inline in reflection/reflection.h.

	// Dynamic initializers 007f7f10..007f8190 (in this order).
	Reflection::RefPropDescriptor<Rocket, PartInstance> Rocket::prop_Target("Target", "Goals", &Rocket::getTarget, &Rocket::setTarget, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_targetOffset("TargetOffset", "Goals", &Rocket::targetOffset, &Rocket::onGoalChanged, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_targetRadius("TargetRadius", "Goals", &Rocket::targetRadius, &Rocket::onGoalChanged, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_MaxSpeed("MaxSpeed", "Thrust", &Rocket::maxSpeed, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_MaxThrust("MaxThrust", "Thrust", &Rocket::maxThrust, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_ThrustP("ThrustP", "Thrust", &Rocket::kThrustP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_ThrustD("ThrustD", "Thrust", &Rocket::kThrustD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_TurnP("TurnP", "Turn", &Rocket::kTurnP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_TurnD("TurnD", "Turn", &Rocket::kTurnD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_MaxTorque("MaxTorque", "Turn", &Rocket::maxTorque, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_CartoonFactor("CartoonFactor", "Goals", &Rocket::cartoonFactor, Reflection::PropertyDescriptor::STANDARD);

	// Security 0 (NeedTrustedCaller in the donor enum) is what the 2008 initializers push.
	Reflection::BoundFuncDesc<Rocket, void(void), 0> Rocket::func_Fire(&Rocket::fire, "Fire", Reflection::FunctionDescriptor::NeedTrustedCaller);
	Reflection::BoundFuncDesc<Rocket, void(void), 0> Rocket::func_Abort(&Rocket::abort, "Abort", Reflection::FunctionDescriptor::NeedTrustedCaller);

	Reflection::SignalDesc<Rocket, void(void)> Rocket::event_ReachedTarget("ReachedTarget");

	Rocket::Rocket()
		: Base(sRocket),
		  active(false),
		  target(),
		  targetOffset(),
		  targetRadius(4.0f),
		  firedEvent(false),
		  maxThrust(4000.0f),
		  kThrustP(5.0f),
		  kThrustD(0.001f),
		  maxSpeed(30.0f),
		  kTurnP(3000.0f),
		  kTurnD(500.0f),
		  maxTorque(400000.0f, 400000.0f, 0.0f),
		  cartoonFactor(0.7f)
	{
	}

	// Workspace::findWorkspace 005a3380, Network::Players::clientIsPresent 00495e60 (native headers).
	void Rocket::fire()
	{
		if (!Workspace::findWorkspace(this))
			throw std::runtime_error("Rocket:Fire may only be called when the Rocket is in the Workspace");
		if (Network::Players::clientIsPresent(this, true))
			throw std::runtime_error("Rocket:Fire may not be called from a client");
		active = true;
	}

	void Rocket::abort()
	{
		active = false;
	}

	void Rocket::setTarget(PartInstance* value)
	{
		if (target.get() != value)
		{
			target = shared_from<PartInstance>(value);
			firedEvent = false;
			raisePropertyChanged(Rocket::prop_Target);
		}
	}
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sRocket>();

// 2008-06 native RBX::BodyGyro rows of the original BodyMovers unit (0062e090..00633101) that read 2008 Body fields
// (inactive): BodyGyro::computeOrientation 0062e910 and BodyGyro::computeBalance 0062ec40. BodyGyro::computeForce
// 006300d0 (their only caller) is in native-classes/BodyMovers.cpp.
//
// Batch 16: like native-classes/RocketControl.cpp, this unit defines NATIVE_PRIMITIVE_NATIVE_BODY, so the
// part-embedded Primitive.h and native-headers/v8datamodel/BodyMovers.h (-> v8kernel/Connector.h -> Connector2008.h)
// reach native-headers/v8kernel/Body2008.h (root +0x10, cofm +0x28, simBody +0x2c, moment +0x68, pv +0x94). The
// unit-local Connector / BodyMover / BodyGyro redeclarations of earlier batches are gone.
// Body::getBranchIBodyV3 (0062e100) and Body::getBranchTorque (0062e2e0) are now public inline members of
// native-headers/v8kernel/Body2008.h (donor tools/rbxgs v8kernel/Body.h shapes). With them computeOrientation 0062e910
// and the out-of-line COMDATs 0062e100 / 0062e2e0 / Body::accumulateTorque 006060b0 are prove.py inactive_exact
// (batch 12); computeBalance 0062ec40 stays parked (x87 scheduling, see below).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8datamodel/BodyMovers.h"
#include <G3D/g3dmath.h>
#include "util/Math.h"

namespace RBX
{
	// 0062e910: donor tools/rbxgs Gyro.cpp BodyGyro::computeOrientation.
	void BodyGyro::computeOrientation(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.y, 0.0f))
			return;

		Body* root = body->getRoot();

		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

		G3D::Vector3 localZNegAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.lookVector());

		float desiredTorqueY = -(root->getBranchIBodyV3().y * localZNegAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueY - torqueBody.y) < root->getBranchIBodyV3().y * maxTorque.y)
			torqueBody.y = desiredTorqueY;
		else
			torqueBody.y = torqueBody.y + desiredTorqueY;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.y = torqueBody.y - kD * root->getBranchIBodyV3().y * angVelBody.y;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}

	// 0062ec40: donor tools/rbxgs Gyro.cpp BodyGyro::computeBalance.
	void BodyGyro::computeBalance(Body* body)
	{
		if (G3D::fuzzyEq(maxTorque.x, 0.0f) && G3D::fuzzyEq(maxTorque.z, 0.0f))
			return;

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();
		G3D::Vector3 localYAxis = body->getCoordinateFrame().vectorToObjectSpace(cframe.upVector());
		float desiredTorqueX = root->getBranchIBodyV3().x * localYAxis.z * kP;
		float desiredTorqueZ = -(root->getBranchIBodyV3().z * localYAxis.x * kP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);

		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;

		if (fabs(desiredTorqueZ - torqueBody.z) < root->getBranchIBodyV3().z * maxTorque.z)
			torqueBody.z = desiredTorqueZ;
		else
			torqueBody.z += desiredTorqueZ;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		// Parked: 1136 bytes, first divergence at 0062ef27 (x87 scheduling only). The target loads kD first
		// ((kD * I.x) * angVelBody.x) and orders the angVelBody row as m01*y + m02*z + m00*x; every form tried compiles
		// to (I.x * angVelBody.x) * kD with m02*z first: `(I * a) * kD` (donor), `x = x - kD * I * a`,
		// `-= kD * (I * a)`, `-= kD * I * a`. Batch 27 (rejected): defining computeBalance before computeOrientation
		// (unit order) leaves the diff unchanged (insn 238). Every remaining diff is a mirrored commutative x87 operand
		// (row sums, the kD product, the inline SimBody::accumulateTorque fadd), the same mirror as Rocket::turn 0062e530.
		torqueBody.x -= (root->getBranchIBodyV3().x * angVelBody.x) * kD;
		torqueBody.z -= (root->getBranchIBodyV3().z * angVelBody.z) * kD;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}
}
