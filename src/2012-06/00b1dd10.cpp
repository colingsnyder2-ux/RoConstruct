// roc 2012-06 00b1dd10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd10
//
// 00b1dd10  b988f8e400           mov ecx, 0xe4f888
// 00b1dd15  e9261dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1dd10 { void m(); };
extern T_func_00b1dd10 G1_func_00b1dd10;
void func_00b1dd10()
{
    G1_func_00b1dd10.m();
}
