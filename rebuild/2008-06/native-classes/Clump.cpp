// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Clump unit (inactive), the 2008 Clump of native-headers/v8world/AssemblyLayout.h
// (NATIVE_CLUMP_DECL; ??_7Clump 0083f7ac, COL 008ad504; the evidence is in that header). Flags: the sibling v8world
// rows of native-classes/PrimitiveState.cpp. The Primitive is native-headers/v8world/Primitive2008.h (root primitive
// body +0xa0, myOwner +0xa4, +0xac), IMoving::notifyMoved 00614be0 the donor v8world/IMoving.h declaration.
// Rows built here: setSleepInfo 005e5fe0, getRootAssembly 005e6070, getSimJob 005e6110, computeCanSleep 005e6120,
// getBody 005e6160, notifyMoved 005e6170, setAssembly 005e6240, onPrimitivesChanged 005e62a0,
// onPrimitiveCanSleepChanged 005e6530, removePrimitive 005e6790, setParent 005e6fd0, ~Clump 005e70a0 (and ??_G
// 005e7280), the two IPipelined slot forwarders putInKernel 00646970 / removeFromKernel 005e60d0.
// Pending (NATIVE_PRIMITIVE_SETCLUMP_PENDING, see the guard below): Clump(Primitive*) 005e6cf0 and removePrimitiveImp
// 005e5ff0 call Primitive::setClump 005e7550, which native-headers/v8world/Primitive2008.h does not declare yet.
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8world/Primitive2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"
#include "v8world/IMoving.h"
#include "util/StlExtra.h"

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

#ifdef NATIVE_PRIMITIVE_SETCLUMP_PENDING
// Pending a Primitive2008.h declaration `void setClump(Clump* set); // 005e7550` (owner: Primitive2008.h; the body is
// AppUnit5E4PrimitiveParts.cpp). With that declaration (checked in a scratch compile) Clump(Primitive*) below is
// byte-identical to 005e6cf0; Body::setParent 006148b0 is native-headers/v8kernel/Body2008.h.
#include "v8kernel/Body2008.h"

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
}
#endif
