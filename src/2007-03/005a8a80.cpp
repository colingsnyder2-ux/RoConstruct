// from server: 97% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/SimJobStage.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/SimJobStage.h"

#include "decomp.h"
#include "v8kernel/Kernel.h"
#include "v8world/Assembly2.h"
#include "v8world/Primitive.h"

#include <algorithm>
#include <cstddef>
#include <functional>

namespace RBX {

// FUNCTION: WEBSERVICE 0x1011c900
void SimJobStage::onEdgeRemoving(Edge* e)
{
	e->removeFromKernel();

	e->removeFromStage(this);
}

// FUNCTION: WEBSERVICE 0x1011c990
SimJobStage::SimJobStage(IStage* upstream, World* world) : IWorldStage(upstream, new Kernel(this), world)
{
}

// FUNCTION: WEBSERVICE 0x1011ca60
void SimJobStage::notifyMovingPrimitives()
{
	std::for_each(mechanisms.begin(), mechanisms.end(), std::mem_fun(&Mechanism::notifyMovingPrimitives));
}

// FUNCTION: WEBSERVICE 0x1011cb40
void SimJobStage::destroyMechanism(Mechanism* m)
{
	Mechanism* next = mechanisms.size() > 1 ? nextMechanism(mechanisms, m) : NULL;

	MechanismTracker::transferTrackers(m, next);

	mechanisms.erase(m->myIt);

	delete m;
}

void SimJobStage::insertMechanism(Mechanism* mechanism)
{
	mechanisms.push_back(mechanism);

	mechanism->myIt = --mechanisms.end();
}

// FUNCTION: WEBSERVICE 0x1011cba0
void SimJobStage::onAssemblyAdded(Assembly* a)
{
	a->putInPipeline(this);

	Mechanism* mechanism = new Mechanism();
	mechanism->insertAssembly(a);

	insertMechanism(mechanism);

	a->putInKernel(getKernel());
}

// FUNCTION: WEBSERVICE 0x1011cc80
void SimJobStage::onAssemblyRemoving(Assembly* a)
{
	a->removeFromKernel();

	Mechanism* mechanism = a->getMechanism();

	mechanism->removeAssembly(a);

	if (mechanism->getAssemblies().size() == 0) {
		destroyMechanism(mechanism);
	}

	a->removeFromStage(this);
}

// FUNCTION: WEBSERVICE 0x1011ccc0
void SimJobStage::combineMechanisms(Edge* e)
{
	Assembly* a0 = e->getPrimitive(0)->getAssembly();
	Assembly* a1 = e->getPrimitive(1)->getAssembly();

	Mechanism* m0 = a0->getMechanism();
	Mechanism* m1 = a1->getMechanism();

	if (m0 != m1) {
		Mechanism* bigger = m0->getAssemblies().size() > m1->getAssemblies().size() ? m0 : m1;
		Mechanism* smaller = bigger == m0 ? m1 : m0;

		bigger->absorb(smaller);

		destroyMechanism(smaller);
	}
}

// FUNCTION: WEBSERVICE 0x1011cd20
void SimJobStage::onEdgeAdded(Edge* e)
{
	e->putInPipeline(this);

	if (e->getEdgeType() == Edge::JOINT) {
		Assembly* a0 = e->getPrimitive(0)->getAssembly();
		Assembly* a1 = e->getPrimitive(1)->getAssembly();

		if (a0->inOrDownstreamOfStage(this) && a1->inOrDownstreamOfStage(this)) {
			combineMechanisms(e);
		}
	}

	e->putInKernel(getKernel());
}

} // namespace RBX
