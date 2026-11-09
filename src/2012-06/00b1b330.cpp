// roc 2012-06 00b1b330  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b330
//
// 00b1b330  b9b0a2e300           mov ecx, 0xe3a2b0
// 00b1b335  e936468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b330 { void m(); };
extern T_func_00b1b330 G1_func_00b1b330;
void func_00b1b330()
{
    G1_func_00b1b330.m();
}
