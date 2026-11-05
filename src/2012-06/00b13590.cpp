// roc 2012-06 00b13590  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13590
//
// 00b13590  b90015e200           mov ecx, 0xe21500
// 00b13595  e9e628a1ff           jmp 0x525e80
// auto-matched from its assembly shape

struct T_func_00b13590 { void m(); };
extern T_func_00b13590 G1_func_00b13590;
void func_00b13590()
{
    G1_func_00b13590.m();
}
