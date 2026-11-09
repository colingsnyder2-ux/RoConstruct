// roc 2012-06 00b1de30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1de30
//
// 00b1de30  b910f6e400           mov ecx, 0xe4f610
// 00b1de35  e9b640a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1de30 { void m(); };
extern T_func_00b1de30 G1_func_00b1de30;
void func_00b1de30()
{
    G1_func_00b1de30.m();
}
