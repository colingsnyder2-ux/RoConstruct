// from server: 100% by Xemicl
// roc 2012-06 0042a370  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a370
//
// 0042a370  56                   push esi
// 0042a371  8bf1                 mov esi, ecx
// 0042a373  837e7c00             cmp dword ptr [esi + 0x7c], 0
// 0042a377  7514                 jne 0x42a38d
// 0042a379  686ceab400           push 0xb4ea6c
// 0042a37e  e88de6feff           call 0x418a10
// 0042a383  50                   push eax
// 0042a384  ff15b021b200         call dword ptr [0xb221b0]
// 0042a38a  89467c               mov dword ptr [esi + 0x7c], eax
// 0042a38d  8b4e7c               mov ecx, dword ptr [esi + 0x7c]
// 0042a390  8b442408             mov eax, dword ptr [esp + 8]
// 0042a394  8908                 mov dword ptr [eax], ecx
// 0042a396  5e                   pop esi
// 0042a397  c20400               ret 4
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