// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_unit_367216b06c91c7e0.cpp

// Candidate translation unit (score above; library headers required).
#include "v8world/JointStage.h"

#include "decomp.h"
#include "v8world/Joint.h"
#include "v8world/Primitive.h"

#include <cstddef>
#include <vector>

namespace RBX {
class Assembly;
class AssemblyStage;
class MotorJoint;

class ClumpStage : public IWorldStage
{
public:
	ClumpStage(IStage* upstream, World* world);
	virtual ~ClumpStage() {}
	void onPrimitiveCanSleepChanged(Primitive* p);
	void onPrimitiveAddedAnchor(Primitive* p);
	void onPrimitiveRemovedAnchor(Primitive* p);
	void onPrimitiveCanCollideChanged(Primitive* p);
	void onMotorAngleChanged(MotorJoint* motorJoint);
	virtual StageType getStageType();
	virtual void stepWorld(int worldStepId, int uiStepId, bool throttling) { getDownstream()->stepWorld(worldStepId, uiStepId, throttling); }
	void onPrimitiveAdded(Primitive* p);
	void onPrimitiveRemoving(Primitive* p);
	void process();
	void stepUi(int frameCount);
private:
	std::set<Joint*> pad;
};

ClumpStage* JointStage::getClumpStage()
{
	return static_cast<ClumpStage*>(getDownstream());
}

void JointStage::moveEdgeToDownstream(Edge* e)
{
	getDownstreamWS()->onEdgeAdded(e);
}

void JointStage::removeEdgeFromDownstream(Edge* e)
{
	getDownstreamWS()->onEdgeRemoving(e);
}

void JointStage::removeFromList(Joint* j)
{
	incompleteJoints.erase(j);
}

void JointStage::insertToList(Joint* j)
{
	incompleteJoints.insert(j);
}

void JointStage::insertToMap(Joint* j, Primitive* p)
{
	if (p != NULL) {
		jointMap.insert(std::make_pair(p, j));
	}
}

bool JointStage::edgeHasPrimitivesDownstream(Edge* e)
{
	Primitive* prim0 = e->getPrimitive(0);
	Primitive* prim1 = e->getPrimitive(1);

	return prim0 != NULL && prim1 != NULL && prim0->inPipeline() && prim1->inPipeline() &&
		   prim0->downstreamOfStage(this) && prim1->downstreamOfStage(this);
}

// FUNCTION: WEBSERVICE 0x10118350
void JointStage::removeFromMap(Joint* j, Primitive* p)
{
	do {
		if (p == NULL) {
			break;
		}

		JointMap::iterator pos;

		for (pos = jointMap.lower_bound(p); pos != jointMap.upper_bound(p); ++pos) {
			if (pos->second == j) {
				jointMap.erase(pos);
				return;
			}
		}
	} while (0);
}

// FUNCTION: WEBSERVICE 0x10118480
void JointStage::onJointPrimitiveNulling(Joint* j, Primitive* nulling)
{
	if (j->downstreamOfStage(this)) {
		removeEdgeFromDownstream(j);

		insertToList(j);

		insertToMap(j, j->otherPrimitive(nulling));
	}
	else {
		removeFromMap(j, nulling);
	}
}

// FUNCTION: WEBSERVICE 0x10118510
void JointStage::onJointPrimitiveSet(Joint* j, Primitive* p)
{
	if (edgeHasPrimitivesDownstream(j)) {
		removeFromList(j);

		removeFromMap(j, j->otherPrimitive(p));

		moveEdgeToDownstream(j);
	}
	else {
		insertToMap(j, p);
	}
}

// FUNCTION: WEBSERVICE 0x101185c0
void JointStage::onEdgeAdded(Edge* e)
{
	e->putInPipeline(this);

	if (edgeHasPrimitivesDownstream(e)) {
		moveEdgeToDownstream(e);
	}
	else {
		Joint* j = static_cast<Joint*>(e);

		insertToList(j);
		insertToMap(j, j->getPrimitive(0));
		insertToMap(j, j->getPrimitive(1));
	}
}

// FUNCTION: WEBSERVICE 0x10118680
void JointStage::onEdgeRemoving(Edge* e)
{
	if (e->downstreamOfStage(this)) {
		removeEdgeFromDownstream(e);
	}
	else {
		Joint* j = static_cast<Joint*>(e);

		removeFromList(j);
		removeFromMap(j, j->getPrimitive(0));
		removeFromMap(j, j->getPrimitive(1));
	}

	e->removeFromPipeline(this);
}

// FUNCTION: WEBSERVICE 0x10118700
JointStage::JointStage(IStage* upstream, World* world) : IWorldStage(upstream, new ClumpStage(this, world), world)
{
}

// STUB: WEBSERVICE 0x101188f0
void JointStage::onPrimitiveAdded(Primitive* p)
{
	p->putInPipeline(this);

	getClumpStage()->onPrimitiveAdded(p);

	std::vector<Joint*> jointsToPush;

	JointMap::iterator pos;

	for (pos = jointMap.lower_bound(p); pos != jointMap.upper_bound(p); ++pos) {
		if (edgeHasPrimitivesDownstream(pos->second)) {
			jointsToPush.push_back(pos->second);
		}
	}

	for (unsigned int i = 0; i < jointsToPush.size(); ++i) {
		Joint* j = jointsToPush[i];

		removeFromList(j);
		removeFromMap(j, p);
		removeFromMap(j, j->otherPrimitive(p));

		moveEdgeToDownstream(j);
	}
}

// FUNCTION: WEBSERVICE 0x10118b40
void JointStage::onPrimitiveRemoving(Primitive* p)
{
	std::vector<Joint*> jointsToPop;

	Joint* j = p->getFirstJoint();

	while (j != NULL) {
		if (j->getJointType() != Joint::ANCHOR_JOINT && j->getJointType() != Joint::FREE_JOINT) {

			jointsToPop.push_back(j);
		}

		j = p->getNextJoint(j);
	}

	for (unsigned int i = 0; i < jointsToPop.size(); ++i) {

		Joint* joint = jointsToPop[i];

		removeEdgeFromDownstream(joint);

		insertToList(joint);
		insertToMap(joint, p);
		insertToMap(joint, joint->otherPrimitive(p));
	}

	getClumpStage()->onPrimitiveRemoving(p);

	p->removeFromPipeline(this);
}

} // namespace RBX
