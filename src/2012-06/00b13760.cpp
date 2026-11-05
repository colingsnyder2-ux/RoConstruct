// roc 2012-06 00b13760  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13760
//
// 00b13760  b90c0ae200           mov ecx, 0xe20a0c
// 00b13765  e986e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13760 { void m(); };
extern T_func_00b13760 G1_func_00b13760;
void func_00b13760()
{
    G1_func_00b13760.m();
}
