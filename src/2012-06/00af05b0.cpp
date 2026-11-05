// roc 2012-06 00af05b0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af05b0
//
// 00af05b0  b94457e200           mov ecx, 0xe25744
// 00af05b5  e97614a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af05b0 { void m(); };
extern T_func_00af05b0 G1_func_00af05b0;
void func_00af05b0()
{
    G1_func_00af05b0.m();
}
