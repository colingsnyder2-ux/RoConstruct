// roc 2012-06 00b13710  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13710
//
// 00b13710  b9000fe200           mov ecx, 0xe20f00
// 00b13715  e9d6e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13710 { void m(); };
extern T_func_00b13710 G1_func_00b13710;
void func_00b13710()
{
    G1_func_00b13710.m();
}
