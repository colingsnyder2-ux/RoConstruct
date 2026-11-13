#pragma once
// 2008-06 native RBX::Render::SpecData and the RenderLib Profiler.cpp helpers (inactive), declared under a
// non-colliding path: the donor RenderLib/Profiler.h has a different (later) layout without cpuCount. A unit must not
// include both headers.
//
// Layout (sizeof 0x84: the DebugSettings "Profile" getters 00563230 / 00563260 / 00563290 reserve `sub esp, 0x84`
// for a stack SpecData, construct it with 00501ae0 and destroy it with the implicit destructor 005631c0, which
// destroys the strings at +0x68, +0x48, +0x2c and +0x10). Field writes of the constructor 00501ae0:
//   shaderModel  +0x00 float  (fstp [esi]: getShaderModel() 005011d0 when glLoaded, else fldz)
//   videoMemory  +0x04 int    (DXCaps::videoMemorySize() 00476470 >> 20, shrd eax, edx, 0x14)
//   CPUSpeed     +0x08 int    (getCPUSpeed() 005016f0); read by the CpuSpeed getter 00563260
//   cpuCount     +0x0c int    (00501650, counts the CentralProcessor\%d registry keys); read by the CpuCount
//                             getter 00563290 (initializer 007f2cc0 "Profile" / "CpuCount")
//   glVendor     +0x10 std::string (GLCaps::vendor() 00470880 when glLoaded, else "?")
//   gfxcard      +0x2c std::string (GLCaps::renderer() 004709a0 when glLoaded, else "?")
//   cpu          +0x48 std::string (getCPUMake() 00501590, sret)
//   ram          +0x64 int    (GlobalMemoryStatus dwTotalPhys, signed / (1 << 20): cdq / and 0xfffff / sar 0x14)
//   resolution   +0x68 std::string (getMaxRes() 005019f0, sret)
// Static: glLoaded (bool, 00972888; `cmp byte ptr [0x972888], bl` in 00501ae0).
// Unit helpers (RenderLib Profiler.cpp; internal linkage like the donor `static` helpers: getCPUMake / getMaxRes are
// exact only as static functions; with external linkage the sret pointer is loaded at a different point:
// getCPUMake 183 B but not exact, getMaxRes 224 / 226 B): getShaderModel 005011d0, GetCyclesDifference 00501400, Delay 005014b0, DelayOverhead 00501520
// (their addresses are pushed by getCPUSpeed at 00501772 / 00501780), getCPUMake 00501590, getCPUCount 00501650
// (analog name), getCPUSpeed 005016f0, getMaxRes 005019f0. GetCyclesDifference is an inline-asm rdtsc body with
// __try / __except (filter 00501484, handler block 0050148a) that this recovery does not build; it is declared here
// with external linkage so getCPUSpeed can call it (the call is a REL32 either way).
#include <string>
#include <G3D/g3dmath.h>

namespace RBX
{
	namespace Render
	{
		struct SpecData
		{
		public:
			const float shaderModel;
			const int videoMemory;
			const int CPUSpeed;
			const int cpuCount;
			const std::string glVendor;
			const std::string gfxcard;
			const std::string cpu;
			const int ram;
			const std::string resolution;

		public:
			static bool glLoaded;

		public:
			SpecData();
		};

		typedef void (*DELAY_FUNC)(unsigned uiMS);

		G3D::int64 GetCyclesDifference(DELAY_FUNC DelayFunction, unsigned uiParameter);
	}
}
