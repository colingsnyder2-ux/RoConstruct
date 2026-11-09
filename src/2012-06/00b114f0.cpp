// roc 2012-06 00b114f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b114f0
//
// 00b114f0  b9b064e100           mov ecx, 0xe164b0
// 00b114f5  e9b6888fff           jmp 0x409db0
// auto-matched from its assembly shape

struct T_func_00b114f0 { void m(); };
extern T_func_00b114f0 G1_func_00b114f0;
void func_00b114f0()
{
    G1_func_00b114f0.m();
}
