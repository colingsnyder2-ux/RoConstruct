// roc 2012-06 00af0700  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0700
//
// 00af0700  b94c69e200           mov ecx, 0xe2694c
// 00af0705  e92613a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0700 { void m(); };
extern T_func_00af0700 G1_func_00af0700;
void func_00af0700()
{
    G1_func_00af0700.m();
}
