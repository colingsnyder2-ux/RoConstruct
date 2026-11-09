// roc 2012-06 00b13bf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13bf0
//
// 00b13bf0  b9ec25e200           mov ecx, 0xe225ec
// 00b13bf5  e9a662a3ff           jmp 0x549ea0
// auto-matched from its assembly shape

struct T_func_00b13bf0 { void m(); };
extern T_func_00b13bf0 G1_func_00b13bf0;
void func_00b13bf0()
{
    G1_func_00b13bf0.m();
}
