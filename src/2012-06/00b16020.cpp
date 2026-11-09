// roc 2012-06 00b16020  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16020
//
// 00b16020  b914cde200           mov ecx, 0xe2cd14
// 00b16025  e996fbb7ff           jmp 0x695bc0
// auto-matched from its assembly shape

struct T_func_00b16020 { void m(); };
extern T_func_00b16020 G1_func_00b16020;
void func_00b16020()
{
    G1_func_00b16020.m();
}
