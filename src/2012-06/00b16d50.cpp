// roc 2012-06 00b16d50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16d50
//
// 00b16d50  b930f2e200           mov ecx, 0xe2f230
// 00b16d55  e99632b9ff           jmp 0x6a9ff0
// auto-matched from its assembly shape

struct T_func_00b16d50 { void m(); };
extern T_func_00b16d50 G1_func_00b16d50;
void func_00b16d50()
{
    G1_func_00b16d50.m();
}
