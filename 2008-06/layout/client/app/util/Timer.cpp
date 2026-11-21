#include <windows.h>
#include "AppUnit5F0_2008/RealTime2008.h"

namespace RBX
{
	double getRealTime()
	{
		LARGE_INTEGER counter;
		LARGE_INTEGER frequency;
		QueryPerformanceCounter(&counter);
		QueryPerformanceFrequency(&frequency);
		return (double)counter.QuadPart / (double)frequency.QuadPart;
	}
}
