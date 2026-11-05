// roc 2012-06 00af0610  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0610
//
// 00af0610  b9a85be200           mov ecx, 0xe25ba8
// 00af0615  e91614a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0610 { void m(); };
extern T_func_00af0610 G1_func_00af0610;
void func_00af0610()
{
    G1_func_00af0610.m();
}
