// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /U_RELEASEASSERT
// 2008-06 native RBX::Kernel rows of the original Kernel unit (inactive): bodyKineticEnergy 005faa50, insertConnector
// 005fb160, removeConnector 005fb1f0, removePoint 005fb1a0, newPoint 005fb260, deletePoint 005fb3c0 and stepWorld
// 005fb3f0. Flags copied from AppUnit5F8KernelArrays.cpp / KernelConnector.cpp (the kernel-stage units are built with
// /fp:fast).
// /U_RELEASEASSERT: the target rows carry no RBXASSERT code (insertConnector 005fb160 inlines IndexArray::fastAppend
// without the donor asserts; with them it is 82 B out of line).
//
// Declarations: v8kernel/Kernel2008.h (bodyKineticEnergy, removeConnector, the private removePoint, newPoint) and
// v8kernel/KernelData2008.h (the 0x3c KernelData: bodies +0x0, leafBodies +0xc, points +0x18, connectors +0x24,
// connectors2ndPass +0x30; KernelData 005faff0 / 005fb050, analog names onConnectorAdded / onConnectorRemoved).
// stepWorld 005fb3f0 is `ret 0x10` and tests a fourth byte argument before anything else (a true value calls 005fae00
// with worldStepId and returns), so the 2008 IStage slot 2 takes four arguments: this unit opts in to
// native-headers/kernel-stages (v8kernel/IStage.h with that slot 2 and the 2008 StageType), and Kernel2008.h then
// declares the 4-argument override and 005fae00 (analog name stepMoveBodiesTest).
// Connector: native-headers/v8kernel/Connector2008.h on the 2008 Body path (NATIVE_PRIMITIVE_NATIVE_BODY: Body2008.h,
// Point2008.h, GeoPair2008.h, KernelInput2008.h), as ContactUnit2008ConnectorBody.cpp; it is complete before
// KernelData2008.h (the IndexArray getter owner). No Connector vtable is emitted here.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <G3D/Array.h>
#include "v8kernel/Connector2008.h"
#include "v8kernel/Constants.h"
#include "util/Profiling.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/KernelData2008.h"

namespace RBX
{
	// 005faa50: Body::kineticEnergy 00614670 over KernelData bodies +0x0 / +0x4 (IndexArray, element read by value).
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

	// 005fb1a0: points +0x18 fastRemove (Point::getKernelIndex 005fa610 out of line, Array<Point*>::resize 005fa870).
	void Kernel::removePoint(Point* point)
	{
		kernelData->points.fastRemove(point);
	}

	// 005fb260 (`ret 8`): new 0x34, Point(Body*) 0064dc00, setWorldPos 0064dd40; sameBodyAndOffset inline over points
	// +0x18 (a match gets ++numOwners and the new point is deleted through slot 0); otherwise points fastAppend
	// (getKernelIndex 005fa610, Array<Point*>::append 005fac30 / resize 005fa870 inline). Donor tools/rbxgs
	// v8kernel/Kernel.cpp (insertPoint inline; RBXASSERT(!inStepCode) compiles out).
	Point* Kernel::newPoint(Body* _body, const G3D::Vector3& worldPos)
	{
		Point* nPoint = new Point(_body);

		nPoint->setWorldPos(worldPos);

		for (int i = 0; i < kernelData->points.size(); i++)
		{
			if (Point::sameBodyAndOffset(*nPoint, *kernelData->points[i]))
			{
				kernelData->points[i]->numOwners++;
				delete nPoint;
				return kernelData->points[i];
			}
		}
		kernelData->points.fastAppend(nPoint);
		return nPoint;
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
	// PENDING (NATIVE_KERNEL_STEP_PENDING; ks01, not exact: 631 B vs 502 B). It compiles since the opt-in kernel-stages
	// IStage gives the 4-argument slot 2 (?stepWorld@Kernel@RBX@@UAEXHH_N0@Z; the registry still names 005fb3f0 with the donor 3-argument decoration
	// ?stepWorld@Kernel@RBX@@UAEXHH_N@Z, so it gets no candidate). Every loop, the moveBodiesTest exit (005fae00) and the
	// connector / point / body calls line up. The difference is that the target calls Profiling::Mark::Mark 005c3f80 and
	// ~Mark 005c42d0 out of line (`push 0; push profiler; call`), while the inline Mark of the core util/Profiling.h is
	// expanded here (TlsGetValue / getLocalTime inline, frame 0x20 vs 0x1c). The 005c3f80 / 005c42d0 COMDATs this unit
	// emits are exact, so the 2008 Mark bodies equal the header ones. The blocker is a core-header question (Profiling.h
	// owner), not this unit.
#ifdef NATIVE_KERNEL_STEP_PENDING
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
#endif
}
