#pragma once
#include "v8world/RigidJoint.h"

namespace RBX
{
	class SnapJoint : public RigidJoint
	{
	private:
		virtual Joint::JointType getJointType() const
		{
			return SNAP_JOINT;
		}
	public:
		//SnapJoint(const SnapJoint&);
		SnapJoint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0, const G3D::CoordinateFrame& _jointCoord1)
			: RigidJoint(prim0, prim1, _jointCoord0, _jointCoord1)
		{
		}
		SnapJoint()
			: RigidJoint()
		{
		}
		virtual ~SnapJoint() {}
	public:
		//SnapJoint& operator=(const SnapJoint&);
	  
	private:
		static bool compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
	public:
		static SnapJoint* canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
	};
}