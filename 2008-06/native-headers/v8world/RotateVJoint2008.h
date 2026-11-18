#pragma once
// 2008-06 RBX::RotateVJoint layout under a non-colliding name so a datamodel unit (which reaches the donor
// v8world/RotateJoint.h through v8datamodel/JointInstance.h) can construct the real 2008 joint.
// INFERRED: binary evidence in v8world/Joints2008.h (sizes: RotateJoint 0xc4, RotatePJoint / RotateVJoint 0xc8;
// RTTI RotateVJoint 0083e17c; channelValue at +0xc4 cleared by the RotateV constructors 005e4dd0 / 00645dd0).

#include "v8world/RotateJoint.h"

namespace RBX
{
	// INFERRED: the 2008 RotateVJoint is RotateJoint (0xc4) plus a float channelValue at +0xc4, total 0xc8;
	// its default ctor calls RotateJoint() 00645a70 and zeroes channelValue inline (fldz / fstp at 005e4e10).
	class RotateVJoint2008 : public RotateJoint
	{
	protected:
		float channelValue;   // +0xc4
	public:
		RotateVJoint2008()
			: RotateJoint(), channelValue(0.0f)
		{
		}
	};
}
