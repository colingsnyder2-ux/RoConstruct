// from server: 100% by EspClaude
// roc 2009-06 0041c800  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c800
//
// 0041c800  56                   push esi
// 0041c801  8bf1                 mov esi, ecx
// 0041c803  837e7400             cmp dword ptr [esi + 0x74], 0
// 0041c807  7514                 jne 0x41c81d
// 0041c809  6860038b00           push 0x8b0360
// 0041c80e  e8cd6cffff           call 0x4134e0
// 0041c813  50                   push eax
// 0041c814  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041c81a  894674               mov dword ptr [esi + 0x74], eax
// 0041c81d  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 0041c820  8b442408             mov eax, dword ptr [esp + 8]
// 0041c824  8908                 mov dword ptr [eax], ecx
// 0041c826  5e                   pop esi
// 0041c827  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX00006b@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX00006b {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x74];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_DragMove");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
