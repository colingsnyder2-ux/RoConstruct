// from server: 100% by Xemicl
// roc 2012-06 00415410  unit: CIDEBrowserView  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415410
//
// 00415410  56                   push esi
// 00415411  8b742408             mov esi, dword ptr [esp + 8]
// 00415415  56                   push esi
// 00415416  e89bd05600           call 0x9824b6
// 0041541b  85c0                 test eax, eax
// 0041541d  7507                 jne 0x415426
// 0041541f  814e0416408401       or dword ptr [esi + 4], 0x1844016
// 00415426  5e                   pop esi
// 00415427  c20400               ret 4
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