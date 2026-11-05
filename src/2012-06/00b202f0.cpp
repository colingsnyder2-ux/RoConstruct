// roc 2012-06 00b202f0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b202f0
//
// 00b202f0  b9b04ce500           mov ecx, 0xe54cb0
// 00b202f5  e9f61ba7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b202f0 { void m(); };
extern T_func_00b202f0 G1_func_00b202f0;
void func_00b202f0()
{
    G1_func_00b202f0.m();
}
