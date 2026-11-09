// roc 2012-06 00b13eb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13eb0
//
// 00b13eb0  b9082de200           mov ecx, 0xe22d08
// 00b13eb5  e9b6ba8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13eb0 { void m(); };
extern T_func_00b13eb0 G1_func_00b13eb0;
void func_00b13eb0()
{
    G1_func_00b13eb0.m();
}
