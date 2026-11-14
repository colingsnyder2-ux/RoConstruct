#pragma once
// 2008-06 native Assembly / Clump (inactive). Two parts:
//   1. RBX::AssemblyLayout (always): a field-offset VIEW for units that also reach the donor v8world/Assembly.h /
//      Clump.h (through the donor or part-embedded v8world/Primitive.h, e.g. Seat.cpp), whose classes put the fields
//      elsewhere (donor Assembly::rootClump +0x8, donor Clump::assembly +0x20). It never collides with RBX::Assembly /
//      RBX::Clump. Padding members are INFERRED: only the named offsets are read from the binary.
//   2. The native 2008 RBX::Clump declaration (only when the unit defines NATIVE_CLUMP_DECL before including this
//      header, and so must not reach the donor v8world/Clump.h / Assembly.h). It needs a 2008 IPipelined: it includes
//      native-headers/v8kernel/IPipelined2008.h, so a unit that also reaches the donor v8world/IPipelined.h (through the
//      donor v8world/Edge.h) defines NATIVE_IPIPELINED2008_DONOR too (same layout, see IPipelined2008.h).
// Evidence (2008-06 binary):
//   RTTI     ??_7Clump 0083f7ac, COL 008ad504: Clump -> IPipelined (mdisp 0), boost::noncopyable (mdisp 8). Three
//            slots: 0 scalar deleting dtor 005e7280 (dtor body 005e70a0), 1 putInKernel 00646970 (`jmp 00645830`,
//            IPipelined::putInKernel), 2 removeFromKernel 005e60d0 (`jmp 00645860`, IPipelined::removeFromKernel).
//            The binary has NO RTTI type descriptor for an RBX::Assembly (only Clump and IPipelined among these; the
//            other IPipelined classes are Primitive and the Edge family), so in 2008 the pipelined "assembly" object
//            is a Clump: Clump(Primitive*) 005e6cf0 stores `this` at +0x24 (a root clump is its own assembly), and
//            SleepStage 0064ae90 hands the same object to SimJobStage 0064d200 / 0064d2a0, which call its slots 1 / 2,
//            IPipelined::putInStage / removeFromStage (00645830 / 00645840) and the Clump-unit members 005e6160 /
//            005e6110 on it.
//   size     0x78 (00668d06: `push 0x78; call new` then Clump(Primitive*) 005e6cf0).
//   Clump    +0x1c root primitive: ctor 005e6cf0 (the argument), Seat::seatCharacter 0063c9f1 and
//            Primitive::setCoordinateFrame 005e826b compare [[assembly+0x24]+0x1c] with the primitive.
//            +0x20 parent clump (ctor zero; dtor 005e70a0 removes this from [+0x20]+0x28 through fastRemoveShort
//            005e5200 and walks [+0x20]).
//            +0x24 assembly: ctor 005e6cf0 (`mov [esi+0x24], esi`); Primitive::getAssembly 005e7570 (`clump =
//            [prim+0x5c]; clump ? [clump+0x24] : 0`), 005e7560 (`[[prim+0x5c]+0x24]`).
//            +0x40 SimJob back-link: ctor zero; SimJobStage insert 0064d0f0 (`[job->slot2()+0x40] = job`), erase
//            0064d180 (`[job->slot2()+0x40] = 0`), getter 005e6110 (`mov eax, [ecx+0x40]`, folded with
//            World::getContactManager) called on the assembly by 0064d2a0 before the erase 0064d180.
//   members  005e6160 (`[[ecx+0x1c]+0xa0]`: the root primitive's body), 005e6170 (notifyMoved: primitive iterator
//            from [ecx+0x1c], myOwner +0xa4 IMoving::notifyMoved 00614be0 per primitive, ++ 00647640), 005e6120
//            (all primitives' +0xac flag, the ctor's computed-property callback at +0x70).

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

#ifdef NATIVE_CLUMP_DECL
#include <boost/noncopyable.hpp>
#include "v8kernel/IPipelined2008.h"

namespace RBX
{
	class Body;
	class Kernel;

	class Clump : public IPipelined, public boost::noncopyable
	{
	private:
		char unknown8[0x14];                             // INFERRED: +0x8..+0x1b, ctor 005e6cf0 zeroes +0x8 / +0xc /
		                                                 // +0x10 / +0x18 and sets the byte +0x14 (not read here)
		Primitive* rootPrimitive;                        // +0x1c (005e6cf0, 005e6160, 005e6170)
		Clump* parent;                                   // +0x20 (analog name; 005e6cf0, 005e70a0)
		Assembly* assembly;                              // +0x24 (005e6cf0 stores this; 005e7570)
		char unknown28[0x18];                            // INFERRED: +0x28..+0x3f, a std::vector (005e6cf0 proxy at
		                                                 // +0x28, +0x34 / +0x38 / +0x3c; 005e70a0) not read here
		SimJob* simJob;                                  // +0x40 (005e6cf0, 0064d0f0, 0064d180, 005e6110)
		char unknown44[0x34];                            // INFERRED: +0x44..+0x77 (size 0x78): -1 pair +0x44 / +0x48,
		                                                 // computed properties +0x54..+0x74 (005e6cf0), not read here

	public:
		virtual ~Clump();                                // slot 0 (??_G 005e7280, body 005e70a0)
		virtual void putInKernel(Kernel* kernel);        // slot 1 (00646970, `jmp 00645830`)
		virtual void removeFromKernel();                 // slot 2 (005e60d0, `jmp 00645860`)

		Primitive* getRootPrimitive() const
		{
			return rootPrimitive;
		}
		Assembly* getAssembly() const
		{
			return assembly;
		}
		void setSimJob(SimJob* job)                      // analog name: inline stores of 0064d0f0 / 0064d180
		{
			simJob = job;
		}
		SimJob* getSimJob();                             // 005e6110 (analog name; folded with World::getContactManager)
		Body* getBody();                                 // 005e6160 (analog name)
		void notifyMoved();                              // 005e6170 (analog name)
	};

	// INFERRED: the 2008 binary has no RTTI for an RBX::Assembly and the assembly object is its root Clump (Clump()
	// 005e6cf0 stores this at +0x24), while the registry names that carry the type (Primitive::getAssembly 005e7570,
	// AssemblySimJob(Assembly*) 005e51e0) spell RBX::Assembly. Declared as a Clump that adds no members and no
	// virtuals, never constructed (so no vtable or RTTI of its own, as in the binary): every member called on it is a
	// Clump member, as 005e6110 / 005e6160 / 005e6170 are Clump-unit code.
	class Assembly : public Clump
	{
	public:
		Clump* getRootClump() const                      // the +0x24 view of 0063c9ee / 005e8268
		{
			return Clump::getAssembly();
		}
	};
}
#endif
