// roc 2012-06 00b1b910  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b910
//
// 00b1b910  b95891e400           mov ecx, 0xe49158
// 00b1b915  e9d665a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b910 { void m(); };
extern T_func_00b1b910 G1_func_00b1b910;
void func_00b1b910()
{
    G1_func_00b1b910.m();
}
