// roc 2012-06 00af06b0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af06b0
//
// 00af06b0  b9705de200           mov ecx, 0xe25d70
// 00af06b5  e97613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af06b0 { void m(); };
extern T_func_00af06b0 G1_func_00af06b0;
void func_00af06b0()
{
    G1_func_00af06b0.m();
}
