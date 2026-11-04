// Source-derived world pipeline port from openrbx include/v8world/AssemblyStage2.h.
// June anchor swap is evidenced at 0064cc40/0064ccf0; full ABI/physics parity remains unproven.
#ifndef V8WORLD_ASSEMBLYSTAGE2_H
#define V8WORLD_ASSEMBLYSTAGE2_H

#include "v8world/IWorldStage.h"

#include <set>

namespace RBX {

class Assembly;
class Joint;
class SleepStage;

// VTABLE: WEBSERVICE 0x102485b4
// SIZE 0x28
class AssemblyStage : public IWorldStage
{
public:
	AssemblyStage(IStage* upstream, World* world);

	virtual ~AssemblyStage(); // vtable+0x00

	// SYNTHETIC: WEBSERVICE 0x10127260
	// RBX::AssemblyStage::`scalar deleting destructor'

	virtual StageType getStageType(); // vtable+0x04

	virtual void onEdgeAdded(Edge* edge);    // vtable+0x10
	virtual void onEdgeRemoving(Edge* edge); // vtable+0x14

	void onAssemblyAdded(Assembly* assembly);
	void onAssemblyRemoving(Assembly* assembly);

	void wakeAssembly(Assembly* assembly);

	void stepUi(int uiStepId);

private:
	void onJointAdded(Joint* joint);
	void onJointRemoving(Joint* joint);

	std::set<Assembly*> assemblies; // 0x10
	std::set<Joint*> joints;        // 0x1c
};


} // namespace RBX

#endif // V8WORLD_ASSEMBLYSTAGE2_H
