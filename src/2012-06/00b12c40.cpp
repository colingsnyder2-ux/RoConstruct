// roc 2012-06 00b12c40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c40
//
// 00b12c40  b938d5e100           mov ecx, 0xe1d538
// 00b12c45  e926cd8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12c40 { void m(); };
extern T_func_00b12c40 G1_func_00b12c40;
void func_00b12c40()
{
    G1_func_00b12c40.m();
}
