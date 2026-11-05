// roc 2012-06 00b1aad0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aad0
//
// 00b1aad0  b96087e300           mov ecx, 0xe38760
// 00b1aad5  e9b60fc5ff           jmp 0x76ba90
// auto-matched from its assembly shape

struct T_func_00b1aad0 { void m(); };
extern T_func_00b1aad0 G1_func_00b1aad0;
void func_00b1aad0()
{
    G1_func_00b1aad0.m();
}
