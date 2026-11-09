// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 005a4020  unit: RBX::Stats::N::?$TypedStatsItem  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a4020
//
// 005a4020  83ec08               sub esp, 8
// 005a4023  56                   push esi
// 005a4024  8bf1                 mov esi, ecx
// 005a4026  8d8e58010000         lea ecx, [esi + 0x158]
// 005a402c  e88f6fe8ff           call 0x42afc0
// 005a4031  dd5c2404             fstp qword ptr [esp + 4]
// 005a4035  8d442404             lea eax, [esp + 4]
// 005a4039  50                   push eax
// 005a403a  8bce                 mov ecx, esi
// 005a403c  e86f500200           call 0x5c90b0
// 005a4041  5e                   pop esi
// 005a4042  83c408               add esp, 8
// 005a4045  c3                   ret 

struct D { double get(); };
struct S {
    void f();
    void set(double*);
    char data[0xb8];
    D d;
};
void S::f() {
    double value = d.get();
    set(&value);
}
