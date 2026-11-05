// roc 2012-06 00b16fa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16fa0
//
// 00b16fa0  b9a8ede200           mov ecx, 0xe2eda8
// 00b16fa5  e9a689bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b16fa0 { void m(); };
extern T_func_00b16fa0 G1_func_00b16fa0;
void func_00b16fa0()
{
    G1_func_00b16fa0.m();
}
