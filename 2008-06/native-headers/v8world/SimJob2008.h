#pragma once
// >>> native-status (generated) -- do not edit >>>
// SimJob2008 | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src f5932ce8 | roc native-status --write
// 2008-06 native RBX::SimJob / AssemblySimJob (inactive). No donor class exists (the donor tree has neither); the name
// v8world/SimJob2008.h follows the other 2008 engine headers.
// Every field, slot and size below is read from the 2008-06 binary:
//   RTTI     SimJob 0083f72c -> boost::noncopyable_::noncopyable (mdisp 4: the empty base after the vptr);
//            AssemblySimJob 0083f73c -> SimJob -> noncopyable (mdisp 4).
//   slots    3: 0 scalar deleting dtor (SimJob ??_G 005e5190, inherited unchanged by AssemblySimJob: both vtables hold
//            005e5190), 1 / 2 pure in SimJob (_purecall 006a16be); AssemblySimJob 0074eed0 for both (`mov eax,
//            [ecx+0x24]; ret`). Slot 2's result is the assembly whose +0x40 the SimJobStage insert 0064d0f0 points back
//            at the job. Analog names: getAssemblyConst (slot 1) / getAssembly (slot 2).
//   sizes    SimJob 0x24 (AssemblySimJob() 005e51e0 writes +0x24 after the SimJob() call); AssemblySimJob 0x28
//            (SimJobStage 0064d200 news 0x28 and calls AssemblySimJob(assembly) 005e51e0).
//   ctor     SimJob() 005e50f0: vtable, the std::vector at +0x4 (VS2008 RTM _SECURE_SCL: aux owner object new(4) at
//            +0x4, first/last/end +0x10/+0x14/+0x18), +0x1c / +0x20 = 0.
//   dtor     ~SimJob 005e5150: vtable, the vector destructor (delete first, clear, delete the aux object).
//   fields   mechanisms +0x4: std::vector of 4-byte pointers; Mechanism (005e5350, in the Mechanism unit after
//            Mechanism::getMechanismFromPrimitive 005e50c0) pushes `this` into simJob+0x4 and stores the job at its
//            +0x0; 005e53a0 moves those elements between jobs. stageIterator +0x1c / +0x20: the std::list<SimJob*>
//            iterator (container, node) the SimJobStage insert 0064d0f0 stores after inserting the job into its list
//            (+0x10 of SimJobStage).
#include <vector>
#include <list>
#include <boost/noncopyable.hpp>

struct NativeKernelStagesLayout;

namespace RBX
{
	class Mechanism;
	class Assembly;

	class SimJob : public boost::noncopyable
	{
		friend struct ::NativeKernelStagesLayout; // tests/NativeKernelStagesLayout.cpp offset asserts

	private:
		std::vector<Mechanism*> mechanisms;                    // +0x4
	public:
		std::list<SimJob*>::iterator stageIterator;            // +0x1c

	public:
		SimJob();                                              // 005e50f0
		virtual ~SimJob();                                     // 005e5150 (slot 0 ??_G 005e5190)
		virtual Assembly* getAssemblyConst() = 0;              // slot 1 (analog name)
		virtual Assembly* getAssembly() = 0;                   // slot 2 (analog name)
	};

	class AssemblySimJob : public SimJob
	{
		friend struct ::NativeKernelStagesLayout;

	private:
		Assembly* assembly;                                    // +0x24

	public:
		AssemblySimJob(Assembly* assembly);                    // 005e51e0
		virtual Assembly* getAssemblyConst()                   // slot 1 (0074eed0)
		{
			return assembly;
		}
		virtual Assembly* getAssembly()                        // slot 2 (0074eed0)
		{
			return assembly;
		}
	};
}
