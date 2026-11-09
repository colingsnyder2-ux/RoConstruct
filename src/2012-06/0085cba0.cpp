// roc 2012-06 0085cba0  unit: VWinHttpRequest_source::?$stream_buffer  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0085cba0
//
// 0085cba0  56                   push esi
// 0085cba1  8bf1                 mov esi, ecx
// 0085cba3  807e4800             cmp byte ptr [esi + 0x48], 0
// 0085cba7  7409                 je 0x85cbb2
// 0085cba9  e872e4ffff           call 0x85b020
// 0085cbae  c6464800             mov byte ptr [esi + 0x48], 0
// 0085cbb2  5e                   pop esi
// 0085cbb3  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
struct S {
    char pad[0x48];
    char flag;
    void f();
};

extern "C" void __cdecl helper();

void S::f() {
    if (flag != 0) {
        helper();
        flag = 0;
    }
}
}
