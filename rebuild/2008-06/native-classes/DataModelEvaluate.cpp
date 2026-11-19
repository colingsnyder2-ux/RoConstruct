// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/datamodel-2008 /I{headers}/engine-world
// 2008-06 native RBX::DataModel::evaluate 00575d90 (1528 B, Evaluator slot) and its static helper report(double)
// 00575300 (244 B), rows of the DataModel unit (inactive). GUARDED: the body below is byte-identical to the target in
// a batch-24 experiment (same flags, plus a scratch include overlay that added the missing declarations listed under
// "Blockers"): evaluate 1528 B with every relocation bound to its original address, report IDENTICAL (sret in esi,
// inactive_exact 00575300). It stays guarded only because those declarations live in headers this unit does not own.
// Identity: decorated ?evaluate@DataModel@RBX@@UBE?AV?$basic_string@...@ABV34@@Z (identity-registry 00575d90 is still
// the placeholder func_00575d90; DataModel.h already declares the authentic virtual). Keys are the image strings
// 0082ffd8 .. 0082fe0c / 00819e44 .. 00819dd4 in call order; the donor (tools/rbxgs v8datamodel/DataModel.cpp) is the
// 2007 shape (timer/simDC, no Cpu or Kernel keys).
//   Shape notes proved by the experiment: separate 'if (...) return' statements (the eight IMetric keys are tail-merged
//   into the first, graphicsMode, as in the target; one '||' chain moved the body to the end, 1556 B); the Kernel
//   numBodies value is read before the "numBodies" compare into numGroupJobs with numProjectileJobs = 0 (target
//   [esp+0x38] / [esp+0x3c]); report computes 'percent' as its own statement after formatTime (target ftol before
//   c_str and 1/time).
// Blockers (owners), all evidence from the target call/field sites:
//   - util/RunStateOwner.h (core): RunService 00575690 'double getIdleCpuPercent() const' (name provisional, "IdleCpu"
//     key; 72-byte thiscall reading +0x1c0/+0x1c8/+0x1d0/+0x1d8, max(...,0) * 100.0). Fields unknown0x1c8/0x1d0/0x1d8
//     ("SimCpu"/"GfxCpu"/"UiCpu") and frameRate() ("FPS", stopwatch +0x228) already exist.
//   - engine-world/v8world/World.h: numJoints/numContacts/numLinkCalls are at +0xe4/+0xe8/+0xec in 2008 (the header
//     gives +0xd8/+0xdc/+0xe0: 12 bytes missing after breakableJoints); a public inline getter for the +0x80 float
//     ("eThrottle"; the experiment's 'float getThrottlePercentage() const' COMDAT is inactive_exact at 00574fd0).
//   - a Kernel declaration visible together with engine-world World.h (Kernel2008.h cannot be combined with it; the
//     donor v8kernel/Kernel.h lacks these): numLeafBodies 005faa30, numPoints 005faa40, numConnectors 005fa620 (the
//     registry / Kernel2008.h names for 005faa30/005faa40 are donor-order shifted: KernelData2008.h puts leafBodies
//     +0xc, points +0x18, connectors +0x24, and the "numPoints"/"numConstraints" keys call 005faa40/005fa620),
//     matrixSize 005faa90, solverIterations 005fadd0, connectorSpringEnergy 005fa630, totalKineticEnergy 00575040.
//   - contactPairHitRatio 00606bc0 / contactFeatureHitRatio 00606bf0: declared on Contact in Contact2008.h, which cannot
//     be combined with engine-world World.h; the donor Contact.h has only BlockBlockContact::contactPairHitRatio.
#ifdef NATIVE_DATAMODEL_EVALUATE_DECLARATIONS
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"
#include "util/IMetric.h"
#include "util/Log.h"
#include "util/Utilities.h"
#include "v8world/World.h"
#include "v8kernel/Kernel.h"
#include "v8world/Contact.h"
#include "v8kernel/Connector.h"
#include <G3D/format.h>
#include <stdio.h>

namespace RBX
{
	// 00575300: static helper of 00575d90 ("SimCpu" / "GfxCpu" / "UiCpu"); format string 0082fd8c, 3000.0 0082fda0.
	static std::string report(double time)
	{
		if (time > 0.0)
		{
			std::string t = Log::formatTime(time);
			int percent = (int)(time * 3000.0);
			char buffer[256];
			sprintf(buffer, "%i %%  %s (%.3gfps)", percent, t.c_str(), 1.0 / time);
			return std::string(buffer);
		}
		else
		{
			return Log::formatTime(time);
		}
	}

	// 00575d90 (Evaluator slot; this is the Evaluator subobject)
	std::string DataModel::evaluate(const std::string& valueName) const
	{
		World* world = workspace->getWorld();

		if (valueName == "SimCpu")
			return report(runService->unknown0x1c8);
		if (valueName == "GfxCpu")
			return report(runService->unknown0x1d0);
		if (valueName == "UiCpu")
			return report(runService->unknown0x1d8);
		if (valueName == "IdleCpu")
			return G3D::format("%.2g %%", runService->getIdleCpuPercent());
		if (valueName == "FPS")
			return G3D::format("%.3g", runService->frameRate());
		if (valueName == "drawId")
			return StringConverter<int>::convertToString(drawId);
		if (valueName == "graphicsMode")
			return tempMetric->getMetric(valueName);
		if (valueName == "FRM")
			return tempMetric->getMetric(valueName);
		if (valueName == "Particles")
			return tempMetric->getMetric(valueName);
		if (valueName == "Shadows")
			return tempMetric->getMetric(valueName);
		if (valueName == "antiAliasing")
			return tempMetric->getMetric(valueName);
		if (valueName == "bevels")
			return tempMetric->getMetric(valueName);
		if (valueName == "videoMemory")
			return tempMetric->getMetric(valueName);
		if (valueName == "GfxTime")
			return tempMetric->getMetric(valueName);
		if (valueName == "numPrimitives")
			return StringConverter<int>::convertToString(world->getNumPrimitives());
		if (valueName == "numJoints")
			return StringConverter<int>::convertToString(world->getNumJoints());
		if (valueName == "numContacts")
			return StringConverter<int>::convertToString(world->getNumContacts());
		if (valueName == "numContactsInCollisionStage")
			return StringConverter<int>::convertToString(world->getMetric(IWorldStage::NUM_CONTACTSTAGE_CONTACTS));
		if (valueName == "numSteppingContacts")
			return StringConverter<int>::convertToString(world->getMetric(IWorldStage::NUM_STEPPING_CONTACTS));
		if (valueName == "numTouchingContacts")
			return StringConverter<int>::convertToString(world->getMetric(IWorldStage::NUM_TOUCHING_CONTACTS));
		if (valueName == "maxTreeDepth")
			return StringConverter<int>::convertToString(world->getMetric(IWorldStage::MAX_TREE_DEPTH));
		// 00606bc0 / 00606bf0: owner class as the final header declares them (experiment overlay: BlockBlockContact).
		if (valueName == "contactPairHitRatio")
			return StringConverter<float>::convertToString(BlockBlockContact::contactPairHitRatio());
		if (valueName == "contactFeatureHitRatio")
			return StringConverter<float>::convertToString(BlockBlockContact::contactFeatureHitRatio());
		if (valueName == "numLinkCalls")
			return StringConverter<int>::convertToString(world->getNumLinkCalls());
		if (valueName == "numHashNodes")
			return StringConverter<int>::convertToString(world->getNumHashNodes());
		if (valueName == "maxBucketSize")
			return StringConverter<int>::convertToString(world->getMaxBucketSize());
		// World +0x80 float (getter name provisional, see Blockers).
		if (valueName == "eThrottle")
			return StringConverter<float>::convertToString(world->getThrottlePercentage());
		if (valueName == "solverIterations")
			return StringConverter<int>::convertToString(world->getKernel().solverIterations());
		if (valueName == "matrixSize")
			return StringConverter<int>::convertToString(world->getKernel().matrixSize());

		int numGroupJobs = world->getKernel().numBodies();
		int numProjectileJobs = 0;

		if (valueName == "numBodies")
			return StringConverter<int>::convertToString(numGroupJobs + numProjectileJobs);
		if (valueName == "numLeafBodies")
			return StringConverter<int>::convertToString(world->getKernel().numLeafBodies());
		if (valueName == "numGroupJobs")
			return StringConverter<int>::convertToString(numGroupJobs);
		if (valueName == "numProjectileJobs")
			return StringConverter<int>::convertToString(numProjectileJobs);
		if (valueName == "numConstraints")
			return StringConverter<int>::convertToString(world->getKernel().numConnectors());
		if (valueName == "numPoints")
			return StringConverter<int>::convertToString(world->getKernel().numPoints());
		if (valueName == "percentConnectorsActive")
			return StringConverter<float>::convertToString(ContactConnector::percentConnectorsActive());
		if (valueName == "energyBody")
			return StringConverter<float>::convertToString(world->getKernel().bodyKineticEnergy());
		if (valueName == "energyConnector")
			return StringConverter<float>::convertToString(world->getKernel().connectorSpringEnergy());
		if (valueName == "energyTotal")
			return StringConverter<float>::convertToString(world->getKernel().totalKineticEnergy());

		return "?";
	}
}
#endif
