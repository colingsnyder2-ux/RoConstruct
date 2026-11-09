// roc 2012-06 00b159c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b159c0
//
// 00b159c0  b9e0a5e200           mov ecx, 0xe2a5e0
// 00b159c5  e926c5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b159c0 { void m(); };
extern T_func_00b159c0 G1_func_00b159c0;
void func_00b159c0()
{
    G1_func_00b159c0.m();
}
