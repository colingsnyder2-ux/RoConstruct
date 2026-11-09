// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64*);
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64*);
extern double maxTime;
extern __int64 startTime;
void __stdcall onTimer(int, int, int, int, int)
{
	__int64 now;
	QueryPerformanceCounter(&now);
	__int64 d = now - startTime;
	__int64 freq;
	QueryPerformanceFrequency(&freq);
	double t = (double)d / (double)freq;
	if (t > maxTime)
		maxTime = t;
}
