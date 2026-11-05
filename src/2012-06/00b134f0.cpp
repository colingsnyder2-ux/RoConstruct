// roc 2012-06 00b134f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b134f0
//
// 00b134f0  b90815e200           mov ecx, 0xe21508
// 00b134f5  e92658a1ff           jmp 0x528d20
// auto-matched from its assembly shape

struct T_func_00b134f0 { void m(); };
extern T_func_00b134f0 G1_func_00b134f0;
void func_00b134f0()
{
    G1_func_00b134f0.m();
}
