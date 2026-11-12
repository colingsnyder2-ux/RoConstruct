// Source-derived world pipeline port from openrbx include/v8world/Assembly2.h.
// June anchor swap is evidenced at 0064cc40/0064ccf0; full ABI/physics parity remains unproven.
#ifndef V8WORLD_ASSEMBLY2_H
#define V8WORLD_ASSEMBLY2_H

#include "util/ComputeProp.h"
#include "util/RunningAverage.h"
#include "v8world/IPipelined.h"
#include "v8world/Clump.h"
#include "v8world/Mechanism.h"
// The port references RBX::SimJob without declaring it. The 2008-06 recovered header is
// v8world/SimJob2008.h (RTTI SimJob 0083f72c, ctor 005e50f0; the 2008-06 engine headers use the
// "2008" filename suffix). The native-world include dir has no SimJob.h of its own.
#include "v8world/SimJob2008.h"

#include <G3D/Vector3.h>
#include <boost/noncopyable.hpp>
#include <vector>

namespace RBX {

using G3D::Vector3;
using G3D::CoordinateFrame;

class Body;
class EdgeIterator;
class PrimIterator;
class Edge;
class Joint;
class Mechanism;
class MotorJoint;
class RigidJoint;
class Primitive;

namespace Sim {

enum AssemblyState
{
	ANCHORED = 0,
	RECURSIVE_WAKE_PENDING = 1,
	WAKE_PENDING = 2,
	AWAKE = 3,
	SLEEPING_CHECKING = 4,
	SLEEPING_DEEPLY = 5,
};

} // namespace Sim

// SIZE 0x24
class SleepInfo
{
public:
	SleepInfo();
	~SleepInfo();

private:
	friend class Assembly;
	friend class SleepStage;

	static float sleepTolerance() { return 0.02f; }

	Sim::AssemblyState state;                // 0x00
	int sleepCount;                          // 0x04
	RunningAverageState runningAverageState; // 0x08
};


// VTABLE: WEBSERVICE 0x10246c4c
// SIZE 0x50
class Assembly : public IPipelined, public boost::noncopyable
{
private:
	float computeMaxRadius() const;
	bool computeCanSleep() const;
	void onPrimitivesChanged();
	static Joint* getJointToParent(Primitive* primitive);

public:
	Assembly(Primitive* root);
	Primitive* getMainPrimitive() const { return const_cast<Primitive*>(getAssemblyPrimitiveConst()); }
	bool moving() { return getSleepStatus()==Sim::AWAKE; }
	int getDof() const { return getAnchored()?0:6; }
	~Assembly();

	// SYNTHETIC: WEBSERVICE 0x1011b5c0
	// RBX::Assembly::`scalar deleting destructor'

	PrimIterator assemblyPrimBegin() const;
	PrimIterator assemblyPrimEnd() const;

	EdgeIterator externalEdgeBegin() const;
	EdgeIterator externalEdgeEnd() const;

	Assembly* getRootAssembly();
	const Assembly* getRootAssemblyConst() const;
	Primitive* getAssemblyPrimitive();
	const Primitive* getAssemblyPrimitiveConst() const;

	SleepInfo* getSleepInfo() { return sleepInfo; }
	void setSleepInfo(SleepInfo* value) { sleepInfo = value; }

	float getMaxRadius() { return maxRadius; }
	bool getCanSleep() { return canSleep; }

	Assembly* otherAssembly(Edge* edge) const;

	const Primitive* getRootPrimitive() const { return rootPrimitive; }

	Mechanism* getMechanism();
	void setMechanism(Mechanism* value) { job = value; }
	void setJob(SimJob* value) { job = value; }
	SimJob* getJob() const { return job; }

	void onPrimitiveCanSleepChanged(Primitive* primitive);

	unsigned int numMotors() const;
	MotorJoint* getMotor(unsigned int index);

	void stepUi(int frameCount);

	void setParent(Assembly* value);

	static void addRigidChild(Primitive* parent, RigidJoint* joint, Primitive* child);
	static void addMotorChild(Primitive* parent, MotorJoint* joint, Primitive* child);
	static void addGroundChild(Primitive* child);
	Sim::AssemblyState getSleepStatus() const;
	bool getAnchored() const;

	void notifyMoved();

	virtual void putInKernel(Kernel* kernel); // vtable+0x04
	virtual void removeFromKernel();          // vtable+0x08

private:
	const MotorJoint* getMotorImp(unsigned int& index) const;

	void addChild(Assembly* child);

	SleepInfo* sleepInfo;                   // 0x08
	Primitive* rootPrimitive;               // 0x0c
	Assembly* parent;                       // 0x10
	std::vector<Assembly*> children;        // 0x14
	SimJob* job;                   // 0x24
	ComputeProp<float, Assembly> maxRadius; // 0x28
	ComputeProp<bool, Assembly> canSleep;   // 0x40
};


// VTABLE: WEBSERVICE 0x10247e3c
// SIZE 0x50
class Clump : public Assembly
{
public:
	// FUNCTION: WEBSERVICE 0x1011b310
	Clump(Primitive* root) : Assembly(root) {}
};


bool lessAssembly(const Assembly* a, const Assembly* b);

} // namespace RBX

#endif // V8WORLD_ASSEMBLY2_H
