// roc 2012-06 00b202a0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b202a0
//
// 00b202a0  b9884de500           mov ecx, 0xe54d88
// 00b202a5  e9461ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b202a0 { void m(); };
extern T_func_00b202a0 G1_func_00b202a0;
void func_00b202a0()
{
    G1_func_00b202a0.m();
}
