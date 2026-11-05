// roc 2012-06 00b1b390  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b390
//
// 00b1b390  b9048de400           mov ecx, 0xe48d04
// 00b1b395  e98632c6ff           jmp 0x77e620
// auto-matched from its assembly shape

struct T_func_00b1b390 { void m(); };
extern T_func_00b1b390 G1_func_00b1b390;
void func_00b1b390()
{
    G1_func_00b1b390.m();
}
