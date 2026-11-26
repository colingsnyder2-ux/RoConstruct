// from server: 100% by Xemicl
// roc 2012-06 007de570  unit: RBX::VInstance::?$NonFactoryProduct  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007de570
//
// 007de570  6aff                 push -1
// 007de572  68438cac00           push 0xac8c43
// 007de577  64a100000000         mov eax, dword ptr fs:[0]
// 007de57d  50                   push eax
// 007de57e  64892500000000       mov dword ptr fs:[0], esp
// 007de585  51                   push ecx
// 007de586  6a28                 push 0x28
// 007de588  c744241000000000     mov dword ptr [esp + 0x10], 0
// 007de590  e8853b1a00           call 0x98211a
// 007de595  83c404               add esp, 4
// 007de598  890424               mov dword ptr [esp], eax
// 007de59b  c644240c01           mov byte ptr [esp + 0xc], 1
// 007de5a0  85c0                 test eax, eax
// 007de5a2  740e                 je 0x7de5b2
// 007de5a4  8d4c2414             lea ecx, [esp + 0x14]
// 007de5a8  51                   push ecx
// 007de5a9  8bc8                 mov ecx, eax
// 007de5ab  e890fbffff           call 0x7de140
// 007de5b0  eb02                 jmp 0x7de5b4
// 007de5b2  33c0                 xor eax, eax
// 007de5b4  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 007de5b8  8d4c2414             lea ecx, [esp + 0x14]
// 007de5bc  8902                 mov dword ptr [edx], eax
// 007de5be  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 007de5c6  e8b5f5ffff           call 0x7ddb80
// 007de5cb  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007de5cf  64890d00000000       mov dword ptr fs:[0], ecx
// 007de5d6  83c410               add esp, 0x10
// 007de5d9  c23000               ret 0x30
// copied from an identical function in another client (function ?create@Factory@@QAEXUP@@PAPAUT@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P {
    int d[10];
    P(const P&);
    ~P();
};
struct T {
    int d[10];
    T(const P&);
};
struct Factory {
    void create(P p, T** out, int unused);
};
void Factory::create(P p, T** out, int unused)
{
    *out = new T(p);
}