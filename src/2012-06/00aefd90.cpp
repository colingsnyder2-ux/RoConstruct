// roc 2012-06 00aefd90  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aefd90
//
// 00aefd90  b9b045e200           mov ecx, 0xe245b0
// 00aefd95  e9961ca7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aefd90 { void m(); };
extern T_func_00aefd90 G1_func_00aefd90;
void func_00aefd90()
{
    G1_func_00aefd90.m();
}
