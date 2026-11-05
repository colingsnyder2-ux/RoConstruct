// roc 2012-06 00b167c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b167c0
//
// 00b167c0  b938e7e200           mov ecx, 0xe2e738
// 00b167c5  e926b7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b167c0 { void m(); };
extern T_func_00b167c0 G1_func_00b167c0;
void func_00b167c0()
{
    G1_func_00b167c0.m();
}
