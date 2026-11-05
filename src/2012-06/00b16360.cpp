// roc 2012-06 00b16360  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16360
//
// 00b16360  b920dde200           mov ecx, 0xe2dd20
// 00b16365  e906968fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b16360 { void m(); };
extern T_func_00b16360 G1_func_00b16360;
void func_00b16360()
{
    G1_func_00b16360.m();
}
