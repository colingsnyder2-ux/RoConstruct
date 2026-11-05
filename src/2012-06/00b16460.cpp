// roc 2012-06 00b16460  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16460
//
// 00b16460  b988dae200           mov ecx, 0xe2da88
// 00b16465  e986baa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16460 { void m(); };
extern T_func_00b16460 G1_func_00b16460;
void func_00b16460()
{
    G1_func_00b16460.m();
}
