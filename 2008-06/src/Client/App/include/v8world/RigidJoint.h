#pragma once
#include "v8world/Joint.h"

namespace RBX
{
	class RigidJoint : public Joint
	{
	private:
		// these seem to be the same as Joint
		virtual Joint::JointType getJointType() const
		{
			RBXASSERT(0);
			return NO_JOINT;
		}
		virtual bool isBroken() const
		{
			return false;
		}
	public:
		//RigidJoint(const RigidJoint&);
		RigidJoint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0, const G3D::CoordinateFrame& _jointCoord1)
			: Joint(prim0, prim1, _jointCoord0, _jointCoord1)
		{
		}
		RigidJoint()
			: Joint()
		{
		}
		virtual ~RigidJoint() {}
	public:
		virtual bool isAligned();
		virtual G3D::CoordinateFrame align(Primitive* pMove, Primitive* pStay);
		G3D::CoordinateFrame getChildInParent(Primitive* parent, Primitive* child);
		//RigidJoint& operator=(const RigidJoint&);
  
	private:
		static bool jointIsRigid(Joint* j)
		{
			JointType type = j->getJointType();
			return type == WELD_JOINT || type == SNAP_JOINT;
		}
	protected:
		static void faceIdToCoords(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1, G3D::CoordinateFrame& c0, G3D::CoordinateFrame& c1);
	public:
		static bool isRigidJoint(Edge* e)
		{
			return Joint::isJoint(e) && jointIsRigid(rbx_static_cast<Joint*>(e));
		}
	};
}
