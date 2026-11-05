// roc 2012-06 00b158d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b158d0
//
// 00b158d0  b9a8a8e200           mov ecx, 0xe2a8a8
// 00b158d5  e916c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b158d0 { void m(); };
extern T_func_00b158d0 G1_func_00b158d0;
void func_00b158d0()
{
    G1_func_00b158d0.m();
}
