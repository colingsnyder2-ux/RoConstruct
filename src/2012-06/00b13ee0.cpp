// roc 2012-06 00b13ee0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ee0
//
// 00b13ee0  b9d032e200           mov ecx, 0xe232d0
// 00b13ee5  e986ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13ee0 { void m(); };
extern T_func_00b13ee0 G1_func_00b13ee0;
void func_00b13ee0()
{
    G1_func_00b13ee0.m();
}
