// roc 2012-06 00af06f0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af06f0
//
// 00af06f0  b90c5ee200           mov ecx, 0xe25e0c
// 00af06f5  e93613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af06f0 { void m(); };
extern T_func_00af06f0 G1_func_00af06f0;
void func_00af06f0()
{
    G1_func_00af06f0.m();
}
