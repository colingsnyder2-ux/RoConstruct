// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::Kernel rows of the original Kernel unit (inactive): bodyKineticEnergy 005faa50, insertConnector
// 005fb160, removeConnector 005fb1f0, deletePoint 005fb3c0 and stepWorld 005fb3f0. Flags copied from
// AppUnit5F8KernelArrays.cpp / KernelConnector.cpp (the kernel-stage units are built with /fp:fast).
//
// PENDING (NATIVE_KERNEL_DATA_PENDING): every row needs declarations that no native header has yet, so the bodies are
// compiled only with the proposed headers (see the header proposals of this batch):
//   - v8kernel/KernelData2008.h: the 2008 KernelData is 0x3c with five index arrays (bodies +0x0, leaf bodies +0xc,
//     points +0x18, connectors +0x24, connectors2ndPass +0x30); the donor v8kernel/KernelData.h (0x30, four arrays,
//     points +0xc / connectors +0x18) and its donor Body.h cannot be used next to native-headers/v8kernel/Body2008.h.
//     KernelData::005faff0 / 005fb050 (analog names onConnectorAdded / onConnectorRemoved) maintain Body +0x8 and the
//     leaf body array; insertConnector / removeConnector call them.
//   - Kernel2008.h: removeConnector 005fb1f0, bodyKineticEnergy 005faa50 and the private removePoint 005fb1a0 (called
//     out of line by deletePoint) are not declared; stepWorld 005fb3f0 is `ret 0x10` and tests a fourth byte argument
//     before anything else (a true value calls 005fae00 with worldStepId and returns), so the 2008 IStage slot 2 takes
//     four arguments, not the donor three.
// Validated against the target with those proposed headers (scratch copies): see the batch receipt.
#ifdef NATIVE_KERNEL_DATA_PENDING
#include <G3D/Array.h>
#include "v8kernel/KernelIndex.h"
#include "v8kernel/Body2008.h"
#include "v8kernel/Point2008.h"
#include "v8kernel/Constants.h"
#include "util/Profiling.h"
#include "v8kernel/Kernel2008.h"

namespace RBX
{
	// Unit-local redeclaration, exactly as native-headers/v8kernel/Connector2008.h declares Connector (same base, slots
	// and noinline getKernelIndex; RTTI 0083d1f4), following ContactUnit2008ConnectorBody.cpp: Connector2008.h includes
	// the donor v8kernel/Body.h, which cannot be declared next to Body2008.h (C2011). No vtable is emitted here.
	class Connector : public KernelIndex
	{
	public:
		Connector() {}
		__declspec(noinline) int& getKernelIndex() { return kernelIndex; }
		virtual ~Connector() {}                                         // slot 0 (??_G 006062c0)
		virtual void computeForce(const float dt, bool throttling) = 0; // slot 1
		virtual bool canThrottle() const                                // slot 2 (00565950)
		{
			return true;
		}
		virtual bool getBroken()                                        // slot 3 (0060a2f0)
		{
			return false;
		}
		virtual Body* getBody(int i) = 0;                               // slot 4 (analog name)
		virtual float potentialEnergy()                                 // slot 5 (005e72c0)
		{
			return 0;
		}
	};
}

#include "v8kernel/KernelData2008.h"

namespace RBX
{
	// 005faa50: Body::kineticEnergy 00614670 over KernelData +0x0 / +0x4.
	float Kernel::bodyKineticEnergy() const
	{
		float totalEnergy = 0.0;

		for (int i = 0; i < kernelData->bodies.size(); i++)
			totalEnergy += kernelData->bodies[i]->kineticEnergy();

		return totalEnergy;
	}

	// 005fb160: connectors +0x24 fastAppend (Connector::getKernelIndex 005fa610, Array<Connector*>::append 005fab50),
	// then KernelData 005faff0.
	void Kernel::insertConnector(Connector* c)
	{
		kernelData->connectors.fastAppend(c);
		kernelData->onConnectorAdded(c);
	}

	// 005fb1f0: KernelData 005fb050, realTimeConnectors +0x14 resize(0, false) (005fa670), then connectors +0x24
	// fastRemove.
	void Kernel::removeConnector(Connector* c)
	{
		kernelData->onConnectorRemoved(c);
		realTimeConnectors.resize(0, false);
		kernelData->connectors.fastRemove(c);
	}

	// 005fb3c0: numOwners +0x8; removePoint 005fb1a0 and the Point scalar deleting destructor (slot 0).
	void Kernel::deletePoint(Point* point)
	{
		if (point)
		{
			point->numOwners--;
			if (point->numOwners == 0)
			{
				removePoint(point);
				delete point;
			}
		}
	}

	// 005fb3f0: inStepCode +0xc, Profiling::Mark (005c3f80 / 005c42d0) on profilingKernel +0x20; realTimeConnectors
	// +0x14 rebuilt when throttling (canThrottle slot 2); Constants::kernelDt 00649310 and kernelStepsPerWorldStep
	// 006492d0 (19) read after that block; per kernel step: Point::step 0064dc90, computeForce (slot 1) of the
	// real-time or all connectors, Point::forceToBody 0064dc70, connectors2ndPass, Body::step 00614200, then
	// Body::updatePV 00599360 of the leaf bodies +0xc.
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
}
#endif
