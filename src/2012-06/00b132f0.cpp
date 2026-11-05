// roc 2012-06 00b132f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b132f0
//
// 00b132f0  b95803e200           mov ecx, 0xe20358
// 00b132f5  e976c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b132f0 { void m(); };
extern T_func_00b132f0 G1_func_00b132f0;
void func_00b132f0()
{
    G1_func_00b132f0.m();
}
