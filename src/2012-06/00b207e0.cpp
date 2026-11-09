// roc 2012-06 00b207e0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b207e0
//
// 00b207e0  b9f056e500           mov ecx, 0xe556f0
// 00b207e5  e90617a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b207e0 { void m(); };
extern T_func_00b207e0 G1_func_00b207e0;
void func_00b207e0()
{
    G1_func_00b207e0.m();
}
