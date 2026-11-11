// from server: 100% by EspClaude
// roc-flags: /O1
// roc 2007-08 007252af  unit: CXTIconHandle  size: 38 bytes
// IAT 0x77d2b0 = GetProcessHeap, 0x77d2ac = HeapFree (same imports used by 007252d5 __InitializeThunkPool).
// G1 = __AtlThunkPool (0x8c98b4), G4 = __AtlInterlockedPushEntrySList (0x8c98b8).
extern int G1;
extern "C" __declspec(dllimport) void* __stdcall GetProcessHeap(void);
extern "C" __declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
extern void* (__stdcall *G4)(int, void*);

void* func_007252af(void* a)
{
    if (G1 == 1)
        return (void*)HeapFree(GetProcessHeap(), 0, a);
    return G4(G1, a);
}
