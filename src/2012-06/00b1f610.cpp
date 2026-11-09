// roc 2012-06 00b1f610  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f610
//
// 00b1f610  b9bc27e500           mov ecx, 0xe527bc
// 00b1f615  e9d628a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f610 { void m(); };
extern T_func_00b1f610 G1_func_00b1f610;
void func_00b1f610()
{
    G1_func_00b1f610.m();
}
