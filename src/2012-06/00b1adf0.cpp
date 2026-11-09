// roc 2012-06 00b1adf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1adf0
//
// 00b1adf0  b9d042e400           mov ecx, 0xe442d0
// 00b1adf5  e9764b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1adf0 { void m(); };
extern T_func_00b1adf0 G1_func_00b1adf0;
void func_00b1adf0()
{
    G1_func_00b1adf0.m();
}
