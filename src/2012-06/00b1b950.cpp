// roc 2012-06 00b1b950  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b950
//
// 00b1b950  b94894e400           mov ecx, 0xe49448
// 00b1b955  e99665a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b950 { void m(); };
extern T_func_00b1b950 G1_func_00b1b950;
void func_00b1b950()
{
    G1_func_00b1b950.m();
}
