// roc 2012-06 00b114c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b114c0
//
// 00b114c0  b92464e100           mov ecx, 0xe16424
// 00b114c5  e9661c8fff           jmp 0x403130
// auto-matched from its assembly shape

struct T_func_00b114c0 { void m(); };
extern T_func_00b114c0 G1_func_00b114c0;
void func_00b114c0()
{
    G1_func_00b114c0.m();
}
