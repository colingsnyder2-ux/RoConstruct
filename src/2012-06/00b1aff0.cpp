// roc 2012-06 00b1aff0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aff0
//
// 00b1aff0  b9d005e400           mov ecx, 0xe405d0
// 00b1aff5  e976498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aff0 { void m(); };
extern T_func_00b1aff0 G1_func_00b1aff0;
void func_00b1aff0()
{
    G1_func_00b1aff0.m();
}
