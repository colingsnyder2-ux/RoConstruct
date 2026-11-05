// roc 2012-06 00b13a90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a90
//
// 00b13a90  b93820e200           mov ecx, 0xe22038
// 00b13a95  e956e4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13a90 { void m(); };
extern T_func_00b13a90 G1_func_00b13a90;
void func_00b13a90()
{
    G1_func_00b13a90.m();
}
