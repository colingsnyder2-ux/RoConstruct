// 2008-06 native RBX::JointsService (inactive); evidence in native-headers/v8datamodel/JointsService.h.
// Verified by tests/record_native_services.py.
// >>> native-status (generated) -- do not edit >>>
// JointsService | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 9119c1e2 | roc native-status --write
#include "v8datamodel/JointsService.h"

namespace RBX
{
	// 005e5500: no assertion code in 2008; the owner is cast back to its JointInstance and unparented.
	void JointsService::onEvent(const World* source, AutoDestroy event)
	{
		IJointOwner* jointOwner = event.joint->getJointOwner();

		if (jointOwner)
			static_cast<JointInstance*>(jointOwner)->setParent(NULL);
	}

	// 005e5860: jump table on getJointType() (vtable +0x14); ANCHOR_JOINT and others fall through. The joint is read
	// once into a local (esi holds it across all six create calls; this is spilled instead).
	void JointsService::onEvent(const World* source, AutoJoin event)
	{
		Joint* joint = event.joint;
		boost::shared_ptr<JointInstance> ji;

		switch (joint->getJointType())
		{
		case Joint::SNAP_JOINT:
			ji = Creatable<Instance>::create<Snap>(joint);
			break;
		case Joint::WELD_JOINT:
			ji = Creatable<Instance>::create<Weld>(joint);
			break;
		case Joint::GLUE_JOINT:
			ji = Creatable<Instance>::create<Glue>(joint);
			break;
		case Joint::ROTATE_JOINT:
			ji = Creatable<Instance>::create<Rotate>(joint);
			break;
		case Joint::ROTATE_P_JOINT:
			ji = Creatable<Instance>::create<RotateP>(joint);
			break;
		case Joint::ROTATE_V_JOINT:
			ji = Creatable<Instance>::create<RotateV>(joint);
			break;
		}

		ji->setParent(this);
	}

	void JointsService::onDescendentAdded(Instance* instance)
	{
		Instance::onDescendentAdded(instance);

		IRenderable* renderable = dynamic_cast<IRenderable*>(instance);
		if (renderable)
			onAdded(renderable);
	}

	void JointsService::onDescendentRemoving(const boost::shared_ptr<Instance>& instance)
	{
		IRenderable* renderable = dynamic_cast<IRenderable*>(instance.get());
		if (renderable)
			onRemoving(renderable);

		Instance::onDescendentRemoving(instance);
	}
}
