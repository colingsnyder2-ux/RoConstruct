// roc 2012-06 00b16180  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16180
//
// 00b16180  b9b0d2e200           mov ecx, 0xe2d2b0
// 00b16185  e97661b8ff           jmp 0x69c300
// auto-matched from its assembly shape

struct T_func_00b16180 { void m(); };
extern T_func_00b16180 G1_func_00b16180;
void func_00b16180()
{
    G1_func_00b16180.m();
}
