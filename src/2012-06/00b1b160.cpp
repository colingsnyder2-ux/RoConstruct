// roc 2012-06 00b1b160  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b160
//
// 00b1b160  b9f8d9e300           mov ecx, 0xe3d9f8
// 00b1b165  e906488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b160 { void m(); };
extern T_func_00b1b160 G1_func_00b1b160;
void func_00b1b160()
{
    G1_func_00b1b160.m();
}
