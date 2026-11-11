// 2008-06 native row of the physics-replication sender unit inside 004c8000..004d4000 (inactive): the static
// ServiceProvider::create<PhysicsService>(const Instance*) 004cd8d0 that PhysicsSender::step 004cd920 calls
// (004cd94f) before shared_from 00618a40. Verified by tests/record_native_app_unit4c8_2008.py.
//
// 004cd8d0 (65 B, cdecl): walks the context up through Instance::getParent (+0x104) until __RTDynamicCast(context,
// 0, Instance 0092907c, ServiceProvider 0092e15c, 0) succeeds, then tail-jumps to the member create<PhysicsService>()
// const 004cd7e0 (counted by world-service-actions-secure-trial.json); NULL when no provider is found. Same definition
// as LocalBackpack2008.cpp / SoundServiceProvider.cpp use for their own service types. Headers are read-only here.
// >>> native-status (generated) -- do not edit >>>
// AppUnit4C8_2008PhysicsServiceCreate | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 26336bc4 | roc native-status --write
#include "v8datamodel/PhysicsService.h"

namespace RBX
{
	template<class Class> Class* ServiceProvider::create(const Instance* context)
	{
		while (context)
		{
			if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(context))
				return provider->create<Class>();
			context = context->getParent();
		}
		return NULL;
	}

	template PhysicsService* ServiceProvider::create<PhysicsService>(const Instance* context);
}
