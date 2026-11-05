// roc 2012-06 00b1bec0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bec0
//
// 00b1bec0  b9c0a0e400           mov ecx, 0xe4a0c0
// 00b1bec5  e92660a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bec0 { void m(); };
extern T_func_00b1bec0 G1_func_00b1bec0;
void func_00b1bec0()
{
    G1_func_00b1bec0.m();
}
