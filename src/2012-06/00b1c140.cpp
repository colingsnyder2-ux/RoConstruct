// roc 2012-06 00b1c140  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c140
//
// 00b1c140  b9e8a9e400           mov ecx, 0xe4a9e8
// 00b1c145  e92650b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1c140 { void m(); };
extern T_func_00b1c140 G1_func_00b1c140;
void func_00b1c140()
{
    G1_func_00b1c140.m();
}
