#pragma once
// 2008-06 native RBX::Kernel (inactive). Declared under a non-colliding name: the original path v8kernel/Kernel.h is
// included by the donor v8world/IPipelined.h, i.e. by every engine unit (Edge, Joint, Contact, Primitive, World ...),
// so a header at that path would shadow the donor for nearly all recorders. A unit must not include both this header
// and v8kernel/Kernel.h (or v8world/IPipelined.h / Edge.h / Primitive.h / World.h, which include it).
// The base IStage comes from the donor v8kernel/IStage.h (vptr, upstream +0x4, downstream +0x8).
// Every Kernel field, slot and size below is read from the 2008-06 binary:
//   RTTI     Kernel 0084105c -> IStage (mdisp 0).
//   slots    4: 0 scalar deleting dtor (005fb0c0, calls ~Kernel 005faca0), 1 getStageType (0077d800 `mov eax, 7`),
//            2 stepWorld(int, int, bool) (005fb3f0, evidence name), 3 getKernel (007188c0 `mov eax, ecx`).
//   size     0x24 (SimJobStage() 0064d300 news 0x24 and calls Kernel(this) 005fb650).
//   ctor     005fb650: IStage(upstream, NULL), inStepCode +0xc = false, kernelData +0x10 = new KernelData (0x3c,
//            constructor 005fb5f0), realTimeConnectors +0x14 (G3D::Array: data +0x14 / num +0x18 / numAllocated +0x1c
//            zeroed), profilingKernel +0x20 = new CodeProfiler("Kernel") (0xc048, constructor 005c43a0), then
//            ++numKernels (0097b5b8).
//   dtor     005faca0: vtable, --numKernels, delete kernelData (~KernelData 005fa970 out of line), ~scoped_ptr (virtual
//            delete through slot 0), ~Array (00507d20 alignedFree, then data / num / numAllocated = 0), ~IStage.
//   leaves   numBodies 005faa20 / numPoints 005faa30 / numConnectors 005faa40 read kernelData +0x4 / +0x10 / +0x1c:
//            the sizes of the first three index arrays, at the donor KernelData offsets.
//   The donor has maxBodies / maxPoints / maxConnectors after realTimeConnectors; 2008 has none (profilingKernel
//   follows realTimeConnectors at +0x20).
#include <G3D/Array.h>
#include <boost/scoped_ptr.hpp>
#include "v8kernel/IStage.h"

struct NativeKernelStagesLayout;

namespace RBX
{
	class KernelData;
	class Connector;
	class Point;
	namespace Profiling
	{
		class CodeProfiler;
	}

	class Kernel : public IStage
	{
		friend struct ::NativeKernelStagesLayout; // tests/NativeKernelStagesLayout.cpp offset asserts

	private:
		bool inStepCode;                                              // +0xc
		KernelData* kernelData;                                       // +0x10
		G3D::Array<Connector*> realTimeConnectors;                    // +0x14
		static int numKernels;                                        // 0097b5b8
	public:
		boost::scoped_ptr<Profiling::CodeProfiler> profilingKernel;   // +0x20

	public:
		Kernel(IStage* upstream);                                     // 005fb650
		virtual ~Kernel();                                            // 005faca0 (slot 0 ??_G 005fb0c0)
		virtual StageType getStageType();                             // slot 1 (0077d800; NATIVE_KERNEL_STAGES_PENDING)
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);   // slot 2 (005fb3f0, not built)
		virtual Kernel* getKernel()                                   // slot 3 (007188c0)
		{
			return this;
		}

		int numBodies() const;                                        // 005faa20
		int numPoints() const;                                        // 005faa30
		int numConnectors() const;                                    // 005faa40
		void insertConnector(Connector* connector);                    // 005fb160
		void deletePoint(Point* point);                                // 005fb3c0
	};
}
