// roc 2012-06 00b16f50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f50
//
// 00b16f50  b9f0f6e200           mov ecx, 0xe2f6f0
// 00b16f55  e91689bcff           jmp 0x6df870
// auto-matched from its assembly shape

struct T_func_00b16f50 { void m(); };
extern T_func_00b16f50 G1_func_00b16f50;
void func_00b16f50()
{
    G1_func_00b16f50.m();
}
