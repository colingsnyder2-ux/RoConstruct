// roc 2012-06 00b1acd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1acd0
//
// 00b1acd0  b92065e400           mov ecx, 0xe46520
// 00b1acd5  e9964c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1acd0 { void m(); };
extern T_func_00b1acd0 G1_func_00b1acd0;
void func_00b1acd0()
{
    G1_func_00b1acd0.m();
}
