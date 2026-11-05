// roc 2012-06 00b1caf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1caf0
//
// 00b1caf0  b9a0d1e400           mov ecx, 0xe4d1a0
// 00b1caf5  e9f653a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1caf0 { void m(); };
extern T_func_00b1caf0 G1_func_00b1caf0;
void func_00b1caf0()
{
    G1_func_00b1caf0.m();
}
