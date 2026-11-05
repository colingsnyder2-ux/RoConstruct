// roc 2012-06 00af0490  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0490
//
// 00af0490  b9b052e200           mov ecx, 0xe252b0
// 00af0495  e99615a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0490 { void m(); };
extern T_func_00af0490 G1_func_00af0490;
void func_00af0490()
{
    G1_func_00af0490.m();
}
