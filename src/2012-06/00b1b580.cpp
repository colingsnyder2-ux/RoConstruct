// roc 2012-06 00b1b580  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b580
//
// 00b1b580  b9e88ae400           mov ecx, 0xe48ae8
// 00b1b585  e90690c5ff           jmp 0x774590
// auto-matched from its assembly shape

struct T_func_00b1b580 { void m(); };
extern T_func_00b1b580 G1_func_00b1b580;
void func_00b1b580()
{
    G1_func_00b1b580.m();
}
