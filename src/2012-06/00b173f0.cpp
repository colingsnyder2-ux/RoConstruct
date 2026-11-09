// roc 2012-06 00b173f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b173f0
//
// 00b173f0  b9f017e300           mov ecx, 0xe317f0
// 00b173f5  e9f6aaa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b173f0 { void m(); };
extern T_func_00b173f0 G1_func_00b173f0;
void func_00b173f0()
{
    G1_func_00b173f0.m();
}
