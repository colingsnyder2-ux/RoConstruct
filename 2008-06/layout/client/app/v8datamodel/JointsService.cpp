#include "v8datamodel/JointsService.h"
#include "v8datamodel/Workspace.h"
#include "v8tree/Service.h"
#include <boost/thread/once.hpp>

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

	void JointsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<World, AutoJoin>::disconnect(world, this);
		Notifier<World, AutoDestroy>::disconnect(world, this);
		world = NULL;
		if (newProvider)
		{
			Workspace* workspace = ServiceProvider::create<Workspace>(newProvider);
			if (workspace)
				world = workspace->getWorld();
		}
		Notifier<World, AutoJoin>::connect(world, this);
		Notifier<World, AutoDestroy>::connect(world, this);
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

	// ServiceProvider find (unsplit; uses explicit name since JointsService is NonFactoryProduct<Instance,NULL>)
	template<class Class> size_t ServiceProvider::doGetClassIndex() {
		static size_t index = newIndex();
		return index;
	}
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex() {
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}
	template<> JointsService* ServiceProvider::find<JointsService>() const {
		size_t index = getClassIndex<JointsService>();
		if (index + 1 > serviceArray.size()) {
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
		} else {
			JointsService* service = static_cast<JointsService*>(serviceArray[index].get());
			if (service) return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(Name::declare("JointsService", -1));
		if (!item) return NULL;
		serviceArray[index] = item;
		return static_cast<JointsService*>(item.get());
	}
}

template class boost::shared_ptr<RBX::JointInstance>;
