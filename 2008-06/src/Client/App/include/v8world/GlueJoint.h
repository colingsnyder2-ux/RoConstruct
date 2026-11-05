#pragma once
#include <g3d/coordinateframe.h>
#include "v8world/MultiJoint.h"
#include "util/Face.h"
#include "util/NormalId.h"

namespace RBX
{
	class Primitive;
	class Kernel;

	class GlueJoint : public MultiJoint
	{
	private:
		Face overlapInP0;
		Face overlapInP1;
  
	private:
		float getMaxForce();
		virtual void putInKernel(Kernel*);
		virtual Joint::JointType getJointType() const
		{
			return GLUE_JOINT;
		}
		virtual bool isBreakable() const
		{
			return true;
		}
	public:
		//GlueJoint(const GlueJoint&);
		GlueJoint(Primitive*, Primitive*, const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
		GlueJoint();
		virtual ~GlueJoint() {}
  
	private:
		static bool compatibleSurfaces(Primitive*, Primitive*, NormalId, NormalId);
	public:
		static GlueJoint* canBuildJoint(Primitive*, Primitive*, NormalId, NormalId);
	};
}
