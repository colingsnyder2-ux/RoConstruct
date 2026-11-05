// roc 2012-06 00b1b270  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b270
//
// 00b1b270  b990b9e300           mov ecx, 0xe3b990
// 00b1b275  e9f6468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b270 { void m(); };
extern T_func_00b1b270 G1_func_00b1b270;
void func_00b1b270()
{
    G1_func_00b1b270.m();
}
