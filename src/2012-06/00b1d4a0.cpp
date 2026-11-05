// roc 2012-06 00b1d4a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d4a0
//
// 00b1d4a0  b9c0dfe400           mov ecx, 0xe4dfc0
// 00b1d4a5  e9464aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d4a0 { void m(); };
extern T_func_00b1d4a0 G1_func_00b1d4a0;
void func_00b1d4a0()
{
    G1_func_00b1d4a0.m();
}
