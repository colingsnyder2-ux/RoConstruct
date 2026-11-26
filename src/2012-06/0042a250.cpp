// from server: 100% by Xemicl
// roc 2012-06 0042a250  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a250
//
// 0042a250  56                   push esi
// 0042a251  8bf1                 mov esi, ecx
// 0042a253  837e7400             cmp dword ptr [esi + 0x74], 0
// 0042a257  7514                 jne 0x42a26d
// 0042a259  6858eab400           push 0xb4ea58
// 0042a25e  e8ade7feff           call 0x418a10
// 0042a263  50                   push eax
// 0042a264  ff15b021b200         call dword ptr [0xb221b0]
// 0042a26a  894674               mov dword ptr [esi + 0x74], eax
// 0042a26d  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 0042a270  8b442408             mov eax, dword ptr [esp + 8]
// 0042a274  8908                 mov dword ptr [eax], ecx
// 0042a276  5e                   pop esi
// 0042a277  c20400               ret 4
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