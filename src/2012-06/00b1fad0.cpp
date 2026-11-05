// roc 2012-06 00b1fad0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1fad0
//
// 00b1fad0  b92836e500           mov ecx, 0xe53628
// 00b1fad5  e91624a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1fad0 { void m(); };
extern T_func_00b1fad0 G1_func_00b1fad0;
void func_00b1fad0()
{
    G1_func_00b1fad0.m();
}
