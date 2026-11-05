// roc 2012-06 00b11970  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11970
//
// 00b11970  b91887e100           mov ecx, 0xe18718
// 00b11975  e906bf91ff           jmp 0x42d880
// auto-matched from its assembly shape

struct T_func_00b11970 { void m(); };
extern T_func_00b11970 G1_func_00b11970;
void func_00b11970()
{
    G1_func_00b11970.m();
}
