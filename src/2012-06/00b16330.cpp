// roc 2012-06 00b16330  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16330
//
// 00b16330  b950d9e200           mov ecx, 0xe2d950
// 00b16335  e9b63cb9ff           jmp 0x6a9ff0
// auto-matched from its assembly shape

struct T_func_00b16330 { void m(); };
extern T_func_00b16330 G1_func_00b16330;
void func_00b16330()
{
    G1_func_00b16330.m();
}
