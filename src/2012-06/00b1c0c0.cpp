// roc 2012-06 00b1c0c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c0c0
//
// 00b1c0c0  b998a8e400           mov ecx, 0xe4a898
// 00b1c0c5  e9a650b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1c0c0 { void m(); };
extern T_func_00b1c0c0 G1_func_00b1c0c0;
void func_00b1c0c0()
{
    G1_func_00b1c0c0.m();
}
