// roc 2012-06 00b204a0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b204a0
//
// 00b204a0  b97851e500           mov ecx, 0xe55178
// 00b204a5  e9461aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b204a0 { void m(); };
extern T_func_00b204a0 G1_func_00b204a0;
void func_00b204a0()
{
    G1_func_00b204a0.m();
}
