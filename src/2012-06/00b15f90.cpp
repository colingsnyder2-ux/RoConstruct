// roc 2012-06 00b15f90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15f90
//
// 00b15f90  b9e8c5e200           mov ecx, 0xe2c5e8
// 00b15f95  e9b6f0b7ff           jmp 0x695050
// auto-matched from its assembly shape

struct T_func_00b15f90 { void m(); };
extern T_func_00b15f90 G1_func_00b15f90;
void func_00b15f90()
{
    G1_func_00b15f90.m();
}
