// roc 2012-06 00a56b60  unit: CXTPPropertyGridInplaceEdit  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a56b60
//
// 00a56b60  83792000             cmp dword ptr [ecx + 0x20], 0
// 00a56b64  7407                 je 0xa56b6d
// 00a56b66  6a00                 push 0
// 00a56b68  e837bff2ff           call 0x982aa4
// 00a56b6d  c3                   ret 
// copied from an identical function in another client (function ?f@CXTPPropertyGridInplaceEdit@ns_ROCX0000d4@@QAEXXZ)

namespace ns_ROCX0000d4 {
struct CXTPPropertyGridInplaceEdit
{
    char pad[0x20];
    void* field_20;
    void f();
};

extern "C" void __stdcall sub_0062ff4a(void*);

void CXTPPropertyGridInplaceEdit::f()
{
    if (field_20 != 0)
        sub_0062ff4a(0);
}
}
