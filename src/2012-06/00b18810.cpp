// roc 2012-06 00b18810  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18810
//
// 00b18810  b9c062e300           mov ecx, 0xe362c0
// 00b18815  e9d696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18810 { void m(); };
extern T_func_00b18810 G1_func_00b18810;
void func_00b18810()
{
    G1_func_00b18810.m();
}
