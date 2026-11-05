// roc 2012-06 00b1f1f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f1f0
//
// 00b1f1f0  b9e01ee500           mov ecx, 0xe51ee0
// 00b1f1f5  e9a661d6ff           jmp 0x8853a0
// auto-matched from its assembly shape

struct T_func_00b1f1f0 { void m(); };
extern T_func_00b1f1f0 G1_func_00b1f1f0;
void func_00b1f1f0()
{
    G1_func_00b1f1f0.m();
}
