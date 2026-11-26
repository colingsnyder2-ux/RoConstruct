// from server: 100% by Xemicl
// roc 2012-06 00429f40  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00429f40
//
// 00429f40  56                   push esi
// 00429f41  8bf1                 mov esi, ecx
// 00429f43  837e6800             cmp dword ptr [esi + 0x68], 0
// 00429f47  7514                 jne 0x429f5d
// 00429f49  681ceab400           push 0xb4ea1c
// 00429f4e  e8bdeafeff           call 0x418a10
// 00429f53  50                   push eax
// 00429f54  ff15b021b200         call dword ptr [0xb221b0]
// 00429f5a  894668               mov dword ptr [esi + 0x68], eax
// 00429f5d  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 00429f60  8b442408             mov eax, dword ptr [esp + 8]
// 00429f64  8908                 mov dword ptr [eax], ecx
// 00429f66  5e                   pop esi
// 00429f67  c20400               ret 4
// copied from an identical function in another client (function ?getProcedure@CSettingsExplorer@ns_ROCX000068@@QAEPAPAXPAPAX@Z)

namespace ns_ROCX000068 {
extern "C" void* __cdecl getModule();
extern "C" void* (__stdcall *GetProcAddress)(void*, const char*);

struct CSettingsExplorer {
    char padding[0x68];
    void* procedure;
    void** getProcedure(void** result);
};

void** CSettingsExplorer::getProcedure(void** result) {
    if (!procedure)
        procedure = GetProcAddress(getModule(), "ImageList_EndDrag");
    *result = *reinterpret_cast<void* volatile*>(&procedure);
    return result;
}
}