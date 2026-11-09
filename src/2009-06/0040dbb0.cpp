// from server: 100% by EspClaude
// roc 2009-06 0040dbb0  unit: CIDEBrowserView  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040dbb0
//
// 0040dbb0  8b442404             mov eax, dword ptr [esp + 4]
// 0040dbb4  8b500c               mov edx, dword ptr [eax + 0xc]
// 0040dbb7  83bafc00000005       cmp dword ptr [edx + 0xfc], 5
// 0040dbbe  750f                 jne 0x40dbcf
// 0040dbc0  e8bbf9ffff           call 0x40d580
// 0040dbc5  8b442408             mov eax, dword ptr [esp + 8]
// 0040dbc9  c70001000000         mov dword ptr [eax], 1
// 0040dbcf  c20800               ret 8
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
