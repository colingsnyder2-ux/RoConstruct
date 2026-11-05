// roc 2012-06 00b179f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b179f0
//
// 00b179f0  b9702be300           mov ecx, 0xe32b70
// 00b179f5  e9767f8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b179f0 { void m(); };
extern T_func_00b179f0 G1_func_00b179f0;
void func_00b179f0()
{
    G1_func_00b179f0.m();
}
