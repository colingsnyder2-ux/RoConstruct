// roc 2012-06 00b1cdf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cdf0
//
// 00b1cdf0  b9b0d8e400           mov ecx, 0xe4d8b0
// 00b1cdf5  e97643b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1cdf0 { void m(); };
extern T_func_00b1cdf0 G1_func_00b1cdf0;
void func_00b1cdf0()
{
    G1_func_00b1cdf0.m();
}
