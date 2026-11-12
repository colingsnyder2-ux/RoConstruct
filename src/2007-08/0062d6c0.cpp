// from server: 71% by EspClaude
// from server: 66% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_claude_e8309e0e9745bb06.cpp

// Candidate translation unit (score above; library headers required).
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

// SIZE 0xcc
class Body : public KernelIndex
{
public:
	Body();
	~Body();

private:
	void updatePV() const;

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
	// 2007-08: one 4-byte field fewer between simBody (0x20) and moment; target reads moment at 0x58, pv.velocity.rotational.y at 0xc4
	Link* link;                                 // 0x24
	CoordinateFrame meInParent;                 // 0x28
	Matrix3 moment;                             // 0x58
	float mass;                                 // 0x7c
	mutable int stateIndex;                     // 0x80
	mutable PV pv;                              // 0x84
};

DECOMP_SIZE_ASSERT(Body, 0xcc)

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

#include "humanoid/Flying.h"

#include "util/Name.h"
#include "v8kernel/Body.h"

namespace RBX {

const char sFlying[] = "Flying";

const float Flying::kTurnP = 7500.0f;
const float Flying::kTurnAccelMax = 120000.0f;

// STUB: WEBSERVICE 0x1012a200
Humanoid::State* Flying::onStep(const float stepDt, Controller& controller)
{
	STUB(0x1012a200);
	return NULL;
}

// STUB: WEBSERVICE 0x1012a2e0
void Flying::onComputeForce(const float dt)
{
	Balancing::onComputeForce(dt);

	Body* body = humanoid->getRootBody();

	float momentY = body->getBranchIBodyV3().y;
	float desiredTorqueY = (desiredYRotationalVelocity - body->getVelocity().rotational.y) * momentY * kTurnP;

	desiredTorqueY -= body->getBranchTorque().y;

	float maxTorqueY = body->getBranchIBodyV3().y * kTurnAccelMax;

	desiredTorqueY = G3D::clamp(desiredTorqueY, -maxTorqueY, maxTorqueY);

	body->accumulateTorque(Vector3(0, desiredTorqueY, 0));
}

// FUNCTION: WEBSERVICE 0x1012a4d0
Flying::Flying(Humanoid* humanoid) : Named<Balancing, sFlying>(humanoid, 300.0f, 50.0f), desiredYRotationalVelocity(0)
{
}

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sFlying>();
template void RBX::Name::callDoDeclare<RBX::sFlying>();
