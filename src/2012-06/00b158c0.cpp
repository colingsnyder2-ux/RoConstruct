// roc 2012-06 00b158c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b158c0
//
// 00b158c0  b918a9e200           mov ecx, 0xe2a918
// 00b158c5  e926c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b158c0 { void m(); };
extern T_func_00b158c0 G1_func_00b158c0;
void func_00b158c0()
{
    G1_func_00b158c0.m();
}
