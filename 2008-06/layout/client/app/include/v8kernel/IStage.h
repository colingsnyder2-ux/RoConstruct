#pragma once
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
