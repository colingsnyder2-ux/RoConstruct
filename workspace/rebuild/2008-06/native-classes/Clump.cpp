// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Clump unit (inactive), the 2008 Clump of native-headers/v8world/AssemblyLayout.h
// (NATIVE_CLUMP_DECL; ??_7Clump 0083f7ac, COL 008ad504; the evidence is in that header). Flags: the sibling v8world
// rows of native-classes/PrimitiveState.cpp. The Primitive is native-headers/v8world/Primitive2008.h (root primitive
// body +0xa0, myOwner +0xa4, +0xac), IMoving::notifyMoved 00614be0 the donor v8world/IMoving.h declaration.
// Rows built here: setSleepInfo 005e5fe0, getRootAssembly 005e6070, getSimJob 005e6110, computeCanSleep 005e6120,
// getBody 005e6160, notifyMoved 005e6170, setAssembly 005e6240, onPrimitivesChanged 005e62a0,
// onPrimitiveCanSleepChanged 005e6530, removePrimitive 005e6790, setParent 005e6fd0, ~Clump 005e70a0 (and ??_G
// 005e7280), the two IPipelined slot forwarders putInKernel 00646970 / removeFromKernel 005e60d0, Clump(Primitive*)
// 005e6cf0, lessAssembly 005e5f60, getJointToParent 005e6080, getAnchored 005e60e0, numMotors 005e62d0, getMotorImp
// 005e6360, Assembly::getMotor 005e6400, computeMaxRadius 005e6420, computeExternalEdges 005e6ba0, getExternalEdges
// 005e6c70 and addChild 005e6f70; removePrimitiveImp 005e5ff0 is a parked draft (see its comment).
// Clump(Primitive*) 005e6cf0 and removePrimitiveImp 005e5ff0 call Primitive::setClump 005e7550 (Primitive2008.h) and
// Body::setParent 006148b0 (native-headers/v8kernel/Body2008.h).
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8world/Primitive2008.h"
#include "v8kernel/Body2008.h"
#include "v8world/Joints2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"
#include "v8world/IMoving.h"
#include "util/StlExtra.h"
#include "util/Math.h"
#include <algorithm>

namespace RBX
{
	// 005e6110 (`mov eax, [ecx + 0x40]`; folded with World::getContactManager, whose registry name it carries): the
	// SimJob back-link that SimJobStage 0064d0f0 / 0064d180 set and clear; SimJobStage::removeAssembly 0064d2a0 calls
	// it on the assembly and deletes the result as a SimJob (analog name; openrbx Assembly::getMechanism).
	SimJob* Clump::getSimJob()
	{
		return simJob;
	}

	// 005e6120 (analog name: openrbx Assembly::computeCanSleep; the ctor 005e6cf0 binds it to the bool ComputeProp at
	// +0x68): false when any primitive of the assembly (PrimIterator IN_ASSEMBLY from the root, ++ 00647640) has its
	// +0xac flag clear (Primitive2008.h names +0xac canCollide).
	bool Clump::computeCanSleep() const
	{
		for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it)
		{
			if (!(*it)->getCanCollide())
			{
				return false;
			}
		}
		return true;
	}

	// 005e6160 (analog name; SimJobStage::addAssembly 0064d200 / removeAssembly 0064d2a0): the root primitive's body
	// (+0x1c, then Primitive +0xa0).
	Body* Clump::getBody()
	{
		return rootPrimitive->getBody();
	}

	// 005e6170 (analog name: openrbx Assembly::notifyMoved; callers Primitive::setCoordinateFrame 005e8200 and
	// SimJobStage::notifyMovingPrimitives 0064d3d0): IMoving::notifyMoved 00614be0 on every primitive's owner (+0xa4).
	void Clump::notifyMoved()
	{
		for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it)
		{
			(*it)->getOwner()->notifyMoved();
		}
	}

	// 00646970 (vtable slot 1; `jmp 00645830` IPipelined::putInKernel, folded with MultiJoint::putInKernel, whose
	// registry name it carries).
	void Clump::putInKernel(Kernel* kernel)
	{
		IPipelined::putInKernel(kernel);
	}

	// 005e60d0 (vtable slot 2; `jmp 00645860` IPipelined::removeFromKernel).
	void Clump::removeFromKernel()
	{
		IPipelined::removeFromKernel();
	}

	// 005e5fe0 (analog name: openrbx Assembly::setSleepInfo): +0x18.
	void Clump::setSleepInfo(SleepInfo* value)
	{
		sleepInfo = value;
	}

	// 005e6070 (analog name: openrbx Assembly::getRootAssembly; the recursion is a tail jump).
	Assembly* Clump::getRootAssembly()
	{
		return parent != NULL ? parent->getRootAssembly() : static_cast<Assembly*>(this);
	}

	// 005e62a0 (analog name: openrbx Assembly::onPrimitivesChanged): externalEdgesDirty +0x14, the two ComputeProp dirty
	// flags +0x54 / +0x69, then the same on every parent (the tail recursion is a loop).
	void Clump::onPrimitivesChanged()
	{
		externalEdgesDirty = true;
		maxRadius.setDirty();
		canSleep.setDirty();

		if (parent != NULL)
		{
			parent->onPrimitivesChanged();
		}
	}

	// 005e6240 (analog name): +0x24 here and, recursively, in every child (children +0x34 / +0x38).
	void Clump::setAssembly(Assembly* value)
	{
		assembly = value;

		for (unsigned int i = 0; i < children.size(); i++)
		{
			children[i]->setAssembly(value);
		}
	}

	// 005e6530 (analog name: openrbx Assembly::onPrimitiveCanSleepChanged): `mov byte [ecx+0x69], 1; ret 4`.
	void Clump::onPrimitiveCanSleepChanged(Primitive* p)
	{
		canSleep.setDirty();
	}

	// 005e6790 (INFERRED name): removePrimitiveImp 005e5ff0, then onPrimitivesChanged (inlined one level, 005e62a0 for
	// the parent).
	void Clump::removePrimitive(Primitive* p)
	{
		removePrimitiveImp(p);
		onPrimitivesChanged();
	}

	// 005e6fd0 (analog name: openrbx Assembly::setParent): fastRemoveShort<Assembly*> 005e5200 and the old parent's
	// onPrimitivesChanged 005e62a0, addChild 005e6f70 on the new parent, setAssembly 005e6240 with the root (005e6070),
	// then onPrimitivesChanged (inlined).
	void Clump::setParent(Clump* newParent)
	{
		if (newParent != parent)
		{
			if (parent != NULL)
			{
				fastRemoveShort(parent->children, static_cast<Assembly*>(this));
				parent->onPrimitivesChanged();
			}

			parent = newParent;

			if (parent != NULL)
			{
				parent->addChild(static_cast<Assembly*>(this));
			}

			setAssembly(getRootAssembly());
			onPrimitivesChanged();
		}
	}

	// 005e70a0 (vtable slot 0 through ??_G 005e7280): removePrimitive(rootPrimitive) (inlined: 005e5ff0), every child
	// detached through setParent(NULL) (inlined: fastRemoveShort 005e5200, setAssembly 005e6240), then this one; the
	// member dtors free children (+0x34, then the aux proxy +0x28) and externalEdges (alignedFree 00507d20).
	Clump::~Clump()
	{
		removePrimitive(rootPrimitive);

		while (children.size() != 0)
		{
			children.back()->setParent(NULL);
		}

		setParent(NULL);
	}
}

namespace RBX
{
	// 005e6cf0 (Clump(Primitive*); `new 0x78` at 00668d00): the members in declaration order (externalEdges empty,
	// externalEdgesDirty true, the -1 pair +0x44 / +0x48, the two ComputeProp bound to this), then assembly = this
	// (+0x24), Primitive::setClump 005e7550 and Body::setParent(NULL) 006148b0 on the root primitive, and
	// onPrimitivesChanged (inlined, 005e62a0 for a parent).
	Clump::Clump(Primitive* root)
		: externalEdgesDirty(true),
		  sleepInfo(NULL),
		  rootPrimitive(root),
		  parent(NULL),
		  simJob(NULL),
		  sleepStepId(-1),
		  sleepStepCount(-1),
		  maxRadius(this, &Clump::computeMaxRadius),
		  canSleep(this, &Clump::computeCanSleep)
	{
		assembly = static_cast<Assembly*>(this);
		Primitive* p = rootPrimitive; // the target keeps the reloaded +0x1c in edi across setClump
		p->setClump(this);
		p->getBody()->setParent(NULL);
		onPrimitivesChanged();
	}

	// 005e5ff0 (INFERRED name): every clump child of p first (PrimIterator::findFirstChild 00647540 IN_CLUMP, recursion
	// and onPrimitivesChanged 005e62a0), then Body::setParent(NULL) 006148b0 and Primitive::setClump(NULL) 005e7550.
	// Not byte-exact (parked): the target calls onPrimitivesChanged 005e62a0 in the loop, this compile inlines it
	// one level (same with removePrimitive(child) in the loop or with this body placed before onPrimitivesChanged).
	void Clump::removePrimitiveImp(Primitive* p)
	{
		Primitive* child;
		while ((child = PrimIterator::findFirstChild(p, PrimIterator::IN_CLUMP)) != NULL)
		{
			removePrimitiveImp(child);
			onPrimitivesChanged();
		}
		p->getBody()->setParent(NULL);
		p->setClump(NULL);
	}

	// 005e5f60 (analog name: openrbx lessAssembly): equal assemblies or equal root primitives are not less; else
	// Guid::compare 005a8330 of the root primitives' guids (Primitive::getGuid 005e7440, b's evaluated first) == -1.
	bool lessAssembly(const Assembly* a0, const Assembly* a1)
	{
		if (a0 == a1)
		{
			return false;
		}

		if (a0->getRootPrimitive() == a1->getRootPrimitive())
		{
			return false;
		}

		return Guid::compare(&a0->getRootPrimitive()->getGuid(), &a1->getRootPrimitive()->getGuid()) == -1;
	}

	// 005e6080 (analog name: openrbx Assembly::getJointToParent): the first active joint (+0x24) of p whose other
	// primitive (+0xc / +0x10) is NULL or owns p's parent body (Body +0x14 against Primitive +0xa0).
	Joint* Clump::getJointToParent(Primitive* p)
	{
		Joint* joint = p->getFirstJoint();

		while (joint != NULL)
		{
			if (joint->getActive())
			{
				Primitive* other = joint->getPrimitive(0);

				if (p == other)
				{
					other = joint->getPrimitive(1);
				}

				if (other == NULL || p->getBody()->getParent() == other->getBody())
				{
					return joint;
				}
			}

			joint = p->getNextJoint(joint);
		}

		return NULL;
	}

	// 005e60e0 (analog name: openrbx Assembly::getAnchored): the root primitive's anchored state (+0xa8 / +0xa9 / +0xaa).
	bool Clump::getAnchored() const
	{
		return rootPrimitive->getAnchor();
	}

	// 005e62d0 (analog name: openrbx Assembly::numMotors): 1 when the joint to the parent (005e6080) is a motor (Edge
	// slot 3 getEdgeType == JOINT, then slot 5 getJointType == MOTOR_JOINT 8), plus every child's count.
	unsigned int Clump::numMotors() const
	{
		unsigned int answer = 0;
		Joint* joint = getJointToParent(rootPrimitive);

		if (static_cast<Edge*>(joint)->getEdgeType() == Edge::JOINT && joint->getJointType() == Joint::MOTOR_JOINT)
		{
			answer = 1;
		}

		for (unsigned int i = 0; i < children.size(); i++)
		{
			answer += children[i]->numMotors();
		}

		return answer;
	}

	// 005e6360 (analog name: openrbx Assembly::getMotorImp): the motorId-th motor of this subtree (the joint to the
	// parent first, then the children in order).
	const MotorJoint* Clump::getMotorImp(unsigned int& motorId) const
	{
		Joint* joint = getJointToParent(rootPrimitive);

		if (static_cast<Edge*>(joint)->getEdgeType() == Edge::JOINT && joint->getJointType() == Joint::MOTOR_JOINT)
		{
			if (motorId == 0)
			{
				return static_cast<MotorJoint*>(joint);
			}

			motorId--;
		}

		for (unsigned int i = 0; i < children.size(); i++)
		{
			const MotorJoint* motor = children[i]->getMotorImp(motorId);

			if (motor != NULL)
			{
				return motor;
			}
		}

		return NULL;
	}

	// 005e6400 (registry ?getMotor@Assembly@RBX@@QAEPAVMotorJoint@2@I@Z): getMotorImp 005e6360 on a copy of index.
	MotorJoint* Assembly::getMotor(unsigned int index)
	{
		unsigned int i = index;

		return const_cast<MotorJoint*>(getMotorImp(i));
	}

	// 005e6420 (analog name: openrbx Assembly::computeMaxRadius; the ctor binds it to the float ComputeProp at +0x50):
	// the largest |offset from the root body's branch cofm (Body::getBranchCofmPos 00614480)| + half grid size over the
	// assembly's primitives (Body::updatePV 00599360, Math::vector3Abs 005de630, Geometry gridSize +0x4).
	float Clump::computeMaxRadius() const
	{
		float answer = 0;
		G3D::Vector3 offsetCenter = rootPrimitive->getBody()->getBranchCofmPos();

		for (PrimIterator it = PrimIterator::begin(rootPrimitive, PrimIterator::IN_ASSEMBLY); *it != NULL; ++it)
		{
			Primitive* primitive = *it;

			G3D::Vector3 offset = primitive->getBody()->getCoordinateFrame().translation - offsetCenter;
			G3D::Vector3 extent = Math::vector3Abs(offset);

			answer = std::max(answer, (extent + primitive->getGeometry()->getGridSize() * 0.5f).magnitude());
		}

		return answer;
	}

	// 005e6ba0 (INFERRED name): every external edge of the assembly (EdgeIterator::begin 00647730 from the root, ++
	// 00647700, against the static end()) appended to edges (G3D::Array<Edge*>::append, inline; resize 005e6540).
	void Clump::computeExternalEdges(G3D::Array<Edge*>& edges)
	{
		EdgeIterator it = EdgeIterator::begin(rootPrimitive);
		EdgeIterator stop = EdgeIterator::end(); // the target keeps end() in ebx / ebp across the loop

		for (; it != stop; ++it)
		{
			edges.append(*it);
		}
	}

	// 005e6c70 (INFERRED name): when externalEdgesDirty (+0x14), externalEdges (+0x8) resize(0, false) 005e6540 and
	// refilled by 005e6ba0; then the flag is cleared and the array returned.
	const G3D::Array<Edge*>& Clump::getExternalEdges()
	{
		if (externalEdgesDirty)
		{
			externalEdges.fastClear();
			computeExternalEdges(externalEdges);
		}

		externalEdgesDirty = false;
		return externalEdges;
	}

	// 005e6f70 (analog name: openrbx Assembly::addChild): children (+0x28) push_back 004213a0, then std::sort with
	// lessAssembly 005e5f60 (inlined into std::_Sort 005e6e90).
	void Clump::addChild(Assembly* child)
	{
		children.push_back(child);
		std::sort(children.begin(), children.end(), lessAssembly);
	}
}
