// =============================================================================
// PhysicsService.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/PhysicsService.h
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
#include "reflection/reflection.h"
#include <set>

struct NativeServicesLayout;

namespace RBX
{
	class World;
	class PartInstance;
	namespace Network
	{
		class PhysicsSender;
	}
	struct AssemblyPhysicsOn;
	struct AssemblyPhysicsOff;
	namespace HUMAN
	{
		class MovingNoPhysicsBase;
	}
	namespace Reflection
	{
		template<typename Class, typename CallbackSignature> class SignalDesc;
	}

	extern const char sPhysicsService[];

	class PhysicsService : public DescribedNonCreatable<PhysicsService, Instance, sPhysicsService>,
						   public Service,
						   public Listener<World, AssemblyPhysicsOn>,
						   public Listener<World, AssemblyPhysicsOff>
	{
		friend struct ::NativeServicesLayout; // tests/NativeServicesLayout.cpp offset asserts
		friend class HUMAN::MovingNoPhysicsBase; // release 0066ed50 calls the private onRemoved 005e9040 (decorated AAE)
		// INFERRED: PhysicsSender::step 004cd920 walks parts and connects eventAdded.
		friend class Network::PhysicsSender;

	private:
		std::set<PartInstance*> parts;                                    // +0x138

		static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventAdded;   // 0097abec
		static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventRemoved; // 0097ac20

		void onAdded(PartInstance* part);                                 // 005e8f70
		void onRemoved(PartInstance* part);                               // 005e9040

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005e8ec0
		virtual void onEvent(const World* source, AssemblyPhysicsOn event);  // 005e9110
		virtual void onEvent(const World* source, AssemblyPhysicsOff event); // 005e9130

	public:
		PhysicsService()                                                  // 004cd5b0
		{
			setName("PhysicsService");
		}
		~PhysicsService();                                                // 005e8d30 (deleting 004cd740)
	};
}
