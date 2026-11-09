// roc 2012-06 009e55f0  unit: CXTSplitterWnd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e55f0
//
// 009e55f0  8b442404             mov eax, dword ptr [esp + 4]
// 009e55f4  898108010000         mov dword ptr [ecx + 0x108], eax
// 009e55fa  a802                 test al, 2
// 009e55fc  740d                 je 0x9e560b
// 009e55fe  c781fc00000000000000 mov dword ptr [ecx + 0xfc], 0
// 009e5608  c20400               ret 4
// 009e560b  6a00                 push 0
// 009e560d  81c1fc000000         add ecx, 0xfc
// 009e5613  51                   push ecx
// 009e5614  6a00                 push 0
// 009e5616  6a26                 push 0x26
// 009e5618  ff15543ab200         call dword ptr [0xb23a54]
// 009e561e  c20400               ret 4
// copied from an identical function in another client (function ?SetSomething@CXTSplitterWnd@ns_ROCX000021@@QAEXH@Z)

namespace ns_ROCX000021 {
extern "C" int (__stdcall *SystemParametersInfoA)(unsigned int, unsigned int, void*, unsigned int);

struct CXTSplitterWnd {
    char pad[0xfc];
    int field_fc;
    char pad2[8];
    int field_108;
    void SetSomething(int);
};

void CXTSplitterWnd::SetSomething(int value) {
    field_108 = value;
    if (value & 2) {
        field_fc = 0;
    } else {
        SystemParametersInfoA(0x26, 0, &field_fc, 0);
    }
}
}
