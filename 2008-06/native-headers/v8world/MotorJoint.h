#pragma once
#include "v8kernel/Link.h"
#include "v8world/Joint.h"

namespace RBX
{
	class MotorJoint : public Joint
	{
	private:
		RevoluteLink* link;
		int polarity;
		float currentAngle;
	public:
		float maxVelocity;
		float desiredAngle;
  
	private:
		virtual Joint::JointType getJointType() const
		{
			return MOTOR_JOINT;
		}
		virtual bool isBroken() const
		{
			return false;
		}
		virtual bool isAligned();
		void setJointAngle(float value);
	public:
		float getCurrentAngle() const
		{
			return currentAngle;
		}
		void setCurrentAngle(float value);
		G3D::CoordinateFrame getMeInOther(Primitive* me);
		virtual void stepUi(int uiStepId);
	public:
		//MotorJoint(const MotorJoint&);
		MotorJoint();
		virtual ~MotorJoint();
	public:
		size_t hashCode() const;
		RevoluteLink* resetLink();
		//MotorJoint& operator=(const MotorJoint&);
  
	public:
		static bool isMotorJoint(Edge* e)
		{
			return Joint::isJoint(e) && rbx_static_cast<Joint*>(e)->getJointType() == MOTOR_JOINT;
		}
	};
}
// 2008-06 native header port of rbxgs App/include/v8world/MotorJoint.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
