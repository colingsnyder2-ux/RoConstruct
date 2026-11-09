// roc 2012-06 00b13630  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13630
//
// 00b13630  b94005e200           mov ecx, 0xe20540
// 00b13635  e906c4d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13630 { void m(); };
extern T_func_00b13630 G1_func_00b13630;
void func_00b13630()
{
    G1_func_00b13630.m();
}
