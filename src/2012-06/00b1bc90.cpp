// roc 2012-06 00b1bc90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bc90
//
// 00b1bc90  b9589de400           mov ecx, 0xe49d58
// 00b1bc95  e95662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bc90 { void m(); };
extern T_func_00b1bc90 G1_func_00b1bc90;
void func_00b1bc90()
{
    G1_func_00b1bc90.m();
}
