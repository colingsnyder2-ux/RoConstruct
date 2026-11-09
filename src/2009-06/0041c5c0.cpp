// from server: 100% by EspClaude
// roc 2009-06 0041c5c0  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c5c0
//
// 0041c5c0  56                   push esi
// 0041c5c1  8bf1                 mov esi, ecx
// 0041c5c3  837e6c00             cmp dword ptr [esi + 0x6c], 0
// 0041c5c7  7514                 jne 0x41c5dd
// 0041c5c9  6838038b00           push 0x8b0338
// 0041c5ce  e80d6fffff           call 0x4134e0
// 0041c5d3  50                   push eax
// 0041c5d4  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041c5da  89466c               mov dword ptr [esi + 0x6c], eax
// 0041c5dd  8b4e6c               mov ecx, dword ptr [esi + 0x6c]
// 0041c5e0  8b442408             mov eax, dword ptr [esp + 8]
// 0041c5e4  8908                 mov dword ptr [eax], ecx
// 0041c5e6  5e                   pop esi
// 0041c5e7  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX000069@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX000069 {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x6c];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_DragEnter");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
