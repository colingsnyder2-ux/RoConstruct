// roc 2012-06 00af06d0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af06d0
//
// 00af06d0  b9945de200           mov ecx, 0xe25d94
// 00af06d5  e95613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af06d0 { void m(); };
extern T_func_00af06d0 G1_func_00af06d0;
void func_00af06d0()
{
    G1_func_00af06d0.m();
}
