// roc 2012-06 00b1ab00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab00
//
// 00b1ab00  b95085e300           mov ecx, 0xe38550
// 00b1ab05  e9a607c5ff           jmp 0x76b2b0
// auto-matched from its assembly shape

struct T_func_00b1ab00 { void m(); };
extern T_func_00b1ab00 G1_func_00b1ab00;
void func_00b1ab00()
{
    G1_func_00b1ab00.m();
}
