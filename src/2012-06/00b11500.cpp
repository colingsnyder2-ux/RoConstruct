// roc 2012-06 00b11500  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11500
//
// 00b11500  b9b464e100           mov ecx, 0xe164b4
// 00b11505  e9d6838fff           jmp 0x4098e0
// auto-matched from its assembly shape

struct T_func_00b11500 { void m(); };
extern T_func_00b11500 G1_func_00b11500;
void func_00b11500()
{
    G1_func_00b11500.m();
}
