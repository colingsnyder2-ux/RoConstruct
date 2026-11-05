#pragma once
#include "v8world/RigidJoint.h"

namespace RBX
{
	class WeldJoint : public RigidJoint
	{
	private:
		virtual Joint::JointType getJointType() const
		{
			return WELD_JOINT;
		}
	public:
		//WeldJoint(const WeldJoint&);
		WeldJoint(Primitive* prim0, Primitive* prim1, const G3D::CoordinateFrame& _jointCoord0, const G3D::CoordinateFrame& _jointCoord1)
			: RigidJoint(prim0, prim1, _jointCoord0, _jointCoord1)
		{
		}
		WeldJoint()
			: RigidJoint()
		{
		}
		virtual ~WeldJoint() {}
	public:
		//WeldJoint& operator=(const WeldJoint&);
	  
	private:
		static bool compatibleSurfaces(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
	public:
		static WeldJoint* canBuildJoint(Primitive* p0, Primitive* p1, NormalId nId0, NormalId nId1);
	};
}