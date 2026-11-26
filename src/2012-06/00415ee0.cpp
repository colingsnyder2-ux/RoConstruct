// from server: 100% by Xemicl
// roc 2012-06 00415ee0  unit: CIDEBrowserView  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00415ee0
//
// 00415ee0  8b442404             mov eax, dword ptr [esp + 4]
// 00415ee4  8b500c               mov edx, dword ptr [eax + 0xc]
// 00415ee7  83bafc00000005       cmp dword ptr [edx + 0xfc], 5
// 00415eee  750f                 jne 0x415eff
// 00415ef0  e8ebf8ffff           call 0x4157e0
// 00415ef5  8b442408             mov eax, dword ptr [esp + 8]
// 00415ef9  c70001000000         mov dword ptr [eax], 1
// 00415eff  c20800               ret 8
// copied from an identical function in another client (function ?sub_40B2F0@CBrowserView@ns_ROCX000006@@QAEXPAH0@Z)

namespace ns_ROCX000006 {
struct CBrowserView {
    void sub_40B070();

    void sub_40B2F0(int* a1, int* a2);
};

void CBrowserView::sub_40B2F0(int* a1, int* a2) {
    int* p = *(int**)((char*)a1 + 0xc);
    if (*(int*)((char*)p + 0xfc) == 5) {
        sub_40B070();
        *a2 = 1;
    }
}
}