// roc 2012-06 00b13ed0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ed0
//
// 00b13ed0  b93829e200           mov ecx, 0xe22938
// 00b13ed5  e996ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13ed0 { void m(); };
extern T_func_00b13ed0 G1_func_00b13ed0;
void func_00b13ed0()
{
    G1_func_00b13ed0.m();
}
