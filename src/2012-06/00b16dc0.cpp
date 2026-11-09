// roc 2012-06 00b16dc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16dc0
//
// 00b16dc0  b910efe200           mov ecx, 0xe2ef10
// 00b16dc5  e926b1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16dc0 { void m(); };
extern T_func_00b16dc0 G1_func_00b16dc0;
void func_00b16dc0()
{
    G1_func_00b16dc0.m();
}
