// roc 2012-06 00b171d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b171d0
//
// 00b171d0  b96009e300           mov ecx, 0xe30960
// 00b171d5  e916ada7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b171d0 { void m(); };
extern T_func_00b171d0 G1_func_00b171d0;
void func_00b171d0()
{
    G1_func_00b171d0.m();
}
