// roc 2012-06 00b1db30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1db30
//
// 00b1db30  b998f3e400           mov ecx, 0xe4f398
// 00b1db35  e9b643a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1db30 { void m(); };
extern T_func_00b1db30 G1_func_00b1db30;
void func_00b1db30()
{
    G1_func_00b1db30.m();
}
