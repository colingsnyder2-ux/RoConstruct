// roc 2012-06 00b1d4d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d4d0
//
// 00b1d4d0  b950e4e400           mov ecx, 0xe4e450
// 00b1d4d5  e9164aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d4d0 { void m(); };
extern T_func_00b1d4d0 G1_func_00b1d4d0;
void func_00b1d4d0()
{
    G1_func_00b1d4d0.m();
}
