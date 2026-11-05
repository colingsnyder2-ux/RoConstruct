// from server: 100% by EspClaude
// roc 2009-06 00445700  unit: CRobloxApp  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445700
//
// 00445700  6aff                 push -1
// 00445702  681b068500           push 0x85061b
// 00445707  64a100000000         mov eax, dword ptr fs:[0]
// 0044570d  50                   push eax
// 0044570e  64892500000000       mov dword ptr fs:[0], esp
// 00445715  81ec30010000         sub esp, 0x130
// 0044571b  6a00                 push 0
// 0044571d  8d4c2404             lea ecx, [esp + 4]
// 00445721  e8dabefbff           call 0x401600
// 00445726  8d0c24               lea ecx, [esp]
// 00445729  c784243801000000000000 mov dword ptr [esp + 0x138], 0
// 00445734  e8c7342d00           call 0x718c00
// 00445739  8d0c24               lea ecx, [esp]
// 0044573c  c7842438010000ffffffff mov dword ptr [esp + 0x138], 0xffffffff
// 00445747  e874b9fbff           call 0x4010c0
// 0044574c  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 00445753  64890d00000000       mov dword ptr fs:[0], ecx
// 0044575a  81c43c010000         add esp, 0x13c
// 00445760  c3                   ret 
// copied from an identical function in another client (function ?OnAppAbout@CIDEDocManager@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
struct Dialog {
    char storage[0x12c];

    Dialog(void* parent);
    virtual ~Dialog();
    virtual int DoModal();
};

struct CIDEDocManager {
    void OnAppAbout();
};

void CIDEDocManager::OnAppAbout()
{
    Dialog dialog(0);
    dialog.DoModal();
}
}
