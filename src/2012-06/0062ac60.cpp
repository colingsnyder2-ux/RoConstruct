// from server: 100% by Xemicl
// roc 2012-06 0062ac60  unit: G3D::MemoryManager  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062ac60
//
// 0062ac60  8b442404             mov eax, dword ptr [esp + 4]
// 0062ac64  85c0                 test eax, eax
// 0062ac66  740d                 je 0x62ac75
// 0062ac68  8b40fc               mov eax, dword ptr [eax - 4]
// 0062ac6b  89442404             mov dword ptr [esp + 4], eax
// 0062ac6f  ff25c829b200         jmp dword ptr [0xb229c8]
// 0062ac75  c3                   ret 
// copied from an identical function in another client (function ?aligned_free_56b290@@YAXPAX@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl free(void*);
void __cdecl aligned_free_56b290(void* p)
{
    if (p != 0)
        free(((void**)p)[-1]);
}