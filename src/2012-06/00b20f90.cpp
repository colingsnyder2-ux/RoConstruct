// roc 2012-06 00b20f90  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20f90
//
// 00b20f90  b9f065e500           mov ecx, 0xe565f0
// 00b20f95  e9560fa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20f90 { void m(); };
extern T_func_00b20f90 G1_func_00b20f90;
void func_00b20f90()
{
    G1_func_00b20f90.m();
}
