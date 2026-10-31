// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 006ba510  unit: CXTPPropertyGridItemConstraint  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba510
//
// 006ba510  56                   push esi
// 006ba511  8bf1                 mov esi, ecx
// 006ba513  83be9c00000000       cmp dword ptr [esi + 0x9c], 0
// 006ba51a  7517                 jne 0x6ba533
// 006ba51c  68a4208500           push 0x8520a4
// 006ba521  e81a8ad5ff           call 0x412f40
// 006ba526  50                   push eax
// 006ba527  ff15c0218000         call dword ptr [0x8021c0]
// 006ba52d  89869c000000         mov dword ptr [esi + 0x9c], eax
// 006ba533  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 006ba539  8b442408             mov eax, dword ptr [esp + 8]
// 006ba53d  8908                 mov dword ptr [eax], ecx
// 006ba53f  5e                   pop esi
// 006ba540  c20400               ret 4

extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x9c];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_GetImageInfo");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
