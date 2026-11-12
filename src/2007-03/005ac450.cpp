// from server: 75% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/Mechanism.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/Mechanism.h"

#include "decomp.h"
#include "util/StlExtra.h"
#include "v8world/Assembly2.h"
#include "v8world/Primitive.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1005ecd0
// FUNCTION: ROBLOX 0x00671ea0
Mechanism* MechanismTracker::getMechanism()
{
	return mechanism;
}

// FUNCTION: WEBSERVICE 0x10127280
// FUNCTION: ROBLOX 0x005f1540
Mechanism* Mechanism::getMechanismFromPrimitive(const Primitive* primitive)
{
	if (primitive != NULL) {
		Assembly* assembly = primitive->getAssembly();

		if (assembly != NULL) {
			return assembly->getMechanism();
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x101272a0
// FUNCTION: ROBLOX 0x005f1560
bool MechanismTracker::tracking()
{
	return mechanism ? true : false;
}

// FUNCTION: WEBSERVICE 0x101272b0
// FUNCTION: ROBLOX 0x005f1570
void Mechanism::notifyMovingPrimitives()
{
	AssemblySet::iterator it;

	for (it = assemblies.begin(); it != assemblies.end(); ++it) {
		(*it)->notifyMoved();
	}
}

// FUNCTION: WEBSERVICE 0x10127320
// FUNCTION: ROBLOX 0x005f15e0
void Mechanism::insertAssembly(Assembly* a)
{
	assemblies.insert(a);

	a->setMechanism(this);
}

// FUNCTION: WEBSERVICE 0x10127350
// FUNCTION: ROBLOX 0x005f16d0
void Mechanism::removeAssembly(Assembly* a)
{
	assemblies.erase(a);

	a->setMechanism(NULL);
}

// FUNCTION: WEBSERVICE 0x10127370
// FUNCTION: ROBLOX 0x005f16f0
void Mechanism::absorb(Mechanism* smaller)
{
	while (smaller->assemblies.size() != 0) {
		Assembly* assembly = *smaller->assemblies.begin();

		smaller->removeAssembly(assembly);

		insertAssembly(assembly);
	}
}

// FUNCTION: WEBSERVICE 0x101274c0
// FUNCTION: ROBLOX 0x005f17d0
void MechanismTracker::stopTracking()
{
	if (mechanism != NULL) {
		fastRemoveShort(mechanism->trackers, this);

		mechanism = NULL;
	}
}

// FUNCTION: WEBSERVICE 0x101274f0
// FUNCTION: ROBLOX 0x005f1800
void MechanismTracker::setMechanism(Mechanism* m)
{
	stopTracking();

	if (m != NULL) {
		m->trackers.push_back(this);

		mechanism = m;
	}
}

// FUNCTION: WEBSERVICE 0x10127540
// FUNCTION: ROBLOX 0x005f1850
void MechanismTracker::transferTrackers(Mechanism* from, Mechanism* to)
{
	while (from->trackers.size() != 0) {
		MechanismTracker* tracker = from->trackers.back();

		tracker->setMechanism(to);
	}
}

} // namespace RBX
