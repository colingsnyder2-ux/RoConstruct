// roc 2012-06 00b1f5e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f5e0
//
// 00b1f5e0  b97428e500           mov ecx, 0xe52874
// 00b1f5e5  e90629a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f5e0 { void m(); };
extern T_func_00b1f5e0 G1_func_00b1f5e0;
void func_00b1f5e0()
{
    G1_func_00b1f5e0.m();
}
