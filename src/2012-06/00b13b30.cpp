// roc 2012-06 00b13b30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b30
//
// 00b13b30  b96823e200           mov ecx, 0xe22368
// 00b13b35  e906bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13b30 { void m(); };
extern T_func_00b13b30 G1_func_00b13b30;
void func_00b13b30()
{
    G1_func_00b13b30.m();
}
