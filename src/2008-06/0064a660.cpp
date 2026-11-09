// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_e9459ee4124ecd0d.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/SleepStage.h", "roc_unit_e122b107650b8d44.cpp")
#pragma include_alias("v8world/Assembly.h", "roc_unit_ca287567c820d3b7.cpp")
#pragma include_alias("v8world/Clump.h", "roc_unit_9da8b0a292a9525e.cpp")
#pragma include_alias("v8world/Primitive.h", "roc_unit_1deee9af9b5e9e77.cpp")
#pragma include_alias("v8kernel/Body.h", "roc_unit_fdeff9a4ea2b6152.cpp")
#pragma include_alias("v8world/Edge.h", "roc_unit_ad178cfd636587c6.cpp")
#include "v8world/SleepStage.h"
#include "v8world/SimJobStage.h"
#include "v8kernel/Body.h"
namespace RBX {
bool SleepStage::forceNeighborAwake(Assembly* a)
{
	G3D::CoordinateFrame cofm = a->getAssemblyPrimitiveConst()->getBody()->getBranchCofmCoordinateFrame();
	float radius = a->getMaxRadius();
	bool withinTolerance =
		a->getSleepInfo()->runningAverageState.withinTolerance(cofm, radius, 2.0f * sleepTolerance());

	return !withinTolerance;
}

bool SleepStage::okNeighborSleep(Assembly* a)
{
	G3D::CoordinateFrame cofm = a->getAssemblyPrimitiveConst()->getBody()->getBranchCofmCoordinateFrame();
	float radius = a->getMaxRadius();

	return a->getSleepInfo()->runningAverageState.withinTolerance(cofm, radius, sleepTolerance());
}

bool SleepStage::computeShouldSleep(Assembly* a)
{
	G3D::CoordinateFrame cofm = a->getAssemblyPrimitiveConst()->getBody()->getBranchCofmCoordinateFrame();
	float maxRadius = a->getMaxRadius();
	RunningAverageState& runningAverageState = a->getSleepInfo()->runningAverageState;

	runningAverageState.update(cofm, maxRadius);

	return runningAverageState.withinTolerance(cofm, maxRadius, sleepTolerance());
}
}
