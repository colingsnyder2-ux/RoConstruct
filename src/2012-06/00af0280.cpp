// roc 2012-06 00af0280  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0280
//
// 00af0280  b9304fe200           mov ecx, 0xe24f30
// 00af0285  e9a617a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0280 { void m(); };
extern T_func_00af0280 G1_func_00af0280;
void func_00af0280()
{
    G1_func_00af0280.m();
}
