// roc 2012-06 00b134e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b134e0
//
// 00b134e0  b9e814e200           mov ecx, 0xe214e8
// 00b134e5  e9765ca1ff           jmp 0x529160
// auto-matched from its assembly shape

struct T_func_00b134e0 { void m(); };
extern T_func_00b134e0 G1_func_00b134e0;
void func_00b134e0()
{
    G1_func_00b134e0.m();
}
