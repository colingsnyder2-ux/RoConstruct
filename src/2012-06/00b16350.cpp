// roc 2012-06 00b16350  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16350
//
// 00b16350  b908dfe200           mov ecx, 0xe2df08
// 00b16355  e916968fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b16350 { void m(); };
extern T_func_00b16350 G1_func_00b16350;
void func_00b16350()
{
    G1_func_00b16350.m();
}
