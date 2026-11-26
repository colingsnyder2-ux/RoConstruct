// from server: 100% by Xemicl
// roc 2012-06 0042a010  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::Vslot::?$callable  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0042a010
//
// 0042a010  56                   push esi
// 0042a011  8bf1                 mov esi, ecx
// 0042a013  837e6c00             cmp dword ptr [esi + 0x6c], 0
// 0042a017  7514                 jne 0x42a02d
// 0042a019  6830eab400           push 0xb4ea30
// 0042a01e  e8ede9feff           call 0x418a10
// 0042a023  50                   push eax
// 0042a024  ff15b021b200         call dword ptr [0xb221b0]
// 0042a02a  89466c               mov dword ptr [esi + 0x6c], eax
// 0042a02d  8b4e6c               mov ecx, dword ptr [esi + 0x6c]
// 0042a030  8b442408             mov eax, dword ptr [esp + 8]
// 0042a034  8908                 mov dword ptr [eax], ecx
// 0042a036  5e                   pop esi
// 0042a037  c20400               ret 4
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