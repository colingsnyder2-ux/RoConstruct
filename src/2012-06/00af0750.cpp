// roc 2012-06 00af0750  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0750
//
// 00af0750  b96073e200           mov ecx, 0xe27360
// 00af0755  e9d612a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0750 { void m(); };
extern T_func_00af0750 G1_func_00af0750;
void func_00af0750()
{
    G1_func_00af0750.m();
}
