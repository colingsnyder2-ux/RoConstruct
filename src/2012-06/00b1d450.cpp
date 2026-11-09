// roc 2012-06 00b1d450  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d450
//
// 00b1d450  b984e0e400           mov ecx, 0xe4e084
// 00b1d455  e9964aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d450 { void m(); };
extern T_func_00b1d450 G1_func_00b1d450;
void func_00b1d450()
{
    G1_func_00b1d450.m();
}
