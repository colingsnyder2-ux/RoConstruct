// roc 2012-06 00b135d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b135d0
//
// 00b135d0  b94010e200           mov ecx, 0xe21040
// 00b135d5  e916e9a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b135d0 { void m(); };
extern T_func_00b135d0 G1_func_00b135d0;
void func_00b135d0()
{
    G1_func_00b135d0.m();
}
