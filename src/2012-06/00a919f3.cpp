// from server: 26% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Rendering/RenderLib/Profiler.cpp

// Candidate translation unit (score above; library headers required).
#include "decomp.h"

#include <G3D/RegistryUtil.h>
#include <GLG3D/DXCaps.h>
#include <GLG3D/GLCaps.h>
#include <boost/lexical_cast.hpp>
#include <string>
#include <windows.h>

namespace RBX {
namespace Render {

typedef void (*DelayFunction)(unsigned int uiParameter);

static float getShaderModel();
static int getCPUSpeed();
static std::string getCPUMake();
static std::string getMaxRes();
static int getRam();

// SIZE 0x80
struct SpecData
{
	static bool glLoaded;

	float shaderModel;      // 0x00
	int videoMemory;        // 0x04
	int CPUSpeed;           // 0x08
	std::string glVendor;   // 0x0c
	std::string gfxcard;    // 0x28
	std::string cpu;        // 0x44
	int ram;                // 0x60
	std::string resolution; // 0x64

	SpecData();
};

DECOMP_SIZE_ASSERT(SpecData, 0x80)

bool SpecData::glLoaded;

// FUNCTION: WEBSERVICE 0x10169a30
static float getShaderModel()
{
	if ((G3D::GLCaps::supports_GL_ARB_fragment_shader() && G3D::GLCaps::supports_GL_ARB_vertex_shader()) ||
		(G3D::GLCaps::supports_GL_ARB_shader_objects() && G3D::GLCaps::supports_GL_ARB_shading_language_100())) {
		return 2.0f;
	}

	if (G3D::GLCaps::supports("GL_ATI_fragment_shader") || G3D::GLCaps::supports("GL_NV_fragement_program")) {
		return 2.0f;
	}

	if (G3D::GLCaps::supports("GL_ATI_texture_env_combine3") || G3D::GLCaps::supports("GL_NV_texture_shader3")) {
		return 1.4f;
	}

	if (G3D::GLCaps::supports("GL_NV_register_combiners")) {
		return 1.2f;
	}

	return 1.0f;
}

// FUNCTION: WEBSERVICE 0x10169c60
static __int64 GetCyclesDifference(DelayFunction DelayFunction, unsigned int uiParameter)
{
	unsigned int t0Lo, t0Hi;
	unsigned int t1Lo, t1Hi;

	__try {
		__asm {
			rdtsc
			mov esi, eax
			mov edi, edx

			push uiParameter
			call DelayFunction
			pop ebx

			rdtsc
			mov t1Hi, edx
			mov t1Lo, eax

			mov t0Hi, edi
			mov t0Lo, esi
		}
	}
	__except (1) {
		return 0;
	}

	return (__int64) t1Hi * 0x100000000 - ((__int64) t0Hi << 32) - t0Lo + t1Lo;
}

// FUNCTION: WEBSERVICE 0x10169d20
static void Delay(unsigned int time)
{
	LARGE_INTEGER Frequency, StartCounter, EndCounter;

	if (QueryPerformanceFrequency(&Frequency)) {
		__int64 ticks = (Frequency.QuadPart / 1000) * time;

		QueryPerformanceCounter(&StartCounter);

		do {
			QueryPerformanceCounter(&EndCounter);
		} while ((EndCounter.QuadPart - StartCounter.QuadPart) < ticks);
	}
}

// FUNCTION: WEBSERVICE 0x10169d90
static void DelayOverhead(unsigned int time)
{
	LARGE_INTEGER Frequency, StartCounter, EndCounter;

	if (QueryPerformanceFrequency(&Frequency)) {
		__int64 ticks = (Frequency.QuadPart / 1000) * time;

		QueryPerformanceCounter(&StartCounter);

		do {
			QueryPerformanceCounter(&EndCounter);
		} while ((EndCounter.QuadPart - StartCounter.QuadPart) == ticks);
	}
}

// FUNCTION: WEBSERVICE 0x10169e00
static std::string getCPUMake()
{
	std::string cpu_name;

	if (G3D::RegistryUtil::readString(
			"HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\ProcessorNameString",
			cpu_name
		)) {
		return cpu_name;
	}

	return "Could not determine CPU name";
}

// FUNCTION: WEBSERVICE 0x10169ee0
static int getCPUSpeed()
{
	int speed;

	if (G3D::RegistryUtil::read32bitNumber(
			"HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\~MHz",
			speed
		)) {
		if (speed > 300) {
			return speed;
		}
	}

	__int64 total = 0;
	__int64 overhead = 0;

	for (int i = 0; i < 2; i++) {
		total += GetCyclesDifference(Delay, 50);
		overhead += GetCyclesDifference(DelayOverhead, 50);
	}

	total = (total - overhead) / 2;
	total = total / 50;
	total = total / 1000;

	if (total < 100 || total > 50000) {
		total = 1400;
	}

	return (int) total;
}

// FUNCTION: WEBSERVICE 0x10169ff0
static std::string getMaxRes()
{
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	std::string w = boost::lexical_cast<std::string>(width);
	std::string h = boost::lexical_cast<std::string>(height);

	return w + "x" + h;
}

static int getRam()
{
	MEMORYSTATUS memoryStatus;

	GlobalMemoryStatus(&memoryStatus);

	return (int) memoryStatus.dwTotalPhys / (1024 * 1024);
}

// FUNCTION: WEBSERVICE 0x1016a100
SpecData::SpecData()
	: shaderModel(glLoaded ? getShaderModel() : 0.0f),
	  videoMemory((int) (G3D::DXCaps::videoMemorySize() / (1024 * 1024))), CPUSpeed(getCPUSpeed()),
	  glVendor(glLoaded ? G3D::GLCaps::vendor() : "?"), gfxcard(glLoaded ? G3D::GLCaps::renderer() : "?"),
	  cpu(getCPUMake()), ram(getRam()), resolution(getMaxRes())
{
}

} // namespace Render
} // namespace RBX
