// roc 2012-06 00b133d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b133d0
//
// 00b133d0  b9d812e200           mov ecx, 0xe212d8
// 00b133d5  e996ddb6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b133d0 { void m(); };
extern T_func_00b133d0 G1_func_00b133d0;
void func_00b133d0()
{
    G1_func_00b133d0.m();
}
