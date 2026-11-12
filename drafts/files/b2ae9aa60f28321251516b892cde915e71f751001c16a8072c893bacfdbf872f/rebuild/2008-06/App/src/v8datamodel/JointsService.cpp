// 2008-06 native RBX::JointsService (inactive); evidence in native-headers/v8datamodel/JointsService.h.
// Verified by tests/record_native_services.py.
#include "v8datamodel/JointsService.h"
#include "v8datamodel/Workspace.h"

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

	// 005e5b50: detach both World notifier listeners from the old world, then take the new provider's
	// workspace world and attach them again. oldProvider is unused.
	// Not exact (156 vs 156 bytes, evaluation order only): the original expands each dynamic_cast
	// argument (null-guarded lea) BEFORE loading world; this build loads world first and eliminates
	// the guard. Parked 2026-11-12 after two source-shape hypotheses (inline vs local-first); next
	// proof: a construct that forces argument-before-receiver evaluation of the dynamic_cast.
	void JointsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (world)
		{
			Listener<World, AutoJoin>* joinListener = dynamic_cast<Listener<World, AutoJoin>*>(this);
			static_cast<Notifier<World, AutoJoin>*>(world)->removeListener(joinListener);
			Listener<World, AutoDestroy>* destroyListener = dynamic_cast<Listener<World, AutoDestroy>*>(this);
			static_cast<Notifier<World, AutoDestroy>*>(world)->removeListener(destroyListener);
		}
		world = NULL;
		if (newProvider)
		{
			Workspace* workspace = ServiceProvider::create<Workspace>(newProvider);
			if (workspace)
				world = workspace->getWorld();
		}
		if (world)
		{
			Listener<World, AutoJoin>* joinListener = dynamic_cast<Listener<World, AutoJoin>*>(this);
			static_cast<Notifier<World, AutoJoin>*>(world)->addListener(joinListener);
			Listener<World, AutoDestroy>* destroyListener = dynamic_cast<Listener<World, AutoDestroy>*>(this);
			static_cast<Notifier<World, AutoDestroy>*>(world)->addListener(destroyListener);
		}
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
