// roc 2012-06 00b16f20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f20
//
// 00b16f20  b968ede200           mov ecx, 0xe2ed68
// 00b16f25  e9268abcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b16f20 { void m(); };
extern T_func_00b16f20 G1_func_00b16f20;
void func_00b16f20()
{
    G1_func_00b16f20.m();
}
