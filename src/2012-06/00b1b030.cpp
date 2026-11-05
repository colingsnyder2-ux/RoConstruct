// roc 2012-06 00b1b030  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b030
//
// 00b1b030  b930fee300           mov ecx, 0xe3fe30
// 00b1b035  e936498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b030 { void m(); };
extern T_func_00b1b030 G1_func_00b1b030;
void func_00b1b030()
{
    G1_func_00b1b030.m();
}
