// roc 2012-06 00b1bfa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bfa0
//
// 00b1bfa0  b9e0a5e400           mov ecx, 0xe4a5e0
// 00b1bfa5  e99695c4ff           jmp 0x765540
// auto-matched from its assembly shape

struct T_func_00b1bfa0 { void m(); };
extern T_func_00b1bfa0 G1_func_00b1bfa0;
void func_00b1bfa0()
{
    G1_func_00b1bfa0.m();
}
