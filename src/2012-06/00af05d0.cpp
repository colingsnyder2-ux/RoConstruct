// roc 2012-06 00af05d0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af05d0
//
// 00af05d0  b9545be200           mov ecx, 0xe25b54
// 00af05d5  e95614a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af05d0 { void m(); };
extern T_func_00af05d0 G1_func_00af05d0;
void func_00af05d0()
{
    G1_func_00af05d0.m();
}
