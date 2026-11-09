// roc 2012-06 00b158e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b158e0
//
// 00b158e0  b9f8a4e200           mov ecx, 0xe2a4f8
// 00b158e5  e906c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b158e0 { void m(); };
extern T_func_00b158e0 G1_func_00b158e0;
void func_00b158e0()
{
    G1_func_00b158e0.m();
}
