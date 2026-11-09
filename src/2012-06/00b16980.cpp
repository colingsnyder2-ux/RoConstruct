// roc 2012-06 00b16980  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16980
//
// 00b16980  b9a8ebe200           mov ecx, 0xe2eba8
// 00b16985  e966b5a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b16980 { void m(); };
extern T_func_00b16980 G1_func_00b16980;
void func_00b16980()
{
    G1_func_00b16980.m();
}
