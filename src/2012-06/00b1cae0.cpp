// roc 2012-06 00b1cae0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cae0
//
// 00b1cae0  b958d8e400           mov ecx, 0xe4d858
// 00b1cae5  e90654a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1cae0 { void m(); };
extern T_func_00b1cae0 G1_func_00b1cae0;
void func_00b1cae0()
{
    G1_func_00b1cae0.m();
}
