// from server: 100% by Yeetserama
// roc 2007-08 00448260  unit: CIDEDocManager  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00448260
//
// 00448260  6aff                 push -1
// 00448262  689bfa7300           push 0x73fa9b
// 00448267  64a100000000         mov eax, dword ptr fs:[0]
// 0044826d  50                   push eax
// 0044826e  81ec34010000         sub esp, 0x134
// 00448274  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448279  33c4                 xor eax, esp
// 0044827b  89842430010000       mov dword ptr [esp + 0x130], eax
// 00448282  a188518b00           mov eax, dword ptr [0x8b5188]
// 00448287  33c4                 xor eax, esp
// 00448289  50                   push eax
// 0044828a  8d842438010000       lea eax, [esp + 0x138]
// 00448291  64a300000000         mov dword ptr fs:[0], eax
// 00448297  6a00                 push 0
// 00448299  8d4c2408             lea ecx, [esp + 8]
// 0044829d  e8be8ffbff           call 0x401260
// 004482a2  8d4c2404             lea ecx, [esp + 4]
// 004482a6  c784244001000000000000 mov dword ptr [esp + 0x140], 0
// 004482b1  e8747b1e00           call 0x62fe2a
// 004482b6  8d4c2404             lea ecx, [esp + 4]
// 004482ba  c7842440010000ffffffff mov dword ptr [esp + 0x140], 0xffffffff
// 004482c5  e8d68dfbff           call 0x4010a0
// 004482ca  8b8c2438010000       mov ecx, dword ptr [esp + 0x138]
// 004482d1  64890d00000000       mov dword ptr fs:[0], ecx
// 004482d8  59                   pop ecx
// 004482d9  8b8c2430010000       mov ecx, dword ptr [esp + 0x130]
// 004482e0  33cc                 xor ecx, esp
// 004482e2  e837871e00           call 0x630a1e
// 004482e7  81c440010000         add esp, 0x140
// 004482ed  c3                   ret 
// copied from an identical function in another client (function ?OnAppAbout@CIDEDocManager@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
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
