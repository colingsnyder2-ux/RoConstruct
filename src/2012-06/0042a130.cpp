// from server: 100% by Xemicl
// roc 2012-06 0042a130  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a130
//
// 0042a130  56                   push esi
// 0042a131  8bf1                 mov esi, ecx
// 0042a133  837e7000             cmp dword ptr [esi + 0x70], 0
// 0042a137  7514                 jne 0x42a14d
// 0042a139  6844eab400           push 0xb4ea44
// 0042a13e  e8cde8feff           call 0x418a10
// 0042a143  50                   push eax
// 0042a144  ff15b021b200         call dword ptr [0xb221b0]
// 0042a14a  894670               mov dword ptr [esi + 0x70], eax
// 0042a14d  8b4e70               mov ecx, dword ptr [esi + 0x70]
// 0042a150  8b442408             mov eax, dword ptr [esp + 8]
// 0042a154  8908                 mov dword ptr [eax], ecx
// 0042a156  5e                   pop esi
// 0042a157  c20400               ret 4
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