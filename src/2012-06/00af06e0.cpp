// roc 2012-06 00af06e0  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af06e0
//
// 00af06e0  b9f85de200           mov ecx, 0xe25df8
// 00af06e5  e94613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af06e0 { void m(); };
extern T_func_00af06e0 G1_func_00af06e0;
void func_00af06e0()
{
    G1_func_00af06e0.m();
}
