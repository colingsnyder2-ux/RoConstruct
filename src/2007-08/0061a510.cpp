// from server: 100% by EspClaude
// from server: 87% by EspClaude
// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_claude_f20dd3bc20a66ac1.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/SimBody.h"
#include "v8kernel/Constants.h"
// v8kernel/Body.h copy for 2007-08: target reads Body::cofm at +0x1c but moment at +0x58, mass at +0x7c, pv at +0x84
// (Dec-2007 header: +0x5c/+0x80/+0x88), so one 4-byte member between cofm and moment is absent; canThrottle dropped.
#pragma once
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <G3D/CoordinateFrame.h>
#include "util/indexarray.h"
#include "v8kernel/SimBody.h"
#include "v8kernel/Link.h"
#include "util/PV.h"
#include "v8kernel/KernelIndex.h"
#include "v8kernel/Cofm.h"
#include "util/math.h"

namespace RBX {
	//class SimBody;
	class Body : KernelIndex
	{
		private:
			int& getIndex() {return index;};
			Body *root;
			Body *parent;
			int index;
			IndexArray<RBX::Body, &getIndex> children;
			Cofm *cofm;
			SimBody *simBody;
			RBX::Link *link;
			G3D::CoordinateFrame meInParent;
			G3D::Matrix3 moment;
			float mass;
			mutable int stateIndex;
			mutable PV pv;
			//int& getKernelIndex();
			const RBX::SimBody* getRootSimBody() {return getRoot()->simBody;};
			void resetRoot(RBX::Body* newRoot);
			bool validateParentCofmDirty();
			const G3D::CoordinateFrame& getMeInParent() const
			{
				RBXASSERT(getParent());
				return getLink() ? getLink()->getChildInParent() : meInParent;
			}
			void updatePV() const;
			void onChildAdded(RBX::Body* child);
			void onChildRemoved(RBX::Body* child);
			const RBX::Body* calcRootConst() const;
			__declspec(noinline) Body* Body::calcRoot()
			{
				return (getParent() ? getParent()->calcRoot() : this);
			}
			void matchDummy();
		public:
			int& getKernelIndex() {return kernelIndex;}
			Body();
			~Body();
			void step(float, bool);
			bool cofmIsClean();
			void makeCofmDirty();
			void advanceStateIndex();
			void makeStateDirty();
			int getStateIndex() const
			{
				updatePV();
				return stateIndex;
			}
			int numChildren() const {return children.size();}
			RBX::Body* getChild(int index) {return children[index];} //suppose to be const
			inline RBX::Body* getParent() const
			{
				return parent;
			}
			RBX::Link* getLink() const {return link;}
			const RBX::Body* getRootConst() const {return root;}
			RBX::Body* getRoot() {return root;}
			const G3D::Vector3& getCofmOffset() const
			{
				if (cofm)
				{
					return cofm->getCofmInBody();
				}
				else
				{
					return G3D::Vector3::zero();
				}
			}

			G3D::CoordinateFrame getMeInDescendant(const RBX::Body* descendant) const;
			G3D::CoordinateFrame getMeInRoot() const;
			float getMass() const {return mass;}
			G3D::Matrix3 getIBody() const
			{
				updatePV();
				return moment;
			}
			G3D::Vector3 getIBodyV3() const;
			G3D::Matrix3 getIWorld() const
			{
				return Math::momentToWorldSpace(getIBody(), pv.position.rotation);
			}
			G3D::Matrix3 getIWorldAtPoint(const G3D::Vector3& point) const;
			float getBranchMass() const
			{
				return (cofm ? cofm->getMass() : mass);
			}
			G3D::Matrix3 getBranchIBody() const
			{
				return cofm ? cofm->getMoment() : moment;
			}
			G3D::Vector3 getBranchIBodyV3() const
			{
				return Math::toDiagonal(getBranchIBody());
			}
			G3D::Matrix3 getBranchIWorld() const
			{
				updatePV();
				return Math::momentToWorldSpace(getBranchIBody(), pv.position.rotation);
			}
			G3D::Matrix3 getBranchIWorldAtPoint(const G3D::Vector3& point) const;
			G3D::Vector3 getBranchCofmPos() const;
			G3D::CoordinateFrame getBranchCofmCoordinateFrame() const;
			const G3D::Vector3& getPos() const
			{
				updatePV();
				return cofm->getCofmInBody();
			}
			const G3D::CoordinateFrame& getCoordinateFrame() const
			{
				updatePV();
				return pv.position;
			}
			const RBX::Velocity& getVelocity() const
			{
				updatePV();
				return pv.velocity;
			}
			const RBX::PV& getPV() const
			{
				updatePV();
				return pv;
			}
			const bool getCanThrottle() const {return true;}
			void accumulateForceAtCofm(const G3D::Vector3&);
			void accumulateForceAtBranchCofm(const G3D::Vector3& force)
			{
				RBXASSERT(root == this);

				if (root->simBody)
					root->simBody->accumulateForceCofm(force);
			}
			void accumulateForce(const G3D::Vector3& force, const G3D::Vector3& worldPos)
			{
				SimBody* simBody = root->simBody;
				if (simBody)
					simBody->accumulateForce(force, worldPos);
			}
			void accumulateTorque(const G3D::Vector3& torque)
			{
				if (root->simBody)
					root->simBody->accumulateTorque(torque);
			}
			void resetAccumulators()
			{
				if (root->simBody)
					root->simBody->resetAccumulators();
			}
			const G3D::Vector3& getBranchForce() const
			{
				if (root->simBody)
					return root->simBody->force;
				else
					return G3D::Vector3::zero();
			}
			const G3D::Vector3& getBranchTorque() const
			{
				if (root->simBody)
					return root->simBody->torque;
				else
					return G3D::Vector3::zero();
			}
			void setParent(Body* newParent);
			void setMeInParent(RBX::Link*);
			void setMeInParent(const G3D::CoordinateFrame& _meInParent);
			void setMass(float _mass);
			__declspec(noinline) void setMoment(const G3D::Matrix3& _momentInBody) // noinline for Primitive::setGridSize
			{
				if (moment != _momentInBody)
				{
					makeCofmDirty();
					moment = _momentInBody;
				}
			}
			void setPv(const PV& _pv);
			void setCoordinateFrame(const G3D::CoordinateFrame& worldCord);
			void setVelocity(const RBX::Velocity& worldVelocity);
			void setCanThrottle(bool value)
			{
				(void)value;
			}
			float kineticEnergy() const;
			float potentialEnergy() const;
			static int getNextStateIndex();
			static Body* getWorldBody();
	};
}
#include "util/Units.h"
namespace RBX
{

SimBody::SimBody(RBX::Body* _body)
			:body(_body),
			dirty(1),
			force(G3D::Vector3::zero()),
			torque(G3D::Vector3::zero()),
			constantForceY(0.0f)
{}

SimBody::~SimBody() {}

G3D::Vector3 vecUnkPercent(G3D::Vector3& input)
{
	return G3D::Vector3(1.0f / input.x, 1.0f / input.y, 1.0f / input.z);
}

float precentInline(float fNum)
{
	return 1.0f / fNum;
}

inline void Quaternion::normalize()
{
	*this *= 1.0f / magnitude();
}

__forceinline void SimBody::unkSimInline(float fNum)
{
	massRecip = 1.0f / fNum;
	momentRecip = vecUnkPercent(Math::toDiagonal(body->getBranchIBody()));
}

void SimBody::update()
{ float roc_dd0 = 0; float roc_dd1 = 0; float roc_dd2 = 0;
	
	{
		const G3D::Vector3 cofmOffset = body->getCofmOffset();
		pv = body->getPV().pvAtLocalOffset(cofmOffset);
	}
	qOrientation = Quaternion::Quaternion(pv.position.rotation);
	qOrientation.normalize();
	angMomentum = pv.velocity.rotational * body->getBranchIWorld();
	float _mass = body->getBranchMass();
	unkSimInline(_mass);
	constantForceY = body->getBranchMass() * Units::kmsAccelerationToRbx(Constants::getKmsGravity()).y;
	dirty = false;
}


}

