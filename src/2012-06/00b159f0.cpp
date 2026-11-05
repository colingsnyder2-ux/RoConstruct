// roc 2012-06 00b159f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b159f0
//
// 00b159f0  b9d0a3e200           mov ecx, 0xe2a3d0
// 00b159f5  e9f6c4a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b159f0 { void m(); };
extern T_func_00b159f0 G1_func_00b159f0;
void func_00b159f0()
{
    G1_func_00b159f0.m();
}
