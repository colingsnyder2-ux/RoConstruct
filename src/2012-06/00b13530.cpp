// roc 2012-06 00b13530  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13530
//
// 00b13530  b9f814e200           mov ecx, 0xe214f8
// 00b13535  e92646a1ff           jmp 0x527b60
// auto-matched from its assembly shape

struct T_func_00b13530 { void m(); };
extern T_func_00b13530 G1_func_00b13530;
void func_00b13530()
{
    G1_func_00b13530.m();
}
