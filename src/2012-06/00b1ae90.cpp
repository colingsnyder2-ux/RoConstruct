// roc 2012-06 00b1ae90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae90
//
// 00b1ae90  b9c02fe400           mov ecx, 0xe42fc0
// 00b1ae95  e9d64a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae90 { void m(); };
extern T_func_00b1ae90 G1_func_00b1ae90;
void func_00b1ae90()
{
    G1_func_00b1ae90.m();
}
