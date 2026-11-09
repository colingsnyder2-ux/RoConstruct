// roc 2012-06 00b13790  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13790
//
// 00b13790  b95808e200           mov ecx, 0xe20858
// 00b13795  e956e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13790 { void m(); };
extern T_func_00b13790 G1_func_00b13790;
void func_00b13790()
{
    G1_func_00b13790.m();
}
