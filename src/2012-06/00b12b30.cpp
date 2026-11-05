// roc 2012-06 00b12b30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12b30
//
// 00b12b30  b930cee100           mov ecx, 0xe1ce30
// 00b12b35  e936ce8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12b30 { void m(); };
extern T_func_00b12b30 G1_func_00b12b30;
void func_00b12b30()
{
    G1_func_00b12b30.m();
}
