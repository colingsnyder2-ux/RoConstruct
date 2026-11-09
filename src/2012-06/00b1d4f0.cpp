// roc 2012-06 00b1d4f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d4f0
//
// 00b1d4f0  b938e3e400           mov ecx, 0xe4e338
// 00b1d4f5  e9f649a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d4f0 { void m(); };
extern T_func_00b1d4f0 G1_func_00b1d4f0;
void func_00b1d4f0()
{
    G1_func_00b1d4f0.m();
}
