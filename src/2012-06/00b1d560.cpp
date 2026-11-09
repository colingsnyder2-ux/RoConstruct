// roc 2012-06 00b1d560  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d560
//
// 00b1d560  b974e6e400           mov ecx, 0xe4e674
// 00b1d565  e98649a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d560 { void m(); };
extern T_func_00b1d560 G1_func_00b1d560;
void func_00b1d560()
{
    G1_func_00b1d560.m();
}
