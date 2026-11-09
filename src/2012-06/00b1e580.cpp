// roc 2012-06 00b1e580  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e580
//
// 00b1e580  b9d006e500           mov ecx, 0xe506d0
// 00b1e585  e96639a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1e580 { void m(); };
extern T_func_00b1e580 G1_func_00b1e580;
void func_00b1e580()
{
    G1_func_00b1e580.m();
}
