// Layout probe for the inactive native BodyMover family (v8datamodel/BodyMovers.h, v8datamodel/Rocket.h);
// tests/record_native_body_movers.py checks each probe body is `mov eax, imm32; ret` with the binary's value:
//   sizes      create<X> allocations 005c1a00 (BodyGyro 0x18c), 005c2150 (BodyPosition 0x174), 005c23c0 (BodyVelocity
//              0x170), 005c2630 (BodyAngularVelocity 0x170), 005c1c70 (BodyForce 0x154), 005c1ee0 (BodyThrust 0x160),
//              005c28a0 (Rocket 0x190); BodyMover 0x148 (constructor 0062e320 writes up to +0x144).
//   bases      Connector +0x130 / Listener<RunService, Stepped> +0x138 (RTTI mdisp, constructor vptr stores).
//   fields     constructor stores and BoundProp member offsets pushed by the dynamic initializers 007f7f10..007f85a0.
#include <stddef.h>
#include "v8datamodel/BodyMovers.h"
#include "v8datamodel/Rocket.h"

#define NATIVE_BASE(D, B) ((size_t)static_cast<B*>((D*)0x1000) - 0x1000)

struct NativeBodyMoverLayout
{
	typedef RBX::Listener<RBX::RunService, RBX::Stepped> SteppedListener;
	static size_t moverConnector() { return NATIVE_BASE(RBX::BodyMover, RBX::Connector); }
	static size_t moverListener() { return NATIVE_BASE(RBX::BodyMover, SteppedListener); }
	static size_t moverWorld() { return offsetof(RBX::BodyMover, world); }
	static size_t moverPart() { return offsetof(RBX::BodyMover, part); }
	static size_t gyroKD() { return offsetof(RBX::BodyGyro, kD); }
	static size_t gyroMaxTorque() { return offsetof(RBX::BodyGyro, maxTorque); }
	static size_t gyroCFrame() { return offsetof(RBX::BodyGyro, cframe); }
	static size_t positionMaxForce() { return offsetof(RBX::BodyPosition, maxForce); }
	static size_t positionPosition() { return offsetof(RBX::BodyPosition, position); }
	static size_t positionLastForce() { return offsetof(RBX::BodyPosition, lastForce); }
	static size_t velocityMaxForce() { return offsetof(RBX::BodyVelocity, maxForce); }
	static size_t velocityVelocity() { return offsetof(RBX::BodyVelocity, velocity); }
	static size_t velocityLastForce() { return offsetof(RBX::BodyVelocity, lastForce); }
	static size_t angularMaxTorque() { return offsetof(RBX::BodyAngularVelocity, maxTorque); }
	static size_t angularVelocity() { return offsetof(RBX::BodyAngularVelocity, angularVelocity); }
	static size_t angularLastTorque() { return offsetof(RBX::BodyAngularVelocity, lastTorque); }
	static size_t forceForce() { return offsetof(RBX::BodyForce, force); }
	static size_t thrustLocation() { return offsetof(RBX::BodyThrust, location); }
	static size_t rocketActive() { return offsetof(RBX::Rocket, active); }
	static size_t rocketTarget() { return offsetof(RBX::Rocket, target); }
	static size_t rocketTargetOffset() { return offsetof(RBX::Rocket, targetOffset); }
	static size_t rocketTargetRadius() { return offsetof(RBX::Rocket, targetRadius); }
	static size_t rocketFiredEvent() { return offsetof(RBX::Rocket, firedEvent); }
	static size_t rocketMaxThrust() { return offsetof(RBX::Rocket, maxThrust); }
	static size_t rocketMaxSpeed() { return offsetof(RBX::Rocket, maxSpeed); }
	static size_t rocketMaxTorque() { return offsetof(RBX::Rocket, maxTorque); }
	static size_t rocketCartoonFactor() { return offsetof(RBX::Rocket, cartoonFactor); }
};

#define PROBE(name) size_t nativeBodyMover_##name() { return NativeBodyMoverLayout::name(); }
PROBE(moverConnector) PROBE(moverListener) PROBE(moverWorld) PROBE(moverPart)
PROBE(gyroKD) PROBE(gyroMaxTorque) PROBE(gyroCFrame)
PROBE(positionMaxForce) PROBE(positionPosition) PROBE(positionLastForce)
PROBE(velocityMaxForce) PROBE(velocityVelocity) PROBE(velocityLastForce)
PROBE(angularMaxTorque) PROBE(angularVelocity) PROBE(angularLastTorque)
PROBE(forceForce) PROBE(thrustLocation)
PROBE(rocketActive) PROBE(rocketTarget) PROBE(rocketTargetOffset) PROBE(rocketTargetRadius) PROBE(rocketFiredEvent)
PROBE(rocketMaxThrust) PROBE(rocketMaxSpeed) PROBE(rocketMaxTorque) PROBE(rocketCartoonFactor)

size_t nativeBodyMover_sizeBodyMover() { return sizeof(RBX::BodyMover); }
size_t nativeBodyMover_sizeBodyGyro() { return sizeof(RBX::BodyGyro); }
size_t nativeBodyMover_sizeBodyPosition() { return sizeof(RBX::BodyPosition); }
size_t nativeBodyMover_sizeBodyVelocity() { return sizeof(RBX::BodyVelocity); }
size_t nativeBodyMover_sizeBodyAngularVelocity() { return sizeof(RBX::BodyAngularVelocity); }
size_t nativeBodyMover_sizeBodyForce() { return sizeof(RBX::BodyForce); }
size_t nativeBodyMover_sizeBodyThrust() { return sizeof(RBX::BodyThrust); }
size_t nativeBodyMover_sizeRocket() { return sizeof(RBX::Rocket); }
