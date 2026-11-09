// roc 2012-06 00abca10  unit: seg_00ab0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00abca10
//
// 00abca10  b90cfae200           mov ecx, 0xe2fa0c
// 00abca15  e9465ad6ff           jmp 0x822460
// auto-matched from its assembly shape

struct T_func_00abca10 { void m(); };
extern T_func_00abca10 G1_func_00abca10;
void func_00abca10()
{
    G1_func_00abca10.m();
}
