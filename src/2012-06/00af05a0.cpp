// roc 2012-06 00af05a0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af05a0
//
// 00af05a0  b92457e200           mov ecx, 0xe25724
// 00af05a5  e98614a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af05a0 { void m(); };
extern T_func_00af05a0 G1_func_00af05a0;
void func_00af05a0()
{
    G1_func_00af05a0.m();
}
