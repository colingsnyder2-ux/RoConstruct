// roc 2012-06 00b1b170  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b170
//
// 00b1b170  b910d8e300           mov ecx, 0xe3d810
// 00b1b175  e9f6478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b170 { void m(); };
extern T_func_00b1b170 G1_func_00b1b170;
void func_00b1b170()
{
    G1_func_00b1b170.m();
}
