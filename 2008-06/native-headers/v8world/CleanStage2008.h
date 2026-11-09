#pragma once
// 2008-06 native RBX::CleanStage (inactive): the first world stage in 2008 (no donor class; the donor pipeline starts
// at JointStage). Declared under a non-colliding name next to JointStage2008.h / SimJobStage2008.h; it does not shadow
// any donor header. The bases IStage / IWorldStage come from the donor v8kernel/IStage.h / v8world/IWorldStage.h
// (reached through the donor v8world/IPipelined.h by every engine unit): their layout (vptr, upstream +0x4,
// downstream +0x8, world +0xc) and their seven slots match the 2008 vtables. Only the StageType values differ (see
// the PENDING note below and the recorder's PROPOSALS).
// Every CleanStage field, slot and size below is read from the 2008-06 binary:
//   RTTI     CleanStage 0084b05c -> IWorldStage -> IStage (all mdisp 0; no IWorldStage / IStage vtable exists:
//            __declspec(novtable) bases, as in the donor).
//   slots    7 (the same in every 2008 stage vtable): 0 scalar deleting dtor (0064a3a0), 1 getStageType (CleanStage
//            00416690 `xor eax, eax`), 2 IStage::stepWorld (0064a380: tail call of downstream slot 2), 3 IStage::getKernel
//            (0064a390: tail call of downstream slot 3), 4 onEdgeAdded (0064a4d0), 5 onEdgeRemoving (0064a510),
//            6 IWorldStage::getMetric (0064a3d0: tail call of downstream slot 6; no donor body).
//   size     0x10 (World() 005ea920 news 0x10 and calls CleanStage(NULL, world) 0064a310): IWorldStage only.
//   ctor     0064a310: downstream = new JointStage(this, world) (0x50, 00668470), upstream +0x4, world +0xc.
//   dtor     ??_G 0064a3a0: vtable store, the donor ~IStage body (delete downstream through its slot 0), operator delete.
//   2008 StageType (getStageType bodies): CleanStage 0 (00416690), JointStage 1 (007286a0), ClumpStage 2 (0077d810),
//            TreeStage 3 (005e2790), AssemblyStage 4 (006fa3f0), SleepStage 5 (007359e0), SimJobStage 6 (005cb9d0),
//            Kernel 7 (0077d800). The donor IStage.h has no CLEAN_STAGE and numbers JOINT_STAGE 0 ... KERNEL_STAGE 8, so
//            the getStageType bodies are defined only under NATIVE_KERNEL_STAGES_PENDING (built with a generated
//            v8kernel/IStage.h that carries the 2008 values).
#include "v8world/IWorldStage.h"

struct NativeKernelStagesLayout;

namespace RBX
{
	class Primitive;
	class Joint;
	class Edge;
	class World;
	class JointStage;

	class CleanStage : public IWorldStage
	{
		friend struct ::NativeKernelStagesLayout; // tests/NativeKernelStagesLayout.cpp size asserts

	private:
		JointStage* getJointStage()
		{
			return rbx_static_cast<JointStage*>(getDownstream());
		}

	public:
		CleanStage(IStage* upstream, World* world);                  // 0064a310
		virtual ~CleanStage()                                        // slot 0 (??_G 0064a3a0 keeps the vtable store)
		{
		}
		virtual StageType getStageType();                            // slot 1 (00416690; NATIVE_KERNEL_STAGES_PENDING)
		virtual void onEdgeAdded(Edge* e);                           // slot 4 (0064a4d0)
		virtual void onEdgeRemoving(Edge* e);                        // slot 5 (0064a510)
		void onPrimitiveAdded(Primitive* p);                         // 0064a3e0
		void onPrimitiveRemoving(Primitive* p);                      // 0064a400
		void onJointPrimitiveNulling(Joint* j, Primitive* nulling);  // 0064a420
		void onJointPrimitiveSet(Joint* j, Primitive* p);            // 0064a460
	};
}
