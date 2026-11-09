// roc 2012-06 00b18c90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18c90
//
// 00b18c90  b9c874e300           mov ecx, 0xe374c8
// 00b18c95  e9a6c8c4ff           jmp 0x765540
// auto-matched from its assembly shape

struct T_func_00b18c90 { void m(); };
extern T_func_00b18c90 G1_func_00b18c90;
void func_00b18c90()
{
    G1_func_00b18c90.m();
}
