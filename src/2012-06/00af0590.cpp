// roc 2012-06 00af0590  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0590
//
// 00af0590  b90c57e200           mov ecx, 0xe2570c
// 00af0595  e99614a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0590 { void m(); };
extern T_func_00af0590 G1_func_00af0590;
void func_00af0590()
{
    G1_func_00af0590.m();
}
