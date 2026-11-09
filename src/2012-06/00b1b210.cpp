// roc 2012-06 00b1b210  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b210
//
// 00b1b210  b900c5e300           mov ecx, 0xe3c500
// 00b1b215  e956478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b210 { void m(); };
extern T_func_00b1b210 G1_func_00b1b210;
void func_00b1b210()
{
    G1_func_00b1b210.m();
}
