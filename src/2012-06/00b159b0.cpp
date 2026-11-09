// roc 2012-06 00b159b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b159b0
//
// 00b159b0  b9e8a6e200           mov ecx, 0xe2a6e8
// 00b159b5  e936c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b159b0 { void m(); };
extern T_func_00b159b0 G1_func_00b159b0;
void func_00b159b0()
{
    G1_func_00b159b0.m();
}
