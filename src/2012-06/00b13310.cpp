// roc 2012-06 00b13310  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13310
//
// 00b13310  b97001e200           mov ecx, 0xe20170
// 00b13315  e956c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13310 { void m(); };
extern T_func_00b13310 G1_func_00b13310;
void func_00b13310()
{
    G1_func_00b13310.m();
}
