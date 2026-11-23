// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native free (namespace-scope) global data of the exe (inactive): definitions that the native sources only
// declare with local externs. Initial values are the exe's own .data image values read at the address given.
// No headers: each symbol is a plain scalar.
namespace RBX
{
	bool distributedPhysics = false;      // 00974e61 (.bss)
	bool throttleAt30Fps = true;          // 00946790 (.data, initial 1)
	double profilerBucketTimeSpan = 0.01; // 0094f638 (.data)
	double profilerWindow = 3.0;          // 0094f640 (.data)
	long instanceCount = 0;               // 0096df94 (.bss)
	bool shadowsEnabled = false;          // 0096de64 (.bss; INFERRED name, ViewBase2008.h)
	int spatialHashLevels = 4;            // 009625a8 (.data, initial 4; INFERRED name, SpatialHash2008.h)
	int renderMode = 0;                   // INFERRED: address unknown, zero-initialised

	namespace HUMAN
	{
		float freefallYawLimitGain = 120000.0f; // 00962aa8 (.data; analog name, HumanoidStates2.cpp)
	}

	namespace ViewNew
	{
		bool useBevels = true;      // 009413c0 (.data, initial 1)
		bool buildingBevel = false; // 0097275c (.bss)
		float currentBevel = 0.0f;  // 00972758 (.bss)
	}

	namespace RenderNew
	{
		bool shadeGroupCreated = false; // INFERRED: address unknown, zero-initialised
	}
}
