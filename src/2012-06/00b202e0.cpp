// roc 2012-06 00b202e0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b202e0
//
// 00b202e0  b9c84ee500           mov ecx, 0xe54ec8
// 00b202e5  e9061ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b202e0 { void m(); };
extern T_func_00b202e0 G1_func_00b202e0;
void func_00b202e0()
{
    G1_func_00b202e0.m();
}
