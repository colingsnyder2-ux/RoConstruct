// Source-derived world pipeline port from openrbx include/v8world/ClumpStage2.h.
// June anchor swap is evidenced at 0064cc40/0064ccf0; full ABI/physics parity remains unproven.
// >>> native-status (generated) -- do not edit >>>
// ClumpStage | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b7bd6587 | roc native-status --write
#ifndef V8WORLD_CLUMPSTAGE2_H
#define V8WORLD_CLUMPSTAGE2_H

#include "v8world/IWorldStage.h"
#include "v8world/Joint.h"

#include <set>

namespace RBX {

class Assembly;
class AssemblyStage;
class MotorJoint;
class Primitive;

float getPrimitiveSize(const Primitive* primitive);

int biggerJointGuid(const Joint* joint0, const Joint* joint1);
int biggerJointSize(const Joint* joint0, const Joint* joint1);

Joint* getJoint(Primitive* primitive, Joint::JointType jointType);

class JointSort
{
public:
	static bool lighterJoint(const Joint* joint0, const Joint* joint1);
};

// VTABLE: WEBSERVICE 0x10247edc
// SIZE 0x30
class TreeStage : public IWorldStage
{
private:
	void insertEdge(Edge* e);
	void insertJoint(Joint* j);

	void swap(Joint* deactivate, Joint* activate, Primitive* newParent);
	void findHeaviestUpstream(Primitive* p0, Primitive* p1, Joint*& answer, int& heavySide);
	Primitive* heavyParent(int index, Primitive* primitive, Joint*& heaviest, int& heaviestIndex);

	void buildDownstreamTree(Primitive* p, std::set<Primitive*>& tree);
	Joint* findLightestDownstream(Primitive* p, Primitive*& newParent);

	void traverse(Joint* joint, Primitive* parent);
	void rebuildClump(Joint* joint, Primitive* parent);

	int getClumpDepth(Primitive* p);

	void cleanEdge(Edge* e);

	void dirtyAssemblies(Joint* j);
	void destroyAssembly(Assembly* a);
	void dirtyAssembly(Assembly* a);
	void undirtyAssembly(Assembly* a);
	void cleanAssembly(Assembly* assembly);

public:
	virtual ~TreeStage(); // vtable+0x00

	// SYNTHETIC: WEBSERVICE 0x1011c1e0
	// RBX::TreeStage::`scalar deleting destructor'

	// FUNCTION: WEBSERVICE 0x100a7740 FOLDED
	virtual StageType getStageType() { return TREE_STAGE; } // vtable+0x04

	virtual void onEdgeAdded(Edge* edge);         // vtable+0x10
	virtual void onEdgeRemoving(Edge* edge);      // vtable+0x14
	virtual int getMetric(MetricType metricType); // vtable+0x18

	virtual void stepWorld(int worldStepId, int uiStepId, bool throttling); // vtable+0x08

	void process();

private:
	void eraseEdge(Edge* e);

public:
	TreeStage(IStage* upstream, World* world);

private:
	int maxTreeDepth;               // 0x10
	bool dirty;                     // 0x14
	std::set<Assembly*> assemblies; // 0x18
	std::set<Edge*> edges;          // 0x24
};


// VTABLE: WEBSERVICE 0x10247e4c
// SIZE 0x10
class ClumpStage : public IWorldStage
{
public:
	ClumpStage(IStage* upstream, World* world);

	virtual ~ClumpStage() {} // vtable+0x00

	void onPrimitiveCanSleepChanged(Primitive* p);

	void onPrimitiveAddedAnchor(Primitive* p);
	void onPrimitiveRemovingAnchor(Primitive* p);

	void onPrimitiveCanCollideChanged(Primitive* p);
	void onMotorAngleChanged(MotorJoint* motorJoint);

	// SYNTHETIC: WEBSERVICE 0x1011b710
	// RBX::ClumpStage::`scalar deleting destructor'

	virtual StageType getStageType(); // vtable+0x04

	// FUNCTION: WEBSERVICE 0x101187e0 FOLDED
	virtual void stepWorld(int worldStepId, int uiStepId, bool throttling) // vtable+0x08
	{
		getDownstream()->stepWorld(worldStepId, uiStepId, throttling);
	}

	void onPrimitiveAdded(Primitive* p);
	void onPrimitiveRemoving(Primitive* p);

	void process();

	void stepUi(int frameCount);

private:
};


} // namespace RBX

#endif // V8WORLD_CLUMPSTAGE2_H
