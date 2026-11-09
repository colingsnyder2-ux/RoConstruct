// roc 2012-06 00b1f240  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f240
//
// 00b1f240  b9b022e500           mov ecx, 0xe522b0
// 00b1f245  e9a62ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f240 { void m(); };
extern T_func_00b1f240 G1_func_00b1f240;
void func_00b1f240()
{
    G1_func_00b1f240.m();
}
