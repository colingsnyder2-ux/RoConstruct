// roc 2012-06 00b12cd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12cd0
//
// 00b12cd0  b97cdfe100           mov ecx, 0xe1df7c
// 00b12cd5  e9a626a0ff           jmp 0x515380
// auto-matched from its assembly shape

struct T_func_00b12cd0 { void m(); };
extern T_func_00b12cd0 G1_func_00b12cd0;
void func_00b12cd0()
{
    G1_func_00b12cd0.m();
}
