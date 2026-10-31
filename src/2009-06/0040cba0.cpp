// from server: 100% by EspClaude
// roc 2009-06 0040cba0  unit: CIDEBrowserView  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040cba0
//
// 0040cba0  56                   push esi
// 0040cba1  8b742408             mov esi, dword ptr [esp + 8]
// 0040cba5  56                   push esi
// 0040cba6  e83bc23000           call 0x718de6
// 0040cbab  85c0                 test eax, eax
// 0040cbad  7507                 jne 0x40cbb6
// 0040cbaf  814e0416408401       or dword ptr [esi + 4], 0x1844016
// 0040cbb6  5e                   pop esi
// 0040cbb7  c20400               ret 4
// copied from an identical function in another client (function ?sub_40dfb0@CBrowserView@ns_ROCX000073@@QAEXPAX@Z)

namespace ns_ROCX000073 {
extern "C" int __stdcall sub_6a0a34(void*);

struct CBrowserView {
    void sub_40dfb0(void* p);
};

void CBrowserView::sub_40dfb0(void* p) {
    if (sub_6a0a34(p) == 0) {
        *(unsigned int*)((char*)p + 4) |= 0x1844016;
    }
}
}
