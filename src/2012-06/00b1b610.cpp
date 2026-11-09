// roc 2012-06 00b1b610  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b610
//
// 00b1b610  b9e08ae400           mov ecx, 0xe48ae0
// 00b1b615  e90663c5ff           jmp 0x771920
// auto-matched from its assembly shape

struct T_func_00b1b610 { void m(); };
extern T_func_00b1b610 G1_func_00b1b610;
void func_00b1b610()
{
    G1_func_00b1b610.m();
}
