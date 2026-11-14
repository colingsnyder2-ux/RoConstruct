#pragma once
// 2008-06 native Assembly / Clump field layout (inactive): a unit-local layout VIEW, not the original declaration.
// Why a view: the units that need these fields reach the donor v8world/Assembly.h and v8world/Clump.h (through the
// part-embedded v8world/Primitive.h), whose classes put the fields elsewhere (donor Assembly::rootClump +0x8, donor
// Clump::rootPrimitive after RunningAverageState), and no native 2008 RBX::Assembly / RBX::Clump declaration exists
// (native-world Assembly.h / Clump.h are the WEBSERVICE layout). The classes cannot be redeclared next to the donor
// headers, so this header declares only the offsets the 2008 binary reads, in RBX::AssemblyLayout (no collision with
// RBX::Assembly / RBX::Clump: it may be included next to the donor headers). Padding members are INFERRED: only the
// named offsets are read from the binary. Replace this with a native 2008 Assembly / Clump declaration when one exists.
// Evidence (2008-06 binary):
//   Clump     +0x24 assembly: Primitive::getAssembly 005e7570 (`clump = [prim+0x5c]; clump ? [clump+0x24] : 0`) and
//             005e7560 (`[[prim+0x5c]+0x24]`); vtable ??_7Clump 0083f7ac (the Clump is polymorphic in 2008).
//             +0x1c root primitive: Seat::seatCharacter 0063c9f1 and Primitive::setCoordinateFrame 005e826b compare
//             [[assembly+0x24]+0x1c] with the primitive (assembly->getRootClump()->getRootPrimitive()).
//   Assembly  +0x1c primitive: 005e6160 (`[[ecx+0x1c]+0xa0]`: its body), 005e6170 (notifyMoved: PrimIterator from
//             [ecx+0x1c], myOwner +0xa4 00614be0 per primitive), 005e6120 (canCollide +0xac walk).
//             +0x24 root clump: Seat::seatCharacter 0063c9ee, Primitive::setCoordinateFrame 005e8268.
//             +0x40 SimJob back-link: SimJobStage insert 0064d0f0 (`[job->slot2()+0x40] = job`), erase 0064d180
//             (`[job->slot2()+0x40] = 0`), getter 005e6110 (`mov eax, [ecx+0x40]`, folded with
//             World::getContactManager) called on the assembly by 0064d2a0 before the erase 0064d180.

namespace RBX
{
	class Assembly;
	class Primitive;
	class SimJob;

	namespace AssemblyLayout
	{
		struct ClumpFields
		{
			char unknown0[0x1c];          // INFERRED: vptr (??_7Clump 0083f7ac) and fields the views never read
			Primitive* rootPrimitive;      // +0x1c (0063c9f1, 005e826b)
			char unknown20[0x4];           // INFERRED: unread here
			Assembly* assembly;            // +0x24 (005e7570, 005e7560)
		};

		struct AssemblyFields
		{
			char unknown0[0x1c];          // INFERRED: fields the views never read
			Primitive* primitive;          // +0x1c (005e6160, 005e6170)
			char unknown20[0x4];           // INFERRED: unread here
			ClumpFields* rootClump;        // +0x24 (0063c9ee, 005e8268)
			char unknown28[0x18];          // INFERRED: unread here
			SimJob* simJob;                // +0x40 (0064d0f0, 0064d180, 005e6110)
		};

		inline AssemblyFields* fields(Assembly* assembly)
		{
			return reinterpret_cast<AssemblyFields*>(assembly);
		}

		// assembly->getRootClump()->getRootPrimitive() with the 2008 offsets (+0x24, then +0x1c).
		inline Primitive* getRootPrimitive(Assembly* assembly)
		{
			return fields(assembly)->rootClump->rootPrimitive;
		}
	}
}
