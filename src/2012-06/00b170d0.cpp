// roc 2012-06 00b170d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b170d0
//
// 00b170d0  b9e0eee200           mov ecx, 0xe2eee0
// 00b170d5  e916aea7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b170d0 { void m(); };
extern T_func_00b170d0 G1_func_00b170d0;
void func_00b170d0()
{
    G1_func_00b170d0.m();
}
