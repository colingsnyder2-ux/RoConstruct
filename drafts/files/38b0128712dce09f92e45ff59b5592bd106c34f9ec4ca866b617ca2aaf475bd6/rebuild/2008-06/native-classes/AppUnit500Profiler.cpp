// 2008-06 native RenderLib Profiler.cpp unit (inactive): RBX::Render::SpecData and its helpers, 00501180..00501c2f.
// Layout and evidence: native-headers/AppUnit500/RenderSpecData.h. GetCyclesDifference (00501400) is an inline-asm
// rdtsc body and is not built here. Profile: document-swap flags + /fp:fast (without it the constructor spills the
// conditional shaderModel through a stack temporary: 333 / 325 B).
#include "AppUnit500/RenderSpecData.h"
#include <GLG3D/GLCaps.h>
#include <GLG3D/DXCaps.h>
#include <G3D/RegistryUtil.h>
#include <G3D/format.h>
#include <boost/lexical_cast.hpp>
#include <windows.h>

namespace RBX
{
	namespace Render
	{
		bool SpecData::glLoaded = false;

		static float getShaderModel()
		{
			if ((G3D::GLCaps::supports_GL_ARB_fragment_shader() && G3D::GLCaps::supports_GL_ARB_vertex_shader()) ||
				(G3D::GLCaps::supports_GL_ARB_shader_objects() && G3D::GLCaps::supports_GL_ARB_shading_language_100()))
				return 2.0f;

			if (G3D::GLCaps::supports("GL_ATI_fragment_shader") || G3D::GLCaps::supports("GL_NV_fragement_program"))
				return 2.0f;

			if (G3D::GLCaps::supports("GL_ATI_texture_env_combine3") || G3D::GLCaps::supports("GL_NV_texture_shader3"))
				return 1.4f;

			if (G3D::GLCaps::supports("GL_NV_register_combiners"))
				return 1.2f;

			return 1.0f;
		}

		static void Delay(unsigned time)
		{
			LARGE_INTEGER Frequency, StartCounter, EndCounter;
			G3D::int64 x;

			if (!QueryPerformanceFrequency(&Frequency))
				return;

			x = Frequency.QuadPart / 1000 * time;

			QueryPerformanceCounter(&StartCounter);

			do
			{
				QueryPerformanceCounter(&EndCounter);
			}
			while (EndCounter.QuadPart - StartCounter.QuadPart < x);
		}

		static void DelayOverhead(unsigned time)
		{
			LARGE_INTEGER Frequency, StartCounter, EndCounter;
			G3D::int64 x;

			if (!QueryPerformanceFrequency(&Frequency))
				return;

			x = Frequency.QuadPart / 1000 * time;

			QueryPerformanceCounter(&StartCounter);

			do
			{
				QueryPerformanceCounter(&EndCounter);
			}
			while (EndCounter.QuadPart - StartCounter.QuadPart == x);
		}

		static std::string getCPUMake()
		{
			std::string cpu_name;
			if (G3D::RegistryUtil::readString("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\ProcessorNameString", cpu_name))
				return cpu_name;
			else
				return "?";
		}

		static int getCPUCount()
		{
			int count = 0;
			while (true)
			{
				std::string key = G3D::format("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\%d", count);
				if (!G3D::RegistryUtil::keyExists(key))
					break;
				++count;
			}
			return count;
		}

		static int getCPUSpeed()
		{
			G3D::int32 speed;

			if (G3D::RegistryUtil::readInt32("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0\\~MHz", speed))
			{
				if (speed > 300)
					return speed;
			}

			unsigned repetitions = 2;
			unsigned mSecPerRepetition = 50;
			G3D::int64 total = 0;
			G3D::int64 overhead = 0;

			for (unsigned i = 0; i < repetitions; i++)
			{
				total += GetCyclesDifference(&Delay, mSecPerRepetition);
				overhead += GetCyclesDifference(&DelayOverhead, mSecPerRepetition);
			}

			total -= overhead;
			total /= repetitions;
			total /= mSecPerRepetition;
			total /= 1000;

			if (total < 100 || total > 50000)
				total = 1400;

			return (int)total;
		}

		static std::string getMaxRes()
		{
			int width = GetSystemMetrics(SM_CXSCREEN);
			int height = GetSystemMetrics(SM_CYSCREEN);

			std::string w = boost::lexical_cast<std::string>(width);
			std::string h = boost::lexical_cast<std::string>(height);

			return w + "x" + h;
		}

		static int getTotalRAM()
		{
			MEMORYSTATUS memoryStatus;
			GlobalMemoryStatus(&memoryStatus);

			return memoryStatus.dwTotalPhys;
		}

		SpecData::SpecData()
			: shaderModel(glLoaded ? getShaderModel() : 0.0f),
			  videoMemory(G3D::DXCaps::videoMemorySize() / (1 << 20)),
			  CPUSpeed(getCPUSpeed()),
			  cpuCount(getCPUCount()),
			  glVendor(glLoaded ? G3D::GLCaps::vendor() : "?"),
			  gfxcard(glLoaded ? G3D::GLCaps::renderer() : "?"),
			  cpu(getCPUMake()),
			  ram(getTotalRAM() / (1 << 20)),
			  resolution(getMaxRes())
		{
		}
	}
}
