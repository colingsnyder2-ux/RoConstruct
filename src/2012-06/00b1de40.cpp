// roc 2012-06 00b1de40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de40
//
// 00b1de40  b94cf6e400           mov ecx, 0xe4f64c
// 00b1de45  e9a640a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1de40 { void m(); };
extern T_func_00b1de40 G1_func_00b1de40;
void func_00b1de40()
{
    G1_func_00b1de40.m();
}
