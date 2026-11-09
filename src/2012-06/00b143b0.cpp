// roc 2012-06 00b143b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b143b0
//
// 00b143b0  b92c42e200           mov ecx, 0xe2422c
// 00b143b5  e916b8a4ff           jmp 0x55fbd0
// auto-matched from its assembly shape

struct T_func_00b143b0 { void m(); };
extern T_func_00b143b0 G1_func_00b143b0;
void func_00b143b0()
{
    G1_func_00b143b0.m();
}
