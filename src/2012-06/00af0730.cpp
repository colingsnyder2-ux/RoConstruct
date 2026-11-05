// roc 2012-06 00af0730  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0730
//
// 00af0730  b92c73e200           mov ecx, 0xe2732c
// 00af0735  e9f612a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0730 { void m(); };
extern T_func_00af0730 G1_func_00af0730;
void func_00af0730()
{
    G1_func_00af0730.m();
}
