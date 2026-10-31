// from server: 100% by EspClaude
// roc 2009-06 0041c4f0  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c4f0
//
// 0041c4f0  56                   push esi
// 0041c4f1  8bf1                 mov esi, ecx
// 0041c4f3  837e6800             cmp dword ptr [esi + 0x68], 0
// 0041c4f7  7514                 jne 0x41c50d
// 0041c4f9  6824038b00           push 0x8b0324
// 0041c4fe  e8dd6fffff           call 0x4134e0
// 0041c503  50                   push eax
// 0041c504  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041c50a  894668               mov dword ptr [esi + 0x68], eax
// 0041c50d  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 0041c510  8b442408             mov eax, dword ptr [esp + 8]
// 0041c514  8908                 mov dword ptr [eax], ecx
// 0041c516  5e                   pop esi
// 0041c517  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX000068@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX000068 {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x68];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_EndDrag");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
