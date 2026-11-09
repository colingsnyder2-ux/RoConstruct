// roc 2012-06 00b1d470  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d470
//
// 00b1d470  b944e6e400           mov ecx, 0xe4e644
// 00b1d475  e9764aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d470 { void m(); };
extern T_func_00b1d470 G1_func_00b1d470;
void func_00b1d470()
{
    G1_func_00b1d470.m();
}
