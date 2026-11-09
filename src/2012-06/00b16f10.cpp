// roc 2012-06 00b16f10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f10
//
// 00b16f10  b9d0f1e200           mov ecx, 0xe2f1d0
// 00b16f15  e9268bd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16f10 { void m(); };
extern T_func_00b16f10 G1_func_00b16f10;
void func_00b16f10()
{
    G1_func_00b16f10.m();
}
