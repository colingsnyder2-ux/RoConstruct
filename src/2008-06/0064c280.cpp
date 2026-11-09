// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_f3d82a98e860a6cd.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/SleepStage.h", "roc_unit_e122b107650b8d44.cpp")
#pragma include_alias("v8world/Assembly.h", "roc_unit_c2191b1d8d68a719.cpp")
#pragma include_alias("v8world/Clump.h", "roc_unit_9da8b0a292a9525e.cpp")
#pragma include_alias("v8world/Primitive.h", "roc_unit_1deee9af9b5e9e77.cpp")
#pragma include_alias("v8kernel/Body.h", "roc_unit_fdeff9a4ea2b6152.cpp")
#pragma include_alias("v8world/Edge.h", "roc_unit_ad178cfd636587c6.cpp")
#include "v8world/SleepStage.h"
#include "v8world/SimJobStage.h"
#include "v8kernel/Body.h"
namespace RBX {
bool SleepStage::isMoving(Assembly* assembly) {
 SleepInfo* info = assembly->getSleepInfo();
 return info && (info->state == Sim::AWAKE || info->state == Sim::RECURSIVE_WAKE_PENDING || info->state == Sim::WAKE_PENDING);
}
bool SleepStage::atLeastOneAssemblyMoving(Assembly* a0, Assembly* a1)
{
	return isMoving(a0) || isMoving(a1);
}
Sim::EdgeState SleepStage::computeContactState(bool moving, bool touching, bool canCollide, bool wasTouching)
{
	if (moving) {
		return touching && canCollide ? Sim::TOUCHING : Sim::STEPPING;
	}

	if (wasTouching && touching && canCollide) {
		return Sim::TOUCHING_SLEEPING;
	}

	return Sim::SLEEPING;
}
void SleepStage::stepContacts(ContactList& contacts)
{
	
	
	
	

	
	
	
	

	for (int i = 0; i < contacts.size(); i++) {
		Contact* c = contacts[i];

		Primitive* p0 = c->getPrimitive(0);
		Primitive* p1 = c->getPrimitive(1);

		if (!(*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(this) + 0xd8)) || !p0->getBody()->getCanThrottle() || !p1->getBody()->getCanThrottle()) {
			bool moving = atLeastOneAssemblyMoving(p0->getAssembly(), p1->getAssembly());

			bool touching = c->step((*reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 0xdc)));

			bool canCollide = !(*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(p0) + 0xa8)) && !(*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(p0) + 0xab)) && !(*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(p1) + 0xa8)) && !(*reinterpret_cast<const bool*>(reinterpret_cast<const char*>(p1) + 0xab));

			// clang-format off
			Sim::EdgeState edgeState = c->getEdgeState(); bool wasTouching = edgeState == Sim::TOUCHING;
			// clang-format on

			Sim::EdgeState state = computeContactState(moving, touching, canCollide, wasTouching);

			if (state != edgeState) {
				switch (state) {
				case Sim::SLEEPING:
					(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x58)).push_back(c);
					break;

				case Sim::TOUCHING_SLEEPING:
					(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0xa0)).push_back(c);
					break;

				case Sim::STEPPING:
					(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x70)).push_back(c);
					break;

				case Sim::TOUCHING:
					(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x88)).push_back(c);
					break;
				}
			}
		}
	}

	changeContactState((*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x58)), Sim::SLEEPING);
	changeContactState((*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x70)), Sim::STEPPING);
	changeContactState((*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x88)), Sim::TOUCHING);
	changeContactState((*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0xa0)), Sim::TOUCHING_SLEEPING);
	(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x58)).resize(0);
	(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x70)).resize(0);
	(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0x88)).resize(0);
	(*reinterpret_cast<std::vector<Contact*>*>(reinterpret_cast<char*>(this) + 0xa0)).resize(0);
}
}
