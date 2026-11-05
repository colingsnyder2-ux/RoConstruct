// roc 2012-06 00b13730  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13730
//
// 00b13730  b90006e200           mov ecx, 0xe20600
// 00b13735  e9b6e7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13730 { void m(); };
extern T_func_00b13730 G1_func_00b13730;
void func_00b13730()
{
    G1_func_00b13730.m();
}
