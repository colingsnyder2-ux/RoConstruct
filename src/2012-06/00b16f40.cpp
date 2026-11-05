// roc 2012-06 00b16f40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16f40
//
// 00b16f40  b9d0ece200           mov ecx, 0xe2ecd0
// 00b16f45  e9a6afa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16f40 { void m(); };
extern T_func_00b16f40 G1_func_00b16f40;
void func_00b16f40()
{
    G1_func_00b16f40.m();
}
