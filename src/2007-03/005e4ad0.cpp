// from server: 62% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8world/AssemblyStage2.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/AssemblyStage2.h"

#include "decomp.h"
#include "v8world/Assembly2.h"
#include "v8world/Contact.h"
#include "v8world/Joint.h"
#include "v8world/Primitive.h"
#include "v8world/SleepStage2.h"

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
