// roc 2012-06 00b143c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b143c0
//
// 00b143c0  b93442e200           mov ecx, 0xe24234
// 00b143c5  e926b2a4ff           jmp 0x55f5f0
// auto-matched from its assembly shape

struct T_func_00b143c0 { void m(); };
extern T_func_00b143c0 G1_func_00b143c0;
void func_00b143c0()
{
    G1_func_00b143c0.m();
}
