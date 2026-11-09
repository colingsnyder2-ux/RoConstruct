// roc 2012-06 00b158f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b158f0
//
// 00b158f0  b910a6e200           mov ecx, 0xe2a610
// 00b158f5  e976b8b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b158f0 { void m(); };
extern T_func_00b158f0 G1_func_00b158f0;
void func_00b158f0()
{
    G1_func_00b158f0.m();
}
