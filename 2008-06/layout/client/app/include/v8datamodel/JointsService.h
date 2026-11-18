#pragma once
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8world/World.h"
#include "v8datamodel/JointInstance.h"
#include "util/IRenderable.h"

struct NativeServicesLayout;

namespace RBX
{
	class JointsService : public NonFactoryProduct<Instance, NULL>,
						  public Service,
						  public IRenderableBucket,
						  public Listener<World, AutoJoin>,
						  public Listener<World, AutoDestroy>
	{
		friend struct ::NativeServicesLayout; // tests/NativeServicesLayout.cpp offset asserts

	public:
		World* world;                                                     // +0x150

	private:
		virtual void onDescendentAdded(Instance* instance);              // 005e54c0
		virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance); // 005e5520

		virtual bool askAddChild(const Instance* instance) const          // 004afb30
		{
			return dynamic_cast<const JointInstance*>(instance) != NULL;
		}

		virtual XmlElement* write()                                       // folded 00416690
		{
			return NULL;
		}

		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005e5b50
		virtual void onEvent(const World* source, AutoDestroy event);     // 005e5500
		virtual void onEvent(const World* source, AutoJoin event);        // 005e5860

	public:
		JointsService()                                                   // 004afa30
			: world(NULL)
		{
			setName("JointsService");
		}
	};
}
