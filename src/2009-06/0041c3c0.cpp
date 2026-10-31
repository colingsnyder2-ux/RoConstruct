// from server: 100% by EspClaude
// roc 2009-06 0041c3c0  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c3c0
//
// 0041c3c0  56                   push esi
// 0041c3c1  8bf1                 mov esi, ecx
// 0041c3c3  837e6400             cmp dword ptr [esi + 0x64], 0
// 0041c3c7  7514                 jne 0x41c3dd
// 0041c3c9  6810038b00           push 0x8b0310
// 0041c3ce  e80d71ffff           call 0x4134e0
// 0041c3d3  50                   push eax
// 0041c3d4  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041c3da  894664               mov dword ptr [esi + 0x64], eax
// 0041c3dd  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 0041c3e0  8b442408             mov eax, dword ptr [esp + 8]
// 0041c3e4  8908                 mov dword ptr [eax], ecx
// 0041c3e6  5e                   pop esi
// 0041c3e7  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX000067@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX000067 {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x64];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_BeginDrag");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
