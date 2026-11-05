// roc 2012-06 00b207d0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b207d0
//
// 00b207d0  b92857e500           mov ecx, 0xe55728
// 00b207d5  e91617a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b207d0 { void m(); };
extern T_func_00b207d0 G1_func_00b207d0;
void func_00b207d0()
{
    G1_func_00b207d0.m();
}
