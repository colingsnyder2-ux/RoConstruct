// roc 2012-06 00b1b6b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b6b0
//
// 00b1b6b0  b9208de400           mov ecx, 0xe48d20
// 00b1b6b5  e93668a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b6b0 { void m(); };
extern T_func_00b1b6b0 G1_func_00b1b6b0;
void func_00b1b6b0()
{
    G1_func_00b1b6b0.m();
}
