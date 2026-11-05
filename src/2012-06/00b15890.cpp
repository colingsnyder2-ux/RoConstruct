// roc 2012-06 00b15890  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15890
//
// 00b15890  b9e0a8e200           mov ecx, 0xe2a8e0
// 00b15895  e956c6a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b15890 { void m(); };
extern T_func_00b15890 G1_func_00b15890;
void func_00b15890()
{
    G1_func_00b15890.m();
}
