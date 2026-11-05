// roc 2012-06 00b12c30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c30
//
// 00b12c30  b920d7e100           mov ecx, 0xe1d720
// 00b12c35  e936cd8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12c30 { void m(); };
extern T_func_00b12c30 G1_func_00b12c30;
void func_00b12c30()
{
    G1_func_00b12c30.m();
}
