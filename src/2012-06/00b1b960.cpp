// roc 2012-06 00b1b960  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b960
//
// 00b1b960  b9e892e400           mov ecx, 0xe492e8
// 00b1b965  e98665a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b960 { void m(); };
extern T_func_00b1b960 G1_func_00b1b960;
void func_00b1b960()
{
    G1_func_00b1b960.m();
}
