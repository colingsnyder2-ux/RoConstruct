#pragma once
#include "v8datamodel/JointInstance.h"
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "util/Events.h"
#include "util/IRenderable.h"

namespace RBX
{
    class World;
    struct AutoJoin;
    struct AutoDestroy;
	class JointsService : public NonFactoryProduct<Instance, NULL>, 
						  public Service,
						  public IRenderableBucket,
						  public Listener<World, AutoJoin>,
						  public Listener<World, AutoDestroy>
	{
	public:
		World* world;

	private:
		virtual void onDescendentAdded(Instance* instance);
		virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);

		virtual bool askAddChild(const Instance* instance) const;
		virtual XmlElement* write();

		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
		virtual void onEvent(const World* source, AutoDestroy event);
		virtual void onEvent(const World* source, AutoJoin event);
	public:
		JointsService(); // Body parked pending target constructor evidence.
	};
}
