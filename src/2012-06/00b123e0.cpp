// roc 2012-06 00b123e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b123e0
//
// 00b123e0  b94094e100           mov ecx, 0xe19440
// 00b123e5  e9064a95ff           jmp 0x466df0
// auto-matched from its assembly shape

struct T_func_00b123e0 { void m(); };
extern T_func_00b123e0 G1_func_00b123e0;
void func_00b123e0()
{
    G1_func_00b123e0.m();
}
