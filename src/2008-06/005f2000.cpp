// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/util/Timer.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Timer.h"

#include <windows.h>

namespace RBX {

// FUNCTION: WEBSERVICE 0x10099040
double getRealTime()
{
	LARGE_INTEGER count;
	LARGE_INTEGER frequency;

	QueryPerformanceCounter(&count);
	QueryPerformanceFrequency(&frequency);

	return (double) count.QuadPart / (double) frequency.QuadPart;
}

} // namespace RBX
