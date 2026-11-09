// roc 2012-06 009e6090  unit: CXTSplitterWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e6090
//
// 009e6090  f6810801000008       test byte ptr [ecx + 0x108], 8
// 009e6097  7408                 je 0x9e60a1
// 009e6099  b812000000           mov eax, 0x12
// 009e609e  c20800               ret 8
// 009e60a1  e838c6f9ff           call 0x9826de
// 009e60a6  c20800               ret 8
// copied from an identical function in another client (function ?method@CXTSplitterWnd@ns_ROCX000024@@QAEHHH@Z)

namespace ns_ROCX000024 {
struct CXTSplitterWnd {
    int method(int, int);
};

extern "C" int __cdecl fn_ROCX000024();

int CXTSplitterWnd::method(int a, int b)
{
    if (*(unsigned char*)((char*)this + 0x108) & 8)
        return 0x12;
    return fn_ROCX000024();
}
}
