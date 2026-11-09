// roc 2012-06 00b189c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b189c0
//
// 00b189c0  b9506be300           mov ecx, 0xe36b50
// 00b189c5  e92695a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b189c0 { void m(); };
extern T_func_00b189c0 G1_func_00b189c0;
void func_00b189c0()
{
    G1_func_00b189c0.m();
}
