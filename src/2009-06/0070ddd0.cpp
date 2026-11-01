// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
long g_count;
struct H { void* h; void close(); };
void H::close() { if (h) { CloseHandle(h); h = 0; InterlockedDecrement(&g_count); } }
