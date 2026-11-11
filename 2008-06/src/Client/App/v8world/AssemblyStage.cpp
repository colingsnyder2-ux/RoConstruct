// Source-derived world pipeline port from openrbx v8world/AssemblyStage2.cpp.
// June anchor swap is evidenced at 0064cc40/0064ccf0; full ABI/physics parity remains unproven.
// >>> native-status (generated) -- do not edit >>>
// AssemblyStage | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 04f4a9d1 | roc native-status --write
#include "v8world/AssemblyStage.h"

#include "v8world/Assembly.h"
#include "v8world/Contact.h"
#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include "v8world/SleepStage.h"

#include <cstddef>

namespace RBX {

// FUNCTION: WEBSERVICE 0x100d7a70 FOLDED
IStage::StageType AssemblyStage::getStageType()
{
	return ASSEMBLY_STAGE;
}

// FUNCTION: WEBSERVICE 0x10126de0
void AssemblyStage::wakeAssembly(Assembly* a)
{
	static_cast<SleepStage*>(getDownstream())->onWakeUpRequest(a, false);
}

// FUNCTION: WEBSERVICE 0x10126e00
void AssemblyStage::stepUi(int uiStepId)
{
	for (std::set<Assembly*>::iterator it = assemblies.begin(); it != assemblies.end(); ++it) {
		(*it)->stepUi(uiStepId);
	}

	for (std::set<Joint*>::iterator it = joints.begin(); it != joints.end(); ++it) {
		(*it)->stepUi(uiStepId);
	}
}

// FUNCTION: WEBSERVICE 0x10126ee0
void AssemblyStage::onAssemblyAdded(Assembly* assembly)
{
	assembly->putInPipeline(this);

	assemblies.insert(assembly);

	static_cast<SleepStage*>(getDownstream())->onAssemblyAdded(assembly);
}

void AssemblyStage::onJointAdded(Joint* joint)
{
	if (joint->canStepUi()) {
		joints.insert(joint);
	}
}

void AssemblyStage::onJointRemoving(Joint* joint)
{
	joints.erase(joint);

	joint->canStepUi();
}

// FUNCTION: WEBSERVICE 0x10126f20
void AssemblyStage::onEdgeAdded(Edge* e)
{
	e->putInPipeline(this);

	if (e->getEdgeType() == Edge::CONTACT) {
		Joint* joint = Primitive::getJoint(e->getPrimitive(0), e->getPrimitive(1));

		if (joint != NULL && joint->downstreamOfStage(this)) {
			return;
		}

		getDownstreamWS()->onEdgeAdded(e);
	}
	else {
		Contact* contact = Primitive::getContact(e->getPrimitive(0), e->getPrimitive(1));

		if (contact != NULL && contact->downstreamOfStage(this)) {
			getDownstreamWS()->onEdgeRemoving(contact);
		}

		getDownstreamWS()->onEdgeAdded(e);

		onJointAdded(static_cast<Joint*>(e));
	}
}

// FUNCTION: WEBSERVICE 0x10127000
AssemblyStage::~AssemblyStage()
{
}

// FUNCTION: WEBSERVICE 0x101270c0
void AssemblyStage::onAssemblyRemoving(Assembly* assembly)
{
	static_cast<SleepStage*>(getDownstream())->onAssemblyRemoving(assembly);

	assemblies.erase(assembly);

	assembly->removeFromStage(this);
}

// FUNCTION: WEBSERVICE 0x101270f0
void AssemblyStage::onEdgeRemoving(Edge* e)
{
	if (e->downstreamOfStage(this)) {
		getDownstreamWS()->onEdgeRemoving(e);
	}

	if (e->getEdgeType() != Edge::CONTACT) {
		Joint* joint = static_cast<Joint*>(e);

		onJointRemoving(joint);

		Contact* contact = Primitive::getContact(e->getPrimitive(0), e->getPrimitive(1));

		if (contact != NULL && contact->inStage(this)) {
			getDownstreamWS()->onEdgeAdded(contact);
		}
	}

	e->removeFromStage(this);
}

// FUNCTION: WEBSERVICE 0x10127180
AssemblyStage::AssemblyStage(IStage* upstream, World* world) : IWorldStage(upstream, new SleepStage(this, world), world)
{
}

} // namespace RBX
