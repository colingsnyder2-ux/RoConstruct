// =============================================================================
// JointsService.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/JointsService.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
