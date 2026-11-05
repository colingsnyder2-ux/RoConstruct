// roc 2012-06 00b13a50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a50
//
// 00b13a50  b9a825e200           mov ecx, 0xe225a8
// 00b13a55  e916d7b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b13a50 { void m(); };
extern T_func_00b13a50 G1_func_00b13a50;
void func_00b13a50()
{
    G1_func_00b13a50.m();
}
