// roc 2012-06 00b1b720  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b720
//
// 00b1b720  b9708fe400           mov ecx, 0xe48f70
// 00b1b725  e9465ab6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1b720 { void m(); };
extern T_func_00b1b720 G1_func_00b1b720;
void func_00b1b720()
{
    G1_func_00b1b720.m();
}
