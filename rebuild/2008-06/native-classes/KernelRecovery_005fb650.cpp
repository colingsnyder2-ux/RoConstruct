// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Kernel (draft; lease: family:class_RBX_Kernel).
// Two functions: 005fb650 (rtti-ctor-dtor, 178 bytes) and 005fb3f0 (stepWorld, 502 bytes).
// stepWorld is slot 2 of the vftable (own-vft tier): tests a fourth bool argument first
// (true calls 005fae00 with worldStepId, then returns). The inline Mark of core util/Profiling.h
// is expanded here (TlsGetValue / getLocalTime inline, frame 0x20 vs 0x1c).
// PENDING (NATIVE_KERNEL_STEP_PENDING): core-header question (Profiling.h owner), not this unit.
// stepWorld 005fb3f0 differs from donor: target calls Profiling::Mark::Mark 005c3f80 and
// ~Mark 005c42d0 out of line (`push 0; push profiler; call`), while inline Mark of util/Profiling.h
// is expanded here (TlsGetValue / getLocalTime inline, frame 0x20 vs 0x1c).
// The 005c3f80 / 005c42d0 COMDATs this unit emits are exact, so the 2008 Mark bodies equal the header ones.
// include its native header; add missing declarations to that header under lease as // INFERRED: lines.

#include "v8kernel/Kernel2008.h"
#include "v8kernel/KernelData.h"
#include "util/Profiling.h"

namespace RBX
{

// 005fb650 (rtti-ctor-dtor, 178 bytes):
// Kernel(IStage* upstream): IStage(upstream, NULL), inStepCode +0xc = false,
// kernelData +0x10 = new KernelData (0x3c, constructor 005fb5f0),
// profilingKernel +0x20 = new CodeProfiler("Kernel") (0xc048, constructor 005c43a0),
// then ++numKernels (0097b5b8).
// INFERRED: KernelData size 0x3c differs from donor 0x30; CodeProfiler 0x20040 differs from 0xc048.
// The scalar deleting destructor 005fb0c0 (vtable 0084105c) calls ~Kernel 005faca0.
Kernel::Kernel(IStage* upstream)
    : IStage(upstream, NULL),
      inStepCode(false),
      kernelData(new KernelData()),
      profilingKernel(new Profiling::CodeProfiler("Kernel"))
{
    ++numKernels;
}

// 005fb3f0 (stepWorld, 502 bytes, vftable-slot (own-vft tier)):
// Virtual slot 2: void stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
// Tests a fourth bool argument first (true: call 005fae00 with worldStepId, then return).
// PENDING (NATIVE_KERNEL_STEP_PENDING; ks01, not exact: 631 B vs 502 B).
// The difference is that the target calls Profiling::Mark::Mark 005c3f80 and
// ~Mark 005c42d0 out of line (`push 0; push profiler; call`), while the inline Mark of the core
// util/Profiling.h is expanded here (TlsGetValue / getLocalTime inline, frame 0x20 vs 0x1c).
// The 005c3f80 / 005c42d0 COMDATs this unit emits are exact, so the 2008 Mark bodies equal the header ones.
// INFERRED: the fourth argument convention and moveBodiesTest path are inferred from the binary;
// core-header question (Profiling.h owner) remains the blocker for exact size match.
void Kernel::stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
{
    if (moveBodiesTest)
    {
        stepMoveBodiesTest(worldStepId);
        return;
    }

    KernelData* data = kernelData;
    inStepCode = true;
    {
        Profiling::Mark mark(*profilingKernel.get(), false);

        if (throttling)
        {
            realTimeConnectors.resize(0, false);

            for (int i = 0; i < data->connectors.size(); i++)
            {
                if (!data->connectors[i]->canThrottle())
                {
                    realTimeConnectors.append(data->connectors[i]);
                }
            }
        }

        float kernelDt = Constants::kernelDt();
        int kernelSteps = Constants::kernelStepsPerWorldStep();

        for (int i = 0; i < kernelSteps; i++)
        {
            for (int j = 0; j < data->points.size(); j++)
            {
                data->points[j]->step();
            }

            if (throttling)
            {
                for (int j = 0; j < realTimeConnectors.size(); j++)
                {
                    realTimeConnectors[j]->computeForce(kernelDt, throttling);
                }
            }
            else
            {
                for (int j = 0; j < data->connectors.size(); j++)
                {
                    data->connectors[j]->computeForce(kernelDt, throttling);
                }
            }

            for (int j = 0; j < data->points.size(); j++)
            {
                data->points[j]->forceToBody();
            }

            for (int j = 0; j < data->connectors2ndPass.size(); j++)
            {
                data->connectors2ndPass[j]->computeForce(kernelDt, throttling);
            }

            for (int j = 0; j < data->bodies.size(); j++)
            {
                data->bodies[j]->step(throttling);
            }

            for (int j = 0; j < data->leafBodies.size(); j++)
            {
                data->leafBodies[j]->getPV();
            }
        }
        inStepCode = false;
    }
}

} // namespace RBX