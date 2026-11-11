// 2008-06 native RBX::JointsService (inactive); evidence in native-headers/v8datamodel/JointsService.h.
// Verified by tests/record_native_services.py.
#include "v8datamodel/JointsService.h"
#include "v8tree/Service.h"
#include <boost/thread/once.hpp>

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::JointInstance>;
