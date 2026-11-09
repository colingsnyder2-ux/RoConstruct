// roc 2012-06 00b14330  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14330
//
// 00b14330  b9b03ce200           mov ecx, 0xe23cb0
// 00b14335  e90667a4ff           jmp 0x55aa40
// auto-matched from its assembly shape

struct T_func_00b14330 { void m(); };
extern T_func_00b14330 G1_func_00b14330;
void func_00b14330()
{
    G1_func_00b14330.m();
}
