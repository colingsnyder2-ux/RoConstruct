// roc 2012-06 00b170a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b170a0
//
// 00b170a0  b9c0f6e200           mov ecx, 0xe2f6c0
// 00b170a5  e946aea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b170a0 { void m(); };
extern T_func_00b170a0 G1_func_00b170a0;
void func_00b170a0()
{
    G1_func_00b170a0.m();
}
