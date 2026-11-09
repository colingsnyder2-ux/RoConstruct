// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_bodythrustnative428b0b9524a36397.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <G3D/Vector3.h>
#include "util/Quaternion.h"
#include "util/PV.h"
//#include "v8kernel/Body.h"

namespace RBX {
	class Body;

	class SimBody
	{
		private:
		  void clearAccumulators();
		  void update();
		  void updateIfDirty()
		  {
			if (dirty)
				update();
		  }
		public:
			char observedPrefix[4];
			Body *body;
			bool dirty;
			PV pv;
			Quaternion qOrientation;
			G3D::Vector3 angMomentum;
			G3D::Vector3 momentRecip;
			float massRecip;
			float constantForceY;
			G3D::Vector3 force;
			G3D::Vector3 torque;
			//funcs
			__forceinline void SimBody::unkSimInline(float fNum);
			//void SimBody(const RBX::SimBody&);
			SimBody(RBX::Body* body);
			~SimBody();
			void step(float dt);
			void makeDirty() {dirty = true;};
			bool getDirty() const {return dirty;};
			PV getOwnerPV();
			const PV& getPV() {return pv;}
			void accumulateForceCofm(const G3D::Vector3& _force)
			{
				updateIfDirty();
				force += _force;	
			};
			inline static G3D::Vector3 accumulateInline(const G3D::Vector3& _force, const G3D::Vector3& pvWorld, const G3D::Vector3& worldPos)
			{
				G3D::Vector3 temp = worldPos - pvWorld;
				return temp.cross(_force);
			}
			void accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos)
			{
				updateIfDirty();
				force += _force;
				torque += accumulateInline(_force, pv.position.translation, worldPos);
			}
			void accumulateTorque(const G3D::Vector3& _torque)
			{
				updateIfDirty();
				torque += _torque;	
			}
			void SimBody::resetAccumulators()
			{
				updateIfDirty();
				force = G3D::Vector3(0.0f, constantForceY, 0.0f);
				torque = G3D::Vector3(0.0f, 0.0f, 0.0f);
			}
			const G3D::Vector3& getForce() const {return force;}
			const G3D::Vector3& getTorque() const {return torque;}
			void matchDummy();
	};
}

#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <G3D/CoordinateFrame.h>
#include "util/indexarray.h"

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
			char observedPrefix[12];
			Body *root;
			Body *parent;
			int index;
			IndexArray<RBX::Body, &getIndex> children;
			Cofm *cofm;
			SimBody *simBody;
			bool canThrottle;
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
			const bool getCanThrottle() const {return this->canThrottle;}
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
				canThrottle = value;
			}
			float kineticEnergy() const;
			float potentialEnergy() const;
			static int getNextStateIndex();
			static Body* getWorldBody();
	};
}
#include <G3D/CoordinateFrame.h>
namespace RBX {
class NativeGyro { char prefix[0x148]; float kP,kD; G3D::Vector3 maxTorque; G3D::CoordinateFrame cframe; public: void computeOrientation(Body*); void computeBalance(Body*); };
	void NativeGyro::computeOrientation(Body* body)
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



	void NativeGyro::computeBalance(Body* body)
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
		torqueBody.x -= (root->getBranchIBodyV3().x * angVelBody.x) * kD;
		torqueBody.z -= (root->getBranchIBodyV3().z * angVelBody.z) * kD;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;

		root->accumulateTorque(addedTorque);
	}


}

namespace RBX {
class RocketBase { public: virtual ~RocketBase(); char observedInstance[0x12c]; };
class RocketConnector { public: virtual void computeForce(float,bool)=0; char connectorData[8]; };
class RocketPart { char prefix[0x2c8]; Body* body; public: Body* getBody()const{return body;} const G3D::CoordinateFrame& getCoordinateFrame()const; };
class NativeRocket:public RocketBase,public RocketConnector {
 void* world; boost::weak_ptr<RocketPart> part;
 bool active; boost::shared_ptr<RocketPart> target; G3D::Vector3 targetOffset; float targetRadius; bool firedEvent;
 float maxThrust,kThrustP,kThrustD,maxSpeed,kTurnP,kTurnD; G3D::Vector3 maxTorque; float cartoonFactor;
 public: G3D::Vector3 turn(Body*,const G3D::Vector3&); virtual void computeForce(float,bool);
};
	G3D::Vector3 NativeRocket::turn(Body* body, const G3D::Vector3& targetDir)
	{
		G3D::Vector3 targetObjectSpace = body->getCoordinateFrame().vectorToObjectSpace(targetDir);

		Body* root = body->getRoot();
		G3D::Vector3 oldTorqueWorld = root->getBranchTorque();

		float desiredTorqueX = targetObjectSpace.y * root->getBranchIBodyV3().x * kTurnP;
		float desiredTorqueY = -(targetObjectSpace.x * root->getBranchIBodyV3().y * kTurnP);

		G3D::Vector3 torqueBody = body->getCoordinateFrame().vectorToObjectSpace(oldTorqueWorld);
		
		if (fabs(desiredTorqueX - torqueBody.x) < root->getBranchIBodyV3().x * maxTorque.x)
			torqueBody.x = desiredTorqueX;
		else
			torqueBody.x += desiredTorqueX;
		
		if (fabs(desiredTorqueY - torqueBody.y) < root->getBranchIBodyV3().y * maxTorque.y)
			torqueBody.y = desiredTorqueY;
		else
			torqueBody.y += desiredTorqueY;

		G3D::Vector3 angVelBody = body->getCoordinateFrame().vectorToObjectSpace(body->getVelocity().rotational);
		torqueBody.x -= (root->getBranchIBodyV3().x * angVelBody.x) * kTurnD;
		torqueBody.y -= (root->getBranchIBodyV3().y * angVelBody.y) * kTurnD;

		G3D::Vector3 addedTorque = body->getCoordinateFrame().vectorToWorldSpace(torqueBody) - oldTorqueWorld;
		root->accumulateTorque(addedTorque);

		return targetObjectSpace;
	}



}

namespace RBX {
	void NativeRocket::computeForce(const float dt, bool throttling)
	{
		if (!active)
			return;

		Body* body = part.lock()->getBody();
		

		G3D::Vector3 targetPos = target.get() ? target->getCoordinateFrame().pointToWorldSpace(targetOffset) : targetOffset;
		G3D::Vector3 targetDelta = targetPos - body->getCoordinateFrame().translation; // fabricated name, may change
		G3D::Vector3 targetDir = targetDelta.direction();
		G3D::Vector3 pAccel = targetDelta * kThrustP;
		Body* root = body->getRoot();

		G3D::Vector3 force = pAccel * root->getBranchMass();

		if (root->getVelocity().linear.squaredMagnitude() > maxSpeed * maxSpeed)
		{
			G3D::Vector3 dir = root->getVelocity().linear.direction();
			float dotProduct = dir.dot(force);
			if (dotProduct > 0.0f)
			{
				force -= dir * dotProduct;
				pAccel = dir * maxSpeed;
				G3D::Vector3 low = root->getVelocity().linear - pAccel;
				force -= (low * root->getBranchMass()) / dt;
			}
		}

		G3D::Vector3 adjustedVelocity = (root->getBranchMass() * kThrustD) * root->getVelocity().linear; // fabricated name, may change
		force -= adjustedVelocity;

		force -= body->getBranchForce();

		Math::fixDenorm(force);

		const G3D::Vector3 maxForce(maxThrust,maxThrust,maxThrust);
		const G3D::Vector3 minForce(-maxThrust,-maxThrust,-maxThrust);
		force = force.clamp(minForce,maxForce);

		root->accumulateForceAtBranchCofm(force);

		G3D::Vector3 unitForce = force.squaredMagnitude() > 0.000001f ? force.fastDirection() : G3D::Vector3::zero(); // fabricated name, may change
		G3D::Vector3 forceCartoon = unitForce * (1.0f - cartoonFactor); // fabricated name, may change
		G3D::Vector3 newDirection = forceCartoon + (targetDir * cartoonFactor); // fabricated name, may change
		turn(body, newDirection.direction());
	}


}

namespace RBX {
class NativeThrust:public RocketBase,public RocketConnector {
 void* world; boost::weak_ptr<RocketPart> part; G3D::Vector3 force,location;
 public: virtual void computeForce(float,bool);
};
void NativeThrust::computeForce(float dt,bool throttling){
 Body* body=part.lock()->getBody();
 G3D::Vector3 worldForce=body->getCoordinateFrame().vectorToWorldSpace(force);
 G3D::Vector3 worldPos=body->getCoordinateFrame().pointToWorldSpace(location);
 body->accumulateForce(worldForce,worldPos);
}
}
