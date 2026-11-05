// roc 2012-06 00b1ab90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab90
//
// 00b1ab90  b9207fe300           mov ecx, 0xe37f20
// 00b1ab95  e9d6f1c4ff           jmp 0x769d70
// auto-matched from its assembly shape

struct T_func_00b1ab90 { void m(); };
extern T_func_00b1ab90 G1_func_00b1ab90;
void func_00b1ab90()
{
    G1_func_00b1ab90.m();
}
