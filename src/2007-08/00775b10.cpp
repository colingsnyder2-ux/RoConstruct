// from server: 100% by atomic.potato
// roc 2007-08 00775b10  unit: seg_00770000  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00775b10
//
// 00775b10  6870b67900           push 0x79b670
// 00775b15  68a8677a00           push 0x7a67a8
// 00775b1a  b9fc7c8c00           mov ecx, 0x8c7cfc
// 00775b1f  e82cfbe7ff           call 0x5f5650
// 00775b24  68f0c77700           push 0x77c7f0
// 00775b29  e8f5b1ebff           call 0x630d23
// 00775b2e  59                   pop ecx
// 00775b2f  c3                   ret

struct S_8C7CFC {
    void method(void *a, void *b);
};

extern "C" void __cdecl sub_630D23(void *p);

void sub_775B10()
{
    S_8C7CFC *p = (S_8C7CFC*)0x8C7CFC;
    p->method((void*)0x7A67A8, (void*)0x79B670);
    sub_630D23((void*)0x77C7F0);
}
