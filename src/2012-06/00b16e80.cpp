// roc 2012-06 00b16e80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16e80
//
// 00b16e80  b9e800e300           mov ecx, 0xe300e8
// 00b16e85  e90677bcff           jmp 0x6de590
// auto-matched from its assembly shape

struct T_func_00b16e80 { void m(); };
extern T_func_00b16e80 G1_func_00b16e80;
void func_00b16e80()
{
    G1_func_00b16e80.m();
}
