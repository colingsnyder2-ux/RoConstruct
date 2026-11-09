// roc 2012-06 00b1d440  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d440
//
// 00b1d440  b980e4e400           mov ecx, 0xe4e480
// 00b1d445  e9a64aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d440 { void m(); };
extern T_func_00b1d440 G1_func_00b1d440;
void func_00b1d440()
{
    G1_func_00b1d440.m();
}
