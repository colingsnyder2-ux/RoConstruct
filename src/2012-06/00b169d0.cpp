// roc 2012-06 00b169d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b169d0
//
// 00b169d0  b978ebe200           mov ecx, 0xe2eb78
// 00b169d5  e916b5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b169d0 { void m(); };
extern T_func_00b169d0 G1_func_00b169d0;
void func_00b169d0()
{
    G1_func_00b169d0.m();
}
