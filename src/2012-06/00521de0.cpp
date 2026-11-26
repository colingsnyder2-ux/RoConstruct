// from server: 100% by Xemicl
// roc 2012-06 00521de0  unit: rbx::signals::$$A6AXXZ::?$signal::Vslot::?$callable  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00521de0
//
// 00521de0  6aff                 push -1
// 00521de2  6863b3aa00           push 0xaab363
// 00521de7  64a100000000         mov eax, dword ptr fs:[0]
// 00521ded  50                   push eax
// 00521dee  64892500000000       mov dword ptr fs:[0], esp
// 00521df5  51                   push ecx
// 00521df6  6a30                 push 0x30
// 00521df8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00521e00  e815034600           call 0x98211a
// 00521e05  83c404               add esp, 4
// 00521e08  890424               mov dword ptr [esp], eax
// 00521e0b  c644240c01           mov byte ptr [esp + 0xc], 1
// 00521e10  85c0                 test eax, eax
// 00521e12  740e                 je 0x521e22
// 00521e14  8d4c2414             lea ecx, [esp + 0x14]
// 00521e18  51                   push ecx
// 00521e19  8bc8                 mov ecx, eax
// 00521e1b  e890faffff           call 0x5218b0
// 00521e20  eb02                 jmp 0x521e24
// 00521e22  33c0                 xor eax, eax
// 00521e24  8b542444             mov edx, dword ptr [esp + 0x44]
// 00521e28  8d4c2418             lea ecx, [esp + 0x18]
// 00521e2c  8902                 mov dword ptr [edx], eax
// 00521e2e  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00521e36  e815bdffff           call 0x51db50
// 00521e3b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00521e3f  64890d00000000       mov dword ptr fs:[0], ecx
// 00521e46  83c410               add esp, 0x10
// 00521e49  c23800               ret 0x38
// copied from an identical function in another client (function ?create@Factory@@QAEXUP@@PAPAUT@@H@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Q { int d[11]; ~Q(); };
struct P {
    int a;
    Q q;
};
struct T {
    int d[12];
    T(const P&);
};
struct Factory {
    void create(P p, T** out, int unused);
};
void Factory::create(P p, T** out, int unused)
{
    *out = new T(p);
}