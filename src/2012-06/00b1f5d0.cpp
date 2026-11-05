// roc 2012-06 00b1f5d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f5d0
//
// 00b1f5d0  b90029e500           mov ecx, 0xe52900
// 00b1f5d5  e91629a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f5d0 { void m(); };
extern T_func_00b1f5d0 G1_func_00b1f5d0;
void func_00b1f5d0()
{
    G1_func_00b1f5d0.m();
}
