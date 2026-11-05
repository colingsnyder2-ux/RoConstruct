// roc 2012-06 00b1f630  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f630
//
// 00b1f630  b98c29e500           mov ecx, 0xe5298c
// 00b1f635  e9b628a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f630 { void m(); };
extern T_func_00b1f630 G1_func_00b1f630;
void func_00b1f630()
{
    G1_func_00b1f630.m();
}
