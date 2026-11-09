// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_d58a8bb22e88c505.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8kernel/IStage.h", "roc_unit_1ca1b106ba673e79.cpp")
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "roc_unit_ea83e629b1338927.cpp")
#include "v8datamodel/Feature.h"
#include "v8world/MotorJoint.h"
#include "v8world/World.h"
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

// Selected genuine static call contract; no Workspace object layout used here.
class Workspace { public: static World* getWorldIfInWorkspace(const Instance* context); };
	void VelocityMotor::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);

		setPart(0, dynamic_cast<Feature*>(this->getParent()));

		World* oldWorld = motorJoint()->getWorld();
		World* wsWorld = Workspace::getWorldIfInWorkspace(this);

		if (oldWorld != wsWorld)
		{
			if (oldWorld)
			{
				oldWorld->removeJoint(motorJoint());
				setPart(0, NULL);
				setPart(1, NULL);
				RBXASSERT(!motorJoint()->getWorld());
			}

			if (wsWorld)
			{
				wsWorld->insertJoint(motorJoint());
				RBXASSERT(motorJoint()->getWorld());
			}
		}
	}

}
