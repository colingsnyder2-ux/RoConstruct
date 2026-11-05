// roc 2012-06 00b10020  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10020
//
// 00b10020  b9636de500           mov ecx, 0xe56d63
// 00b10025  e9d65ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10020 { void m(); };
extern T_func_00b10020 G1_func_00b10020;
void func_00b10020()
{
    G1_func_00b10020.m();
}
