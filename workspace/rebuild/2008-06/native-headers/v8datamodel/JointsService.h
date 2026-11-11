#pragma once
// >>> native-status (generated) -- do not edit >>>
// JointsService | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 74c25c69 | roc native-status --write
// 2008-06 native RBX::JointsService (inactive). Shape after the donor tools/rbxgs JointsService.h; every base, field
// and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 00824acc .?AVJointsService@RBX@@ -> NonFactoryProduct<Instance, 0> (no class descriptor, no
//              class-name array), Listener<World, AutoJoin> (mdisp 0x130, vtable 00824a44: onEvent 005e5860),
//              Listener<World, AutoDestroy> (mdisp 0x134, vtable 00824a38: onEvent 005e5500), Service and
//              IRenderableBucket (both mdisp 0x138; Service is empty).
//   size       0x154: ServiceProvider::create<JointsService> 004b0df0 allocates 0x154 and calls the constructor
//              004afa30, which zeroes the two IndexArrays of IRenderableBucket (+0x138..+0x14c), stores the twelve
//              vtables and zeroes world (+0x150), then setName("JointsService") (string 00824b0c).
//   dtor       004afc00 runs ~IRenderableBucket 005dd2c0 on +0x138, then ~Instance 0055a540 (deleting 004afc50).
//   vtable     slot 2 askAddChild 004afb30 (dynamic_cast to JointInstance), slot 5 onDescendentAdded 005e54c0,
//              slot 6 onDescendentRemoving 005e5520, slot 12 onServiceProvider 005e5b50, slot 14 write (folded
//              return-NULL body 00416690).
//   world      onServiceProvider 005e5b50 disconnects Notifier<World, AutoJoin> (World +0) and
//              Notifier<World, AutoDestroy> (World +0x20) from world (+0x150), then sets world from
//              ServiceProvider::find<Workspace>(newProvider) (Workspace +0x2e4); it does not call
//              Instance::onServiceProvider in 2008.
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
