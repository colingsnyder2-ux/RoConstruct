// roc 2012-06 00b158a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b158a0
//
// 00b158a0  b9c8a7e200           mov ecx, 0xe2a7c8
// 00b158a5  e946c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b158a0 { void m(); };
extern T_func_00b158a0 G1_func_00b158a0;
void func_00b158a0()
{
    G1_func_00b158a0.m();
}
