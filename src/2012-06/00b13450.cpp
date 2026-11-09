// roc 2012-06 00b13450  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13450
//
// 00b13450  b92009e200           mov ecx, 0xe20920
// 00b13455  e9166cb9ff           jmp 0x6aa070
// auto-matched from its assembly shape

struct T_func_00b13450 { void m(); };
extern T_func_00b13450 G1_func_00b13450;
void func_00b13450()
{
    G1_func_00b13450.m();
}
