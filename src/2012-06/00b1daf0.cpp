// roc 2012-06 00b1daf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1daf0
//
// 00b1daf0  b9ccf0e400           mov ecx, 0xe4f0cc
// 00b1daf5  e9f643a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1daf0 { void m(); };
extern T_func_00b1daf0 G1_func_00b1daf0;
void func_00b1daf0()
{
    G1_func_00b1daf0.m();
}
