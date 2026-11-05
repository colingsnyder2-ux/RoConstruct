// roc 2012-06 00b1caa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1caa0
//
// 00b1caa0  b900d5e400           mov ecx, 0xe4d500
// 00b1caa5  e94654a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1caa0 { void m(); };
extern T_func_00b1caa0 G1_func_00b1caa0;
void func_00b1caa0()
{
    G1_func_00b1caa0.m();
}
