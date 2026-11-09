// roc 2012-06 00af0770  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0770
//
// 00af0770  b99473e200           mov ecx, 0xe27394
// 00af0775  e9b612a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0770 { void m(); };
extern T_func_00af0770 G1_func_00af0770;
void func_00af0770()
{
    G1_func_00af0770.m();
}
