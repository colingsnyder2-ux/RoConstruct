// roc 2012-06 00af06a0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af06a0
//
// 00af06a0  b9305de200           mov ecx, 0xe25d30
// 00af06a5  e98613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af06a0 { void m(); };
extern T_func_00af06a0 G1_func_00af06a0;
void func_00af06a0()
{
    G1_func_00af06a0.m();
}
