// roc 2012-06 00b13a60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a60
//
// 00b13a60  b9c81fe200           mov ecx, 0xe21fc8
// 00b13a65  e906d7b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b13a60 { void m(); };
extern T_func_00b13a60 G1_func_00b13a60;
void func_00b13a60()
{
    G1_func_00b13a60.m();
}
