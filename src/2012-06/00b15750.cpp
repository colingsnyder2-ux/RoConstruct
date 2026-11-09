// roc 2012-06 00b15750  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15750
//
// 00b15750  b9dca1e200           mov ecx, 0xe2a1dc
// 00b15755  e9269ab6ff           jmp 0x67f180
// auto-matched from its assembly shape

struct T_func_00b15750 { void m(); };
extern T_func_00b15750 G1_func_00b15750;
void func_00b15750()
{
    G1_func_00b15750.m();
}
