// roc 2012-06 009cb470  unit: CXTPControlColorSelector  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cb470
//
// 009cb470  8b442408             mov eax, dword ptr [esp + 8]
// 009cb474  56                   push esi
// 009cb475  8bf1                 mov esi, ecx
// 009cb477  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009cb47b  50                   push eax
// 009cb47c  51                   push ecx
// 009cb47d  8bce                 mov ecx, esi
// 009cb47f  e8ecfdffff           call 0x9cb270
// 009cb484  83f8ff               cmp eax, -1
// 009cb487  7408                 je 0x9cb491
// 009cb489  50                   push eax
// 009cb48a  8bce                 mov ecx, esi
// 009cb48c  e81ff4ffff           call 0x9ca8b0
// 009cb491  5e                   pop esi
// 009cb492  c20800               ret 8
// copied from an identical function in another client (function ?func@CXTPControlColorSelector@ns_ROCX00000b@@QAEXHH@Z)

namespace ns_ROCX00000b {
struct CXTPControlColorSelector {
    int sub_672E50(int, int);
    void sub_672460(int);
    void func(int, int);
};

void CXTPControlColorSelector::func(int a, int b) {
    int r = sub_672E50(a, b);
    if (r != -1) {
        sub_672460(r);
    }
}
}
