// roc 2012-06 00af0630  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0630
//
// 00af0630  b9f05be200           mov ecx, 0xe25bf0
// 00af0635  e9f613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0630 { void m(); };
extern T_func_00af0630 G1_func_00af0630;
void func_00af0630()
{
    G1_func_00af0630.m();
}
