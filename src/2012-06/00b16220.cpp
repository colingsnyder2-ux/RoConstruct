// roc 2012-06 00b16220  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16220
//
// 00b16220  b98cd6e200           mov ecx, 0xe2d68c
// 00b16225  e9c6bca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16220 { void m(); };
extern T_func_00b16220 G1_func_00b16220;
void func_00b16220()
{
    G1_func_00b16220.m();
}
