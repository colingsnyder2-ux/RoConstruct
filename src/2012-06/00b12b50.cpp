// roc 2012-06 00b12b50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12b50
//
// 00b12b50  b960cae100           mov ecx, 0xe1ca60
// 00b12b55  e916ce8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12b50 { void m(); };
extern T_func_00b12b50 G1_func_00b12b50;
void func_00b12b50()
{
    G1_func_00b12b50.m();
}
