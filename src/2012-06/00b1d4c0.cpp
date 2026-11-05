// roc 2012-06 00b1d4c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d4c0
//
// 00b1d4c0  b9b0e2e400           mov ecx, 0xe4e2b0
// 00b1d4c5  e9264aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d4c0 { void m(); };
extern T_func_00b1d4c0 G1_func_00b1d4c0;
void func_00b1d4c0()
{
    G1_func_00b1d4c0.m();
}
