// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include <string>
#include <G3D/RegistryUtil.h>

namespace RBX { namespace Render {

static __declspec(noinline) std::string getCPUMake()
{
	std::string cpuName;
	if (G3D::RegistryUtil::readString(
		"HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\ProcessorNameString",
		cpuName))
	{
		return cpuName;
	}
	else
	{
		// INFERRED: fallback literal at 0x819e10 is not shown in the disassembly; "Unknown" is a guess.
		return "Unknown";
	}
}

} }

// INFERRED: thin caller so MSVC compiles static getCPUMake with internal-linkage IPA matching RenderSpecData.cpp.
std::string Local_00501590_keep()
{
	return RBX::Render::getCPUMake();
}
