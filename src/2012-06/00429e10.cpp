// from server: 100% by Xemicl
// roc 2012-06 00429e10  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00429e10
//
// 00429e10  56                   push esi
// 00429e11  8bf1                 mov esi, ecx
// 00429e13  837e6400             cmp dword ptr [esi + 0x64], 0
// 00429e17  7514                 jne 0x429e2d
// 00429e19  6808eab400           push 0xb4ea08
// 00429e1e  e8edebfeff           call 0x418a10
// 00429e23  50                   push eax
// 00429e24  ff15b021b200         call dword ptr [0xb221b0]
// 00429e2a  894664               mov dword ptr [esi + 0x64], eax
// 00429e2d  8b4e64               mov ecx, dword ptr [esi + 0x64]
// 00429e30  8b442408             mov eax, dword ptr [esp + 8]
// 00429e34  8908                 mov dword ptr [eax], ecx
// 00429e36  5e                   pop esi
// 00429e37  c20400               ret 4
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