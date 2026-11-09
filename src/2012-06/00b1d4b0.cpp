// roc 2012-06 00b1d4b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d4b0
//
// 00b1d4b0  b920e4e400           mov ecx, 0xe4e420
// 00b1d4b5  e9364aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d4b0 { void m(); };
extern T_func_00b1d4b0 G1_func_00b1d4b0;
void func_00b1d4b0()
{
    G1_func_00b1d4b0.m();
}
