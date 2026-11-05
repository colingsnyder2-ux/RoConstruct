// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_8c97cddee26372e7.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include "v8world/AssemblyStage.h"
#include "v8world/Assembly.h"
#include "v8world/Contact.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
namespace RBX {
void AssemblyStage::onJointRemoving(Joint* joint)
{
	joints.erase(joint);

	joint->canStepUi();
}
void AssemblyStage::onEdgeRemoving(Edge* e)
{
 Assembly* a0 = e->getPrimitive(0)->getAssembly();
 Assembly* a1 = e->getPrimitive(1)->getAssembly();
 *reinterpret_cast<bool*>(reinterpret_cast<char*>(a0) + 0x14) = true;
 *reinterpret_cast<bool*>(reinterpret_cast<char*>(a1) + 0x14) = true;

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
}
