// roc 2012-06 00b16000  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16000
//
// 00b16000  b9c0c3e200           mov ecx, 0xe2c3c0
// 00b16005  e9e6bea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16000 { void m(); };
extern T_func_00b16000 G1_func_00b16000;
void func_00b16000()
{
    G1_func_00b16000.m();
}
