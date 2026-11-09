// roc 2012-06 00b156c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b156c0
//
// 00b156c0  b9f096e200           mov ecx, 0xe296f0
// 00b156c5  e926c8a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b156c0 { void m(); };
extern T_func_00b156c0 G1_func_00b156c0;
void func_00b156c0()
{
    G1_func_00b156c0.m();
}
