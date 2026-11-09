// roc 2012-06 00b13ea0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ea0
//
// 00b13ea0  b9b834e200           mov ecx, 0xe234b8
// 00b13ea5  e9c6ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13ea0 { void m(); };
extern T_func_00b13ea0 G1_func_00b13ea0;
void func_00b13ea0()
{
    G1_func_00b13ea0.m();
}
