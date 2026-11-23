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
#include "util/Math.h"
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

	// 005fa630 (registry placeholder func_005fa630; const thiscall, plain `ret`): openrbx v8kernel/Kernel.cpp
	// connectorSpringEnergy. Sums Connector::potentialEnergy (slot 5) over the KernelData connectors (+0x24 data / +0x28
	// num, kernelData +0x10 reloaded every iteration). Caller: DataModel's 'energyConnector' stat (DataModelEvaluate.cpp).
	float Kernel::connectorSpringEnergy() const
	{
		float springPotential = 0.0f;

		for (int i = 0; i < kernelData->connectors.size(); ++i)
			springPotential += kernelData->connectors[i]->potentialEnergy();

		return springPotential;
	}

	// 005faaa0 (registry placeholder func_005faaa0; thiscall `ret 4`; only caller stepMoveBodiesTest 005fae00). Per KernelData
	// body (+0x0 data / +0x4 num, kernelData kept in a local): getCoordinateFrame (updatePV 00599360, Matrix3 copy
	// 00513220), translation += the argument, Math::rotateAboutYGlobal 005df140 by 0.01f (0082748c),
	// Math::orthonormalizeIfNecessary 005df0a0 of the rotation, Body::setCoordinateFrame 00614400. INFERRED name.
	void Kernel::moveBodiesTest(const G3D::Vector3& delta)
	{
		KernelData* data = kernelData;

		for (int i = 0; i < data->bodies.size(); i++)
		{
			Body* body = data->bodies[i];
			G3D::CoordinateFrame cframe = body->getCoordinateFrame();
			cframe.translation += delta;
			Math::rotateAboutYGlobal(cframe, 0.01f);
			Math::orthonormalizeIfNecessary(cframe.rotation);
			body->setCoordinateFrame(cframe);
		}
	}

	// 005fae00 (registry placeholder func_005fae00; thiscall `ret 4`; caller stepWorld 005fb3f0 when its fourth argument is
	// true). Every Constants::worldStepsPerUiStep (0063e420, folded `mov eax, 8`) world steps: the ui step number divided
	// by Constants::uiStepsPerSec (006492c0, `mov eax, 0x1e`), modulo 4 (signed), picks +x / +y / -x / -y (fld1 and -1.0f
	// 0081c3b8 into two locals zeroed first), scaled by 0.4f (00832a18) with z = 0, then moveBodiesTest 005faaa0.
	void Kernel::stepMoveBodiesTest(int worldStepId)
	{
		if (worldStepId % Constants::worldStepsPerUiStep() == 0)
		{
			int uiStepId = worldStepId / Constants::worldStepsPerUiStep();
			G3D::Vector3 direction(0.0f, 0.0f, 0.0f);

			switch ((uiStepId / Constants::uiStepsPerSec()) % 4)
			{
			case 0:
				direction.x = 1.0f;
				break;
			case 1:
				direction.y = 1.0f;
				break;
			case 2:
				direction.x = -1.0f;
				break;
			case 3:
				direction.y = -1.0f;
				break;
			}

			direction *= 0.4f;
			moveBodiesTest(direction);
		}
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
	// owner), not this unit. st01 (b23): the out-of-line Mark calls are not specific to this body: SleepStage 0064c8a0
	// also calls 005c3f80 / 005c42d0 for each of its three marks, and both bodies lie in the Profiling unit's own range
	// (next to Profiler 005c43a0), not among COMDATs placed after their callers, so the 2008 util/Profiling.h most likely
	// declared Mark::Mark / ~Mark and defined them in Profiling.cpp. Scratch proof (not kept): this exact body, built with
	// -DNATIVE_KERNEL_STEP_PENDING against a copy of util/Profiling.h whose Mark constructor / destructor are only
	// declared, is IDENTICAL to 005fb3f0 (502 B). Remaining blockers: that core-header change (Profiling.h owner) and the
	// registry decoration ?stepWorld@Kernel@RBX@@UAEXHH_N0@Z for 005fb3f0.
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
	// BLOCKED (guard below): the KernelData leaf-body helpers and Kernel::insertBody / removeBody read Body's private
	// leafBodyIndex +0x4 / numConnectors +0x8 / simBody +0x2c (and the private updatePV 00599360), and
	// native-headers/v8kernel/Body2008.h (not assigned to this batch) grants no access. Proposal: add
	// `friend class Kernel; friend class KernelData;` to RBX::Body in Body2008.h (the 2007 openrbx v8kernel/Body.h declares
	// both friends), then define BODY_HEADER_GRANTS_KERNEL_ACCESS there (or drop this guard).
#ifdef BODY_HEADER_GRANTS_KERNEL_ACCESS
	// 005faed0 (registry placeholder func_005faed0; thiscall `ret 4`, recursive): every child (Body children +0x1c / +0x20)
	// with connectors (numConnectors +0x8 > 0) is appended to leafBodies +0xc with leafBodyIndex +0x4 = its old size
	// (Array<Body*>::append 005fabc0); then the child's own children. INFERRED name.
	void KernelData::addLeafBodies(Body* b)
	{
		for (int i = 0; i < b->numChildren(); i++)
		{
			Body* child = b->getChild(i);
			if (child->numConnectors > 0)
			{
				child->leafBodyIndex = leafBodies.size();
				leafBodies.append(child);
			}
			addLeafBodies(child);
		}
	}

	// 005faf20 (registry placeholder func_005faf20; thiscall `ret 4`, recursive; caller Kernel::removeBody 005fb110):
	// updatePV 00599360 of the body, then every child in leafBodies (leafBodyIndex +0x4 >= 0) is swap-removed (last element
	// moved into its slot, Array<Body*>::resize 005fa770 to size - 1 without shrinking, index = -1), then its own
	// children. INFERRED name.
	void KernelData::removeLeafBodies(Body* b)
	{
		b->updatePV();

		for (int i = 0; i < b->numChildren(); i++)
		{
			Body* child = b->getChild(i);
			int removeIndex = child->leafBodyIndex;
			if (removeIndex >= 0)
			{
				Body* movedBody = leafBodies[leafBodies.size() - 1];
				leafBodies[removeIndex] = movedBody;
				movedBody->leafBodyIndex = removeIndex;
				leafBodies.resize(leafBodies.size() - 1, false);
				child->leafBodyIndex = -1;
			}
			removeLeafBodies(child);
		}
	}

	// 005faf90 (registry placeholder func_005faf90; thiscall `ret 4`; caller Kernel::insertBody 005fb0e0): a body still in
	// leafBodies (+0x4 >= 0) is swap-removed from it, the body is appended to bodies +0x0 (kernelIndex = old size,
	// Array<Body*>::append 005fabc0), then addLeafBodies 005faed0. INFERRED name.
	void KernelData::insertBody(Body* b)
	{
		int removeIndex = b->leafBodyIndex;
		if (removeIndex >= 0)
		{
			Body* movedBody = leafBodies[leafBodies.size() - 1];
			leafBodies[removeIndex] = movedBody;
			movedBody->leafBodyIndex = removeIndex;
			leafBodies.resize(leafBodies.size() - 1, false);
			b->leafBodyIndex = -1;
		}
		bodies.fastAppend(b);
		addLeafBodies(b);
	}

	// 005fb0e0 (registry placeholder func_005fb0e0; thiscall `ret 4`; caller SimJobStage 0064d0f0): KernelData::insertBody
	// 005faf90, then Constants::kernelDt 00649310 stored into simBody +0x2c ->dt +0x4 when there is a simBody (the dt is
	// evaluated first: fstp st(0) on the NULL path). openrbx v8kernel/Kernel.cpp insertBody plus the 2008 dt store.
	void Kernel::insertBody(Body* b)
	{
		kernelData->insertBody(b);

		float dt = Constants::kernelDt();
		if (b->simBody)
			b->simBody->dt = dt;
	}

	// 005fb110 (registry placeholder func_005fb110; thiscall `ret 4`): Constants::kernelDt 00649310 called first and its
	// result discarded (INFERRED: an unused local), bodies +0x0 fastRemove inline (kernelIndex +0x0, Array<Body*>::resize
	// 005fa770), KernelData::removeLeafBodies 005faf20, then simBody->dt = 0 when there is a simBody.
	void Kernel::removeBody(Body* b)
	{
		float dt = Constants::kernelDt();
		kernelData->bodies.fastRemove(b);
		kernelData->removeLeafBodies(b);

		if (b->simBody)
			b->simBody->dt = 0.0f;
	}
	// 005faff0 (registry placeholder func_005faff0; analog name, declared in KernelData2008.h; caller Kernel::insertConnector
	// 005fb160): for both connector bodies (Connector::getBody slot 4): ++numConnectors +0x8; a body whose root (+0x10) is in
	// the kernel (root kernelIndex != -1), that is not the root and is not yet in leafBodies (+0x4 < 0) is appended.
	void KernelData::onConnectorAdded(Connector* c)
	{
		for (int i = 0; i < 2; i++)
		{
			Body* b = c->getBody(i);
			if (b)
			{
				b->numConnectors++;
				Body* root = b->getRoot();
				if (root->getKernelIndex() != -1 && b != root && b->leafBodyIndex < 0)
				{
					b->leafBodyIndex = leafBodies.size();
					leafBodies.append(b);
				}
			}
		}
	}

	// 005fb050 (registry placeholder func_005fb050; analog name, declared in KernelData2008.h; caller Kernel::removeConnector
	// 005fb1f0): for both connector bodies: --numConnectors; a body in leafBodies (+0x4 >= 0) whose count dropped to 0 is
	// swap-removed (Array<Body*>::resize 005fa770, index = -1).
	void KernelData::onConnectorRemoved(Connector* c)
	{
		for (int i = 0; i < 2; i++)
		{
			Body* b = c->getBody(i);
			if (b)
			{
				b->numConnectors--;
				int removeIndex = b->leafBodyIndex;
				if (removeIndex >= 0 && b->numConnectors == 0)
				{
					Body* movedBody = leafBodies[leafBodies.size() - 1];
					leafBodies[removeIndex] = movedBody;
					movedBody->leafBodyIndex = removeIndex;
					leafBodies.resize(leafBodies.size() - 1, false);
					b->leafBodyIndex = -1;
				}
			}
		}
	}
#endif
}
