// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
union LI { struct { unsigned long lo; long hi; } u; __int64 QuadPart; };
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(LI*);
__int64 g_start;
void initStart() { g_start = 0; LI li; QueryPerformanceCounter(&li); g_start = li.QuadPart; }
