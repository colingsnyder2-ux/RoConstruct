// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_cd83c50bcee01adf.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <boost/shared_ptr.hpp>
#define private public
#include "util/IRenderable.h"
#undef private
#include "v8datamodel/JointInstance.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8world/World.h"

namespace RBX { struct JointsServiceExePad { virtual void exePadSlot(); char exePad[0x4]; }; }
namespace RBX
{
	class JointsService : public NonFactoryProduct<Instance, NULL>, 
						  public Service,
						  public IRenderableBucket,
						  public JointsServiceExePad,
						  public Listener<World, AutoJoin>,
						  public Listener<World, AutoDestroy>
	{
	public:
		World* world;

	private:
		virtual void onDescendentAdded(Instance* instance);
		virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);

		virtual bool askAddChild(const Instance* instance) const
		{
			return dynamic_cast<const JointInstance*>(instance) != NULL;
		}

		virtual XmlElement* write()
		{
			return NULL;
		}

		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
		virtual void onEvent(const World* source, AutoDestroy event);
		virtual void onEvent(const World* source, AutoJoin event);
	public:
		JointsService()
			: world(NULL)
		{
			setName("JointsService");
		}
	};
}

#include "v8datamodel/Workspace.h"

namespace RBX
{
	void JointsService::onEvent(const World* source, AutoDestroy event)
	{
		RBXASSERT(event.joint != NULL);

		IJointOwner* jointOwner = event.joint->getJointOwner();
		RBXASSERT(jointOwner);

		if (jointOwner)
			static_cast<JointInstance*>(jointOwner)->setParent(NULL);
	}

	void JointsService::onEvent(const World* source, AutoJoin event)
	{
		RBXASSERT(event.joint != NULL);
		RBXASSERT(event.joint->getJointOwner() == NULL);

		boost::shared_ptr<JointInstance> ji;
		
		switch (event.joint->getJointType())
		{
		case Joint::SNAP_JOINT:
			ji = Creatable::create<Snap>(event.joint);
			break;
		case Joint::WELD_JOINT:
			ji = Creatable::create<Weld>(event.joint);
			break;
		case Joint::GLUE_JOINT:
			ji = Creatable::create<Glue>(event.joint);
			break;
		case Joint::ROTATE_JOINT:
			ji = Creatable::create<Rotate>(event.joint);
			break;
		case Joint::ROTATE_P_JOINT:
			ji = Creatable::create<RotateP>(event.joint);
			break;
		case Joint::ROTATE_V_JOINT:
			ji = Creatable::create<RotateV>(event.joint);
			break;
		default:
			RBXASSERT(0);
		}

		ji->setParent(this);
	}

	// exe layout: Notifier<World,AutoDestroy> at World+0x20, Workspace world at 0x2e4
	struct ExWorkspace { char pad[0x2e4]; World* world; };

	static inline void exDisconnectDestroy(World* const& notifier, Listener<World, AutoDestroy>* listener)
	{
		if (notifier)
			reinterpret_cast<const Notifier<World, AutoDestroy>*>(reinterpret_cast<const char*>(notifier) + 0x20)->removeListener(listener);
	}

	static inline void exConnectDestroy(World* const& notifier, Listener<World, AutoDestroy>* listener)
	{
		if (notifier)
			reinterpret_cast<const Notifier<World, AutoDestroy>*>(reinterpret_cast<const char*>(notifier) + 0x20)->addListener(listener);
	}

	void JointsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<World,AutoJoin>::disconnect(world, this);
		exDisconnectDestroy(world, this);

		world = NULL;
		if (Workspace* workspace = ServiceProvider::find<Workspace>(newProvider))
			world = reinterpret_cast<ExWorkspace*>(workspace)->world;

		Notifier<World,AutoJoin>::connect(world, this);
		exConnectDestroy(world, this);
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

