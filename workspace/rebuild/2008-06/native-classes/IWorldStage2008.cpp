// 2008-06 IWorldStage::getMetric (inactive): slot 6 of every 2008 world-stage vtable that does not override it
// (CleanStage 0084b05c, JointStage 0084cf64, ClumpStage, AssemblyStage, SimJobStage 0084b174) holds 0064a3d0, a tail
// call of the downstream stage's slot 6. The donor v8world/IWorldStage.h declares getMetric without a body; this unit
// supplies it (in 2008 the body sits among the CleanStage COMDATs, so it is header-inline there: see PROPOSALS in
// tests/record_native_kernel_stages.py). Verified by that recorder.
// >>> native-status (generated) -- do not edit >>>
// IWorldStage2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 7f066b32 | roc native-status --write
#include "v8world/IWorldStage.h"

namespace RBX
{
	// 0064a3d0
	int IWorldStage::getMetric(MetricType metricType)
	{
		return getDownstreamWS()->getMetric(metricType);
	}
}
