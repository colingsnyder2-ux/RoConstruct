// roc 2012-06 00b1d490  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d490
//
// 00b1d490  b9dce4e400           mov ecx, 0xe4e4dc
// 00b1d495  e9564aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d490 { void m(); };
extern T_func_00b1d490 G1_func_00b1d490;
void func_00b1d490()
{
    G1_func_00b1d490.m();
}
