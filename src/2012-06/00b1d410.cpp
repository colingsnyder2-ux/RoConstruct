// roc 2012-06 00b1d410  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d410
//
// 00b1d410  b974e1e400           mov ecx, 0xe4e174
// 00b1d415  e9d64aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d410 { void m(); };
extern T_func_00b1d410 G1_func_00b1d410;
void func_00b1d410()
{
    G1_func_00b1d410.m();
}
