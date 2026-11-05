// roc 2012-06 00b1f1d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f1d0
//
// 00b1f1d0  b9b824e500           mov ecx, 0xe524b8
// 00b1f1d5  e9965ed6ff           jmp 0x885070
// auto-matched from its assembly shape

struct T_func_00b1f1d0 { void m(); };
extern T_func_00b1f1d0 G1_func_00b1f1d0;
void func_00b1f1d0()
{
    G1_func_00b1f1d0.m();
}
