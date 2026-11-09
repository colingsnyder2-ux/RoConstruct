// roc 2012-06 00b15fa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15fa0
//
// 00b15fa0  b938c9e200           mov ecx, 0xe2c938
// 00b15fa5  e9c6998fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15fa0 { void m(); };
extern T_func_00b15fa0 G1_func_00b15fa0;
void func_00b15fa0()
{
    G1_func_00b15fa0.m();
}
