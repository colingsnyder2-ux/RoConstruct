#pragma once
// >>> native-status (generated) -- do not edit >>>
// IPipelined2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 37ec8f6e | roc native-status --write
// 2008-06 native RBX::IPipelined (inactive). Declared under a non-colliding name: the original path
// v8world/IPipelined.h is the donor header, which includes the donor v8kernel/Kernel.h -> KernelData.h -> Body.h /
// Point.h / Connector.h and so cannot be included next to native-headers/v8kernel/Body2008.h (C2011). This header
// includes only the donor v8kernel/IStage.h (as native-headers/v8kernel/Kernel2008.h does) and declares the Kernel by
// name. A unit must not include both this header and the donor v8world/IPipelined.h (or v8world/Edge.h /
// Primitive.h / World.h, which include it), except through the switch below.
//
// Every virtual, field and body below is read from the 2008-06 binary:
//   RTTI     IPipelined has no vtable of its own: Primitive 0083f83c -> IPipelined (mdisp 0), BallBallContact 008436bc
//            -> Contact -> Edge -> IPipelined (mdisp 0); Primitive() 005e8770 and Contact() 00606c20 store only the
//            most-derived vtable, so it is __declspec(novtable).
//   slots    3: 0 scalar deleting destructor (Primitive 005e83a0), 1 putInKernel 00645830, 2 removeFromKernel 00645860
//            (Primitive vtable 0083f83c: 005e83a0, 00645830, 00645860, then Primitive::getRadius 005e7f10).
//   fields   currentStage +0x4: Primitive() 005e8770 zeroes +0x4 before the vtable store (005e8795); putInKernel 00645830
//            stores the Kernel* (Kernel RTTI 0084105c -> IStage at mdisp 0, so no adjustment); removeFromKernel
//            00645860 and removeFromStage 00645840 set it to currentStage->upstream (IStage +0x4);
//            removeFromPipeline 00645820 stores NULL. Edge (Contact2008.h) starts its fields at +0x8, Primitive at +0x8.
//   members  out of line: getStage(StageType) 006457e0 (walks upstream / downstream by getStageType, slot 1 of IStage),
//            getKernel 00645850 (`push 7; call getStage`), removeFromPipeline 00645820, removeFromStage 00645840.
//
// Switch: a unit that also includes the donor v8world/Edge.h (for example through native-headers/v8world/
// Contact2008.h) defines NATIVE_IPIPELINED2008_DONOR, and this header then includes the donor v8world/IPipelined.h,
// whose IPipelined has the same 2008 layout (novtable, the same three slots, currentStage +0x4; the
// body-primitive2008 layout probe checks both configurations).
#ifdef NATIVE_IPIPELINED2008_DONOR
#include "v8world/IPipelined.h"
#else
#include <stddef.h>
#include "v8kernel/IStage.h"

struct NativeBodyPrimitive2008Layout;

namespace RBX
{
	class Kernel;

	class __declspec(novtable) IPipelined
	{
		friend struct ::NativeBodyPrimitive2008Layout; // tests/NativeBodyPrimitive2008Layout.cpp offset asserts

	private:
		IStage* currentStage;                          // +0x4

		IStage* getStage(IStage::StageType stageType) const;   // 006457e0

	public:
		IPipelined() : currentStage(NULL) {}
		virtual ~IPipelined() {}                       // slot 0

		void removeFromPipeline(IStage* stage);        // 00645820
		void removeFromStage(IStage* stage);           // 00645840
		bool inPipeline() const
		{
			return currentStage != NULL;
		}
		Kernel* getKernel() const;                     // 00645850
		virtual void putInKernel(Kernel* kernel);      // slot 1 (00645830)
		virtual void removeFromKernel();               // slot 2 (00645860)
	};
}
#endif
