#pragma once
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
//   Mechanism (analog name; the vector element, not polymorphic): +0x0 the tracked SimJob. Its members are emitted in
//            the SimJob unit: stopTracking 005e5320 (`if (simJob) { fastRemoveShort(simJob->mechanisms, this) 005e5200;
//            simJob = 0; }`), setSimJob 005e5350 (inline stopTracking, then `if (job) { job->mechanisms.push_back(this)
//            004213a0; simJob = job; }`), and the cdecl transfer 005e53a0 (SimJob::transferMechanisms: while the source
//            vector is non-empty, back()->setSimJob(to), both inlined). These are the roles the donor
//            MechanismTracker::stopTracking / setMechanism / transferTrackers play for the donor Mechanism (2008: the
//            SimJob), so the 2008 element is this tracker. A unit must not include this header and the donor
//            v8world/Mechanism.h together (both declare RBX::Mechanism; the donor layout is the 2013 one).
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
		friend class Mechanism;                   // setSimJob / stopTracking edit mechanisms (005e5350, 005e5320)

	private:
		std::vector<Mechanism*> mechanisms;                    // +0x4
	public:
		std::list<SimJob*>::iterator stageIterator;            // +0x1c

	public:
		SimJob();                                              // 005e50f0
		virtual ~SimJob();                                     // 005e5150 (slot 0 ??_G 005e5190)
		virtual Assembly* getAssemblyConst() = 0;              // slot 1 (analog name)
		virtual Assembly* getAssembly() = 0;                   // slot 2 (analog name)

		// 005e53a0 (cdecl; analog name): hands every mechanism of `from` to `to` (NULL: just detaches them).
		static void transferMechanisms(SimJob* from, SimJob* to);
	};

	class Mechanism
	{
	private:
		SimJob* simJob;                                        // +0x0 (005e5320, 005e5350, 005e53a0)

	public:
		void stopTracking();                                   // 005e5320 (analog name)
		void setSimJob(SimJob* job);                           // 005e5350 (analog name)
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
