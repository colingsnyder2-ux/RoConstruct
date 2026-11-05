// roc 2012-06 00b1f2b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f2b0
//
// 00b1f2b0  b9701fe500           mov ecx, 0xe51f70
// 00b1f2b5  e9362ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f2b0 { void m(); };
extern T_func_00b1f2b0 G1_func_00b1f2b0;
void func_00b1f2b0()
{
    G1_func_00b1f2b0.m();
}
