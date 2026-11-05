// roc 2012-06 00b1d500  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d500
//
// 00b1d500  b904e2e400           mov ecx, 0xe4e204
// 00b1d505  e9e649a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1d500 { void m(); };
extern T_func_00b1d500 G1_func_00b1d500;
void func_00b1d500()
{
    G1_func_00b1d500.m();
}
