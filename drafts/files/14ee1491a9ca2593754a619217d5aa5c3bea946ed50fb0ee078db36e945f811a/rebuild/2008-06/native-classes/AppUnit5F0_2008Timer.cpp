// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// util/Timer.cpp row 005f2000 of the application range 005f0000..005f8000 (inactive 2008-06 native recovery).
// The original calls QueryPerformanceCounter / QueryPerformanceFrequency through the IAT (00802250 / 0080225c).
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
