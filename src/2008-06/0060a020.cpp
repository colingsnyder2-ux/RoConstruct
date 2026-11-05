// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_bae01af1f5e52a67.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "roc_unit_ea83e629b1338927.cpp")
#include "v8datamodel/Feature.h"
#include "v8world/MotorJoint.h"
namespace RBX {
	static inline Primitive* _getParentPrimitive(Instance* instance)
	{
		if (instance)
		{
			PartInstance* part = dynamic_cast<PartInstance*>(instance->getParent());

			if (part)
				return part->getPrimitive();
		}

		return NULL;
	}

	void VelocityMotor::setPart(int i, Feature* feature)
	{
		Primitive* prim = _getParentPrimitive(feature);

		G3D::CoordinateFrame c = feature ? feature->computeLocalCoordinateFrame() : G3D::CoordinateFrame();

		if (motorJoint()->getPrimitive(i) != prim)
		{
			motorJoint()->setPrimitive(i, prim);

			if (prim)
				motorJoint()->setJointCoord(i, c);
		}
	}

}
