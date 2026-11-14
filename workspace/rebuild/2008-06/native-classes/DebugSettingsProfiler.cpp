// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::DebugSettings (inactive): the "Throttle" / "Profiling" accessors and setShowWorldCoordinateFrames
// of the original DebugSettings unit (getters 00563170..005631a0, setters 005639f0 / 00563a20 / 00565cb0..00565d10).
// The rest of the class is native-classes/DebugSettings.cpp and DebugSettingsCoordinateGetters.cpp (read-only); flags
// follow AppUnit560DebugProfile.cpp without /fp:fast. Evidence for the class in native-headers/v8datamodel/DebugSettings.h.
//   The setters for the bool properties are `if (value != global) { global = value; raisePropertyChanged(prop); }`
//   (the tail-jump to Instance::raisePropertyChanged 0040db00 pushes the descriptor), exactly like the sibling
//   setShowModelCoordinateFrames 00565c80. The double setters clamp at 0.001 (.rdata 00827988) and fire no event.
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/Workspace.h"
#include <algorithm>

namespace RBX
{
	// Defined in native-classes/DebugSettings.cpp (dynamic initializers 007f2c30..007f3200).
	// Proposal: drop `static` there so this unit can link to them.
	extern Reflection::PropDescriptor<DebugSettings, bool> prop_ShowWorldCoords;      // 009746a8
	extern Reflection::PropDescriptor<DebugSettings, bool> prop_30FpsThrottle;        // 009746fc
	extern Reflection::PropDescriptor<DebugSettings, bool> prop_DistributedPhysics;   // 009745f8

	// INFERRED: process-wide settings read by these accessors; no header declares them and their owners are unnamed.
	//   distributedPhysics: bool at 00974e61, also read by func_00578ca0 / func_0057a6c0 (world stepping).
	//   throttleAt30Fps:    bool at 00946790 (.data, initial 1), read by the RunService step 00555190.
	//   profilerWindow:     double at 0094f640 (.data, initial 3.0), read by func_005a02e0 / func_005c9fe0.
	//   profilerBucketTimeSpan: double at 0094f638 (.data, initial 0.01), read by Profiling::Profiler::Profiler 005c4340.
	extern bool distributedPhysics;
	extern bool throttleAt30Fps;
	extern double profilerWindow;
	extern double profilerBucketTimeSpan;

	// 00563170
	double DebugSettings::getProfilerWindow() const
	{
		return profilerWindow;
	}

	// 00563180
	double DebugSettings::getProfilerBucketTimeSpan() const
	{
		return profilerBucketTimeSpan;
	}

	// 00563190
	bool DebugSettings::getDistributedPhysics() const
	{
		return distributedPhysics;
	}

	// 005631a0
	bool DebugSettings::get30FpsThrottle() const
	{
		return throttleAt30Fps;
	}

	// 005639f0
	void DebugSettings::setProfilerWindow(double value)
	{
		profilerWindow = std::max(value, 0.001);
	}

	// 00563a20
	void DebugSettings::setProfilerBucketTimeSpan(double value)
	{
		profilerBucketTimeSpan = std::max(value, 0.001);
	}

	// 00565cb0
	void DebugSettings::setShowWorldCoordinateFrames(bool value)
	{
		if (value != Workspace::showWorldCoord)
		{
			Workspace::showWorldCoord = value;
			raisePropertyChanged(prop_ShowWorldCoords);
		}
	}

	// 00565ce0
	void DebugSettings::setDistributedPhysics(bool value)
	{
		if (value != distributedPhysics)
		{
			distributedPhysics = value;
			raisePropertyChanged(prop_DistributedPhysics);
		}
	}

	// 00565d10
	void DebugSettings::set30FpsThrottle(bool value)
	{
		if (value != throttleAt30Fps)
		{
			throttleAt30Fps = value;
			raisePropertyChanged(prop_30FpsThrottle);
		}
	}
}
