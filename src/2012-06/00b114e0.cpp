// roc 2012-06 00b114e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b114e0
//
// 00b114e0  b9ac64e100           mov ecx, 0xe164ac
// 00b114e5  e9968d8fff           jmp 0x40a280
// auto-matched from its assembly shape

struct T_func_00b114e0 { void m(); };
extern T_func_00b114e0 G1_func_00b114e0;
void func_00b114e0()
{
    G1_func_00b114e0.m();
}
