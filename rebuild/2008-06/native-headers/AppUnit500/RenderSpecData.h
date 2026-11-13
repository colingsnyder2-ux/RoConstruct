#pragma once
// 2008-06 RBX::Render::SpecData layout used by DebugSettings profile getters.
// Kept separate from the later donor Profiler.h, which lacks cpuCount.
#include <string>
#include <G3D/g3dmath.h>

namespace RBX
{
	namespace Render
	{
		struct SpecData
		{
			const float shaderModel;       // +0x00
			const int videoMemory;         // +0x04
			const int CPUSpeed;            // +0x08
			const int cpuCount;            // +0x0c
			const std::string glVendor;    // +0x10
			const std::string gfxcard;     // +0x2c
			const std::string cpu;         // +0x48
			const int ram;                 // +0x64
			const std::string resolution;  // +0x68

			static bool glLoaded;
			SpecData();
		};

		typedef void (*DELAY_FUNC)(unsigned uiMS);
		G3D::int64 GetCyclesDifference(DELAY_FUNC DelayFunction, unsigned uiParameter);
	}
}
