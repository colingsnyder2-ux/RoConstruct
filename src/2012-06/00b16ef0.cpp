// roc 2012-06 00b16ef0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16ef0
//
// 00b16ef0  b950f1e200           mov ecx, 0xe2f150
// 00b16ef5  e9468bd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16ef0 { void m(); };
extern T_func_00b16ef0 G1_func_00b16ef0;
void func_00b16ef0()
{
    G1_func_00b16ef0.m();
}
