// roc 2012-06 00b16f90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f90
//
// 00b16f90  b9e8ede200           mov ecx, 0xe2ede8
// 00b16f95  e956afa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16f90 { void m(); };
extern T_func_00b16f90 G1_func_00b16f90;
void func_00b16f90()
{
    G1_func_00b16f90.m();
}
