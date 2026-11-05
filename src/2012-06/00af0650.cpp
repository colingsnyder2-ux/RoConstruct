// roc 2012-06 00af0650  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0650
//
// 00af0650  b9505ce200           mov ecx, 0xe25c50
// 00af0655  e9d613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0650 { void m(); };
extern T_func_00af0650 G1_func_00af0650;
void func_00af0650()
{
    G1_func_00af0650.m();
}
