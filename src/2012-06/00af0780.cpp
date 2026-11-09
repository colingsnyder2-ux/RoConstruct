// roc 2012-06 00af0780  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0780
//
// 00af0780  b9a873e200           mov ecx, 0xe273a8
// 00af0785  e9a612a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0780 { void m(); };
extern T_func_00af0780 G1_func_00af0780;
void func_00af0780()
{
    G1_func_00af0780.m();
}
