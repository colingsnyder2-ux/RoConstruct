// roc 2012-06 00b1c150  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c150
//
// 00b1c150  b938a9e400           mov ecx, 0xe4a938
// 00b1c155  e91650b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1c150 { void m(); };
extern T_func_00b1c150 G1_func_00b1c150;
void func_00b1c150()
{
    G1_func_00b1c150.m();
}
