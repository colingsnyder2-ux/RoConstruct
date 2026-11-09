// roc 2012-06 00b1f1c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f1c0
//
// 00b1f1c0  b97024e500           mov ecx, 0xe52470
// 00b1f1c5  e9a65ed6ff           jmp 0x885070
// auto-matched from its assembly shape

struct T_func_00b1f1c0 { void m(); };
extern T_func_00b1f1c0 G1_func_00b1f1c0;
void func_00b1f1c0()
{
    G1_func_00b1f1c0.m();
}
