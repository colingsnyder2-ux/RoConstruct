// roc 2012-06 00b1ab60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab60
//
// 00b1ab60  b93081e300           mov ecx, 0xe38130
// 00b1ab65  e926fac4ff           jmp 0x76a590
// auto-matched from its assembly shape

struct T_func_00b1ab60 { void m(); };
extern T_func_00b1ab60 G1_func_00b1ab60;
void func_00b1ab60()
{
    G1_func_00b1ab60.m();
}
