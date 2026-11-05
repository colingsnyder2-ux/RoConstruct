// roc 2012-06 00b16db0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16db0
//
// 00b16db0  b9c0f3e200           mov ecx, 0xe2f3c0
// 00b16db5  e9868cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16db0 { void m(); };
extern T_func_00b16db0 G1_func_00b16db0;
void func_00b16db0()
{
    G1_func_00b16db0.m();
}
