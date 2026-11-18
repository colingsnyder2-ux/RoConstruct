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
	struct AssemblyPhysicsOn;
	struct AssemblyPhysicsOff;
	namespace HUMAN
	{
		class MovingNoPhysicsBase;
	}

	extern const char sPhysicsService[];

	class PhysicsService : public DescribedNonCreatable<PhysicsService, Instance, sPhysicsService>,
						   public Service,
						   public Listener<World, AssemblyPhysicsOn>,
						   public Listener<World, AssemblyPhysicsOff>
	{
		friend struct ::NativeServicesLayout; // tests/NativeServicesLayout.cpp offset asserts
		friend class HUMAN::MovingNoPhysicsBase; // release 0066ed50 calls the private onRemoved 005e9040 (decorated AAE)

	private:
		std::set<PartInstance*> parts;                                    // +0x138

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
