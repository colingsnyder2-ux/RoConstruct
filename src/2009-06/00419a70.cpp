// from server: 100% by EspClaude
// roc 2009-06 00419a70  unit: CInsertObjectDialog  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00419a70
//
// 00419a70  56                   push esi
// 00419a71  8bf1                 mov esi, ecx
// 00419a73  e8e4f82f00           call 0x71935c
// 00419a78  8d8ea8000000         lea ecx, [esi + 0xa8]
// 00419a7e  e857f32f00           call 0x718dda
// 00419a83  33c0                 xor eax, eax
// 00419a85  5e                   pop esi
// 00419a86  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000047@@QAEHXZ)

namespace ns_ROCX000047 {
struct Part {
    void update();
};

struct S {
    unsigned char padding[0xa8];
    Part part;
    void prepare();
    int f();
};

int S::f()
{
    prepare();
    part.update();
    return 0;
}
}
