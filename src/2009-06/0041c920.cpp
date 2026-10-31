// from server: 100% by EspClaude
// roc 2009-06 0041c920  unit: CSettingsExplorer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c920
//
// 0041c920  56                   push esi
// 0041c921  8bf1                 mov esi, ecx
// 0041c923  837e7c00             cmp dword ptr [esi + 0x7c], 0
// 0041c927  7514                 jne 0x41c93d
// 0041c929  6874038b00           push 0x8b0374
// 0041c92e  e8ad6bffff           call 0x4134e0
// 0041c933  50                   push eax
// 0041c934  ff15e8e18900         call dword ptr [0x89e1e8]
// 0041c93a  89467c               mov dword ptr [esi + 0x7c], eax
// 0041c93d  8b4e7c               mov ecx, dword ptr [esi + 0x7c]
// 0041c940  8b442408             mov eax, dword ptr [esp + 8]
// 0041c944  8908                 mov dword ptr [eax], ecx
// 0041c946  5e                   pop esi
// 0041c947  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX00006c@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX00006c {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x7c];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_DragShowNolock");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}
