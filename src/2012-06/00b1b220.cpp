// roc 2012-06 00b1b220  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b220
//
// 00b1b220  b918c3e300           mov ecx, 0xe3c318
// 00b1b225  e946478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b220 { void m(); };
extern T_func_00b1b220 G1_func_00b1b220;
void func_00b1b220()
{
    G1_func_00b1b220.m();
}
