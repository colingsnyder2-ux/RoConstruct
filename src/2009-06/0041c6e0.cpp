// from server: 100% by EspClaude
// roc 2009-06 0041c6e0  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c6e0
//
// 0041c6e0  56                   push esi
// 0041c6e1  8bf1                 mov esi, ecx
// 0041c6e3  837e7000             cmp dword ptr [esi + 0x70], 0
// 0041c6e7  7514                 jne 0x41c6fd
// 0041c6e9  684c038b00           push 0x8b034c
// 0041c6ee  e8ed6dffff           call 0x4134e0
// 0041c6f3  50                   push eax
// 0041c6f4  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041c6fa  894670               mov dword ptr [esi + 0x70], eax
// 0041c6fd  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0041c700  8b442408             mov eax, dword ptr [esp + 8]
// 0041c704  8908                 mov dword ptr [eax], ecx
// 0041c706  5e                   pop esi
// 0041c707  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX00006a@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX00006a {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x70];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_DragLeave");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
