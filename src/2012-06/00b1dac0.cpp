// roc 2012-06 00b1dac0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dac0
//
// 00b1dac0  b95cf2e400           mov ecx, 0xe4f25c
// 00b1dac5  e92644a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1dac0 { void m(); };
extern T_func_00b1dac0 G1_func_00b1dac0;
void func_00b1dac0()
{
    G1_func_00b1dac0.m();
}
