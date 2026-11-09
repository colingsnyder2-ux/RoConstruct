// roc 2012-06 0085cbc0  unit: VWinHttpRequest_source::?$stream_buffer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085cbc0
//
// 0085cbc0  56                   push esi
// 0085cbc1  8bf1                 mov esi, ecx
// 0085cbc3  807e5800             cmp byte ptr [esi + 0x58], 0
// 0085cbc7  7409                 je 0x85cbd2
// 0085cbc9  e852e4ffff           call 0x85b020
// 0085cbce  c6465800             mov byte ptr [esi + 0x58], 0
// 0085cbd2  5e                   pop esi
// 0085cbd3  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000010@@QAEXXZ)

namespace ns_ROCX000010 {
struct S {
    char pad[0x58];
    char flag;
    void sub_54b960();
    void f();
};

void S::f()
{
    if (flag != 0) {
        sub_54b960();
        flag = 0;
    }
}
}
