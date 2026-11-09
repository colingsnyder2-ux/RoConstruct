// roc 2012-06 00b1e2d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e2d0
//
// 00b1e2d0  b98801e500           mov ecx, 0xe50188
// 00b1e2d5  e9163ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1e2d0 { void m(); };
extern T_func_00b1e2d0 G1_func_00b1e2d0;
void func_00b1e2d0()
{
    G1_func_00b1e2d0.m();
}
