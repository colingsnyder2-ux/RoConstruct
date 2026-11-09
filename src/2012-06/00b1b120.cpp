// roc 2012-06 00b1b120  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b120
//
// 00b1b120  b998e1e300           mov ecx, 0xe3e198
// 00b1b125  e946488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b120 { void m(); };
extern T_func_00b1b120 G1_func_00b1b120;
void func_00b1b120()
{
    G1_func_00b1b120.m();
}
