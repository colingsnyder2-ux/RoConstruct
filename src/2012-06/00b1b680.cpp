// roc 2012-06 00b1b680  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b680
//
// 00b1b680  b9908de400           mov ecx, 0xe48d90
// 00b1b685  e96668a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b680 { void m(); };
extern T_func_00b1b680 G1_func_00b1b680;
void func_00b1b680()
{
    G1_func_00b1b680.m();
}
