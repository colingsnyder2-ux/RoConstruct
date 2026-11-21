#pragma once
// 2008-06 native RBX::MechanismTracker (inactive). The class name comes from the registry row
// 005e50e0 ?tracking@MechanismTracker@RBX@@QAE_NXZ (`cmp dword ptr [ecx], 0; setne al; ret`); the shape follows the
// donor tools/rbxgs Client/App/include/v8world/Mechanism.h MechanismTracker (one pointer, inline constructor that
// zeroes it, inline destructor calling stopTracking). In 2008 the tracked object is the SimJob (v8world/SimJob2008.h):
//   stopTracking 005e5320 removes the tracker from the job's +0x4 vector (005e5200) and clears the pointer;
//   setSimJob 005e5350 (analog name; the donor setMechanism) re-targets it; the getter (donor getMechanism) is the
//   ICF-folded `mov eax, [ecx]; ret` 0071f210.
// Users: RoundRobinPhysicsSender +0x8 (constructor 004c99c0 stores 0 inline; destructor 004ca010 calls 005e5320;
// 004c99b0 `jmp 005e5320` is the inline destructor's out-of-line copy) and SimJobStage::reportMechanisms 004cbad0.
// v8world/SimJob2008.h declares the same 005e5320 / 005e5350 rows under the analog class name RBX::Mechanism; this
// header does not include it and declares no RBX::Mechanism, so both can be included together.
// The donor header at the path v8world/Mechanism.h is shadowed by the global-namespace stub
// native-headers/v8world/Mechanism.h; this header has its own name and shadows nothing.
#include <stddef.h>

namespace RBX
{
	class SimJob;

	class MechanismTracker
	{
	private:
		SimJob* simJob;                                  // +0x0

		// 005e5320 (donor: private; tests/record_native_network_physics.py binds ?stopTracking@MechanismTracker@RBX@@AAEXXZ)
		void stopTracking();

	public:
		MechanismTracker()
			: simJob(NULL)
		{
		}
		~MechanismTracker()                              // out-of-line copy 004c99b0 (`jmp 005e5320`)
		{
			stopTracking();
		}

		bool tracking();                                 // 005e50e0 ?tracking@MechanismTracker@RBX@@QAE_NXZ (registry)
		SimJob* getSimJob();                             // 0071f210 (ICF-folded getter; donor getMechanism; analog name)
		void setSimJob(SimJob* job);                     // 005e5350 (donor setMechanism; analog name)
	};
}
