// roc 2012-06 00b11ac0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ac0
//
// 00b11ac0  b94c89e100           mov ecx, 0xe1894c
// 00b11ac5  e9c6ed92ff           jmp 0x440890
// auto-matched from its assembly shape

struct T_func_00b11ac0 { void m(); };
extern T_func_00b11ac0 G1_func_00b11ac0;
void func_00b11ac0()
{
    G1_func_00b11ac0.m();
}
