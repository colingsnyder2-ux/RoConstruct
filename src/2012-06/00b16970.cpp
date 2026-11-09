// roc 2012-06 00b16970  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16970
//
// 00b16970  b9c0e8e200           mov ecx, 0xe2e8c0
// 00b16975  e9f68f8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b16970 { void m(); };
extern T_func_00b16970 G1_func_00b16970;
void func_00b16970()
{
    G1_func_00b16970.m();
}
