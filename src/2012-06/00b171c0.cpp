// roc 2012-06 00b171c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b171c0
//
// 00b171c0  b9e008e300           mov ecx, 0xe308e0
// 00b171c5  e97688d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b171c0 { void m(); };
extern T_func_00b171c0 G1_func_00b171c0;
void func_00b171c0()
{
    G1_func_00b171c0.m();
}
