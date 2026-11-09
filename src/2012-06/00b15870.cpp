// roc 2012-06 00b15870  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15870
//
// 00b15870  b958a3e200           mov ecx, 0xe2a358
// 00b15875  e9d6a0bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b15870 { void m(); };
extern T_func_00b15870 G1_func_00b15870;
void func_00b15870()
{
    G1_func_00b15870.m();
}
