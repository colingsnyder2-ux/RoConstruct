// roc 2012-06 00b13bb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13bb0
//
// 00b13bb0  b90c25e200           mov ecx, 0xe2250c
// 00b13bb5  e936e3a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13bb0 { void m(); };
extern T_func_00b13bb0 G1_func_00b13bb0;
void func_00b13bb0()
{
    G1_func_00b13bb0.m();
}
