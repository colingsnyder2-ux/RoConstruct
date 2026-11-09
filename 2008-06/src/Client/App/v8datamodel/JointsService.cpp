#include "v8datamodel/JointsService.h"
#include "v8datamodel/Workspace.h"

namespace RBX
{
	void JointsService::onEvent(const World* source, AutoDestroy event)
	{

		IJointOwner* jointOwner = event.joint->getJointOwner();

		if (jointOwner)
			static_cast<JointInstance*>(jointOwner)->setParent(NULL);
	}

	void JointsService::onEvent(const World* source, AutoJoin event)
	{
		Joint* joint = event.joint;
		boost::shared_ptr<JointInstance> ji;
		
		switch (joint->getJointType())
		{
		case Joint::SNAP_JOINT:
			ji = Creatable::create<Snap>(joint);
			break;
		case Joint::WELD_JOINT:
			ji = Creatable::create<Weld>(joint);
			break;
		case Joint::GLUE_JOINT:
			ji = Creatable::create<Glue>(joint);
			break;
		case Joint::ROTATE_JOINT:
			ji = Creatable::create<Rotate>(joint);
			break;
		case Joint::ROTATE_P_JOINT:
			ji = Creatable::create<RotateP>(joint);
			break;
		case Joint::ROTATE_V_JOINT:
			ji = Creatable::create<RotateV>(joint);
			break;
		}

		ji->setParent(this);
	}

	void JointsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<World,AutoJoin>::disconnect(world, this);
		Notifier<World,AutoDestroy>::disconnect(world, this);

		world = NULL;
		if (Workspace* workspace = ServiceProvider::find<Workspace>(newProvider))
			world = workspace->getWorld();

		Notifier<World,AutoJoin>::connect(world, this);
		Notifier<World,AutoDestroy>::connect(world, this);
	}

	JointsService::~JointsService()
	{
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
