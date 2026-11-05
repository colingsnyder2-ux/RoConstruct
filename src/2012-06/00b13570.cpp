// roc 2012-06 00b13570  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13570
//
// 00b13570  b91c15e200           mov ecx, 0xe2151c
// 00b13575  e9a632a1ff           jmp 0x526820
// auto-matched from its assembly shape

struct T_func_00b13570 { void m(); };
extern T_func_00b13570 G1_func_00b13570;
void func_00b13570()
{
    G1_func_00b13570.m();
}
