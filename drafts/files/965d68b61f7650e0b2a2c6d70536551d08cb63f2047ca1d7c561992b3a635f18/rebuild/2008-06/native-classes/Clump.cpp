// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Clump unit (inactive), the 2008 Clump of native-headers/v8world/AssemblyLayout.h
// (NATIVE_CLUMP_DECL; ??_7Clump 0083f7ac, COL 008ad504; the evidence is in that header). Flags: the sibling v8world
// rows of native-classes/PrimitiveState.cpp. The Primitive is native-headers/v8world/Primitive2008.h (root primitive
// body +0xa0, myOwner +0xa4, +0xac), IMoving::notifyMoved 00614be0 the donor v8world/IMoving.h declaration.
// Rows built here: getSimJob 005e6110, computeCanSleep 005e6120, getBody 005e6160, notifyMoved 005e6170, the two
// IPipelined slot forwarders putInKernel 00646970 / removeFromKernel 005e60d0.
// Not built (parked, see the batch result): Clump(Primitive*) 005e6cf0, ~Clump 005e70a0 and ??_G 005e7280. They need
// the fields the header keeps as INFERRED padding: a G3D::Array at +0x8 (dtor 005e70a0 G3D::System::alignedFree of
// +0x8, then +0x8 / +0xc / +0x10 zeroed) with the byte +0x14, a std::vector<Clump*> of children at +0x28 (+0x34 /
// +0x38 / +0x3c), the -1 pair +0x44 / +0x48 and two ComputeProp (float: +0x54 dirty, +0x58 object, +0x60 getter
// 005e6420; bool: +0x69 dirty, +0x6c object, +0x70 getter 005e6120), plus the Clump-unit callees 005e62a0 /
// 005e6240 / 005e5ff0 (placeholders) and Primitive::setClump 005e7550 (placeholder).
#include <G3D/Array.h>
#include <G3D/CoordinateFrame.h>
#include "v8world/Primitive2008.h"
#define NATIVE_CLUMP_DECL // the native 2008 RBX::Clump / RBX::Assembly of v8world/AssemblyLayout.h
#include "v8world/AssemblyLayout.h"
#include "v8world/IMoving.h"

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
}
