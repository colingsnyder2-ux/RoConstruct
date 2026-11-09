// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_66cef798498ea6c7.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/SleepStage.h", "roc_unit_e122b107650b8d44.cpp")
#pragma include_alias("v8world/Assembly.h", "roc_unit_c2191b1d8d68a719.cpp")
#pragma include_alias("v8world/Clump.h", "roc_unit_9da8b0a292a9525e.cpp")
#pragma include_alias("v8world/Primitive.h", "roc_unit_1deee9af9b5e9e77.cpp")
#pragma include_alias("v8kernel/Body.h", "roc_unit_19ae4f372bbfbfe0.cpp")
#include "v8world/SleepStage.h"
#include "v8world/SimJobStage.h"
#include "v8kernel/Body.h"
namespace RBX {
Sim::AssemblyState SleepStage::getState(Assembly* assembly)
{
	return assembly->inPipeline() && assembly->inOrDownstreamOfStage(this) ? assembly->getSleepInfo()->state
																		   : Sim::ANCHORED;
}

SleepStage::AssemblySet* SleepStage::stateToSet(Sim::AssemblyState state)
{
	switch (state) {
	case Sim::RECURSIVE_WAKE_PENDING:
		return reinterpret_cast<AssemblySet*>(reinterpret_cast<char*>(this) + 0xe0);

	case Sim::WAKE_PENDING:
		return reinterpret_cast<AssemblySet*>(reinterpret_cast<char*>(this) + 0x100);

	case Sim::SLEEPING_CHECKING:
		return reinterpret_cast<AssemblySet*>(reinterpret_cast<char*>(this) + 0x140);

	case Sim::SLEEPING_DEEPLY:
		return reinterpret_cast<AssemblySet*>(reinterpret_cast<char*>(this) + 0x160);

	default:
		return reinterpret_cast<AssemblySet*>(reinterpret_cast<char*>(this) + 0x120);
	}
}

void SleepStage::resetSleepCount(Assembly* assembly)
{
	assembly->getSleepInfo()->sleepCount = 0;
}

void SleepStage::changeAssemblyState(Assembly* a, Sim::AssemblyState newState)
{
	Sim::AssemblyState oldState = getState(a);

	AssemblySet* oldSet = stateToSet(oldState);
	AssemblySet* newSet = stateToSet(newState);

	oldSet->erase(a);

	newSet->insert(a);

	if ((oldState == Sim::SLEEPING_CHECKING || oldState == Sim::SLEEPING_DEEPLY) &&
		newState != Sim::SLEEPING_CHECKING && newState != Sim::SLEEPING_DEEPLY) {
		a->getAssemblyPrimitiveConst()->getBody()->resetAccumulators();
	}

	if (newState == Sim::AWAKE) {
		if (!a->downstreamOfStage(this)) {
			static_cast<SimJobStage*>(getDownstream())->onAssemblyAdded(a);

			if (!externalBodyForceAdded) {
				const Primitive* primitive = a->getAssemblyPrimitiveConst();
			}
		}
	}
	else if (newState == Sim::SLEEPING_CHECKING || newState == Sim::SLEEPING_DEEPLY) {
		a->getAssemblyPrimitiveConst()->getBody()->setVelocity(Velocity::zero());

		if (a->downstreamOfStage(this)) {
			static_cast<SimJobStage*>(getDownstream())->onAssemblyRemoving(a);
		}
	}

	resetSleepCount(a);
	a->getSleepInfo()->state = newState;
}

void SleepStage::wakeEvent(Assembly* a)
{
	Sim::AssemblyState state = getState(a);

	if (state != Sim::ANCHORED && state != Sim::WAKE_PENDING && state != Sim::RECURSIVE_WAKE_PENDING) {
		changeAssemblyState(a, Sim::WAKE_PENDING);
	}
}

void SleepStage::recursiveWakeEvent(Assembly* a)
{
	Sim::AssemblyState state = getState(a);

	if (state != Sim::ANCHORED && state != Sim::RECURSIVE_WAKE_PENDING) {
		changeAssemblyState(a, Sim::RECURSIVE_WAKE_PENDING);
	}
}
}
