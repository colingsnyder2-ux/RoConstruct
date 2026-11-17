#pragma once
// 2008-06 native RBX::IStage with the 2008 StageType numbering (inactive, OPT-IN). This file sits at the original
// include path v8kernel/IStage.h, but only inside the kernel-stages overlay directory. A unit opts in by putting
// '/I{headers}/kernel-stages' on its '// native-flags:' line before any other /I entry. The runner adds those flags
// before /I{headers} and the donor include roots, so every '#include "v8kernel/IStage.h"' in that unit (native or
// donor: v8world/IPipelined.h, v8world/IWorldStage.h, v8kernel/Kernel.h) resolves here. Units that do not opt in keep
// the donor tools/rbxgs v8kernel/IStage.h unchanged. Never place a copy at native-headers/v8kernel/IStage.h, because
// that would shadow the donor for every unit.
//
// Layout and slots (the same in every 2008 stage vtable, native-headers/v8world/CleanStage2008.h:11-14):
//   fields   vptr +0x0, upstream +0x4, downstream +0x8 (CleanStage() 0064a310; IStage::stepWorld 0064a380 /
//            getKernel 0064a390 read downstream +0x8; IPipelined::removeFromStage 00645840 reads upstream +0x4).
//   slots    0 scalar deleting destructor, 1 getStageType, 2 stepWorld, 3 getKernel (the IWorldStage slots 4-6 follow).
//   novtable no IStage vtable exists (RTTI CleanStage 0084b05c -> IWorldStage -> IStage; only the most derived vtable
//            is stored), as in the donor.
//   ~IStage  00587050 (the donor body: delete downstream through its slot 0).
//   slot 2   Kernel::stepWorld 005fb3f0 (Kernel vtable 0084105c slot 2) is `ret 0x10` and reads a fourth argument
//            (`cmp byte ptr [esp + 0x38], 0` at 005fb408, before the SEH frame and the push ebp: that is argument 4).
//            So the 2008 slot 2 takes four arguments. The forwarding bodies (IStage::stepWorld 0064a380, TreeStage
//            00669780, AssemblyStage 0066f570) end in a tail jmp through downstream slot 2 and do not show the count.
//            moveBodiesTest is an analog name: a true value makes Kernel call 005fae00 (analog name
//            stepMoveBodiesTest) instead of the kernel step.
//   bodies   IStage::stepWorld 0064a380 and getKernel 0064a390 are 10-byte tail calls through downstream (+0x8) slot 2 /
//            slot 3, with no assertion code. The donor RBXASSERT(downstream) is left out (the 2008 bodies have none).
//
// 2008 StageType values. Each value is the constant returned by the stage's getStageType (slot 1):
//   CLEAN_STAGE    0  CleanStage    00416690 `xor eax, eax`   (no donor stage; the donor enum starts at JOINT_STAGE 0)
//   JOINT_STAGE    1  JointStage    007286a0 `mov eax, 1`
//   CLUMP_STAGE    2  ClumpStage    0077d810 `mov eax, 2`
//   TREE_STAGE     3  TreeStage     005e2790 `mov eax, 3`
//   ASSEMBLY_STAGE 4  AssemblyStage 006fa3f0 `mov eax, 4`
//   SLEEP_STAGE    5  SleepStage    007359e0 `mov eax, 5`
//   SIMJOB_STAGE   6  SimJobStage   005cb9d0 `mov eax, 6`
//   KERNEL_STAGE   7  Kernel        0077d800 `mov eax, 7` (also IPipelined::getKernel 00645850 `push 7`, and the
//                     inline getWorld / inKernel compares `cmp eax, 7` at 006456e0 / 005e5da0 / 005e3a80 / 006087a0)
// The donor COLLISION_STAGE and SEPARATE_STAGE have no 2008 stage class or getStageType body, so they are not declared.
// Several of these bodies are identical-code folds that share an address with other 0/1/2/5/6/7 returners (registry
// names such as NullController / SlingshotTool / PlayerController); the stage names above come from the vtables.
#include "util/Debug.h"

namespace RBX {
	class Kernel;

	class __declspec(novtable) IStage {
		private:
			IStage *upstream;                                          // +0x4
			IStage *downstream;                                        // +0x8
		public:
			enum StageType : unsigned int {
				CLEAN_STAGE = 0x0,                                     // 00416690
				JOINT_STAGE = 0x1,                                     // 007286a0
				CLUMP_STAGE = 0x2,                                     // 0077d810
				TREE_STAGE = 0x3,                                      // 005e2790
				ASSEMBLY_STAGE = 0x4,                                  // 006fa3f0
				SLEEP_STAGE = 0x5,                                     // 007359e0
				SIMJOB_STAGE = 0x6,                                    // 005cb9d0
				KERNEL_STAGE = 0x7,                                    // 0077d800
			};
			IStage(IStage* upstream, IStage* downstream):upstream(upstream),downstream(downstream) {}

			virtual ~IStage() {                                        // slot 0 (00587050)
				if (downstream)
					delete downstream;
			}

			virtual StageType getStageType() = 0;                      // slot 1
			IStage* findStage(StageType stageType)
			{
				IStage* idownstream = this;
				while (idownstream->getStageType() != stageType)
					idownstream = idownstream->downstream;
				return idownstream;
			}
			// slot 2 (0064a380: tail call of downstream slot 2; Kernel 005fb3f0 `ret 0x10`)
			virtual void stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
			{
				downstream->stepWorld(worldStepId, uiStepId, throttling, moveBodiesTest);
			}
			virtual Kernel* getKernel() {                              // slot 3 (0064a390: tail call of downstream slot 3)
				return downstream->getKernel();
			};
			RBX::IStage* getDownstream() {return downstream;};
			RBX::IStage* getUpstream() {return upstream;};
	};
}

// Lets headers that include v8kernel/IStage.h offer the inline stage-type compares (IPipelined2008.h getWorld /
// inKernel) only where this numbering is active.
#define NATIVE_KERNEL_STAGE_NUMBERING 1
