// roc 2012-06 00b1f5f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f5f0
//
// 00b1f5f0  b98c27e500           mov ecx, 0xe5278c
// 00b1f5f5  e9f628a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f5f0 { void m(); };
extern T_func_00b1f5f0 G1_func_00b1f5f0;
void func_00b1f5f0()
{
    G1_func_00b1f5f0.m();
}
