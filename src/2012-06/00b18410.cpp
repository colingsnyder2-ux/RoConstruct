// roc 2012-06 00b18410  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18410
//
// 00b18410  b9c059e300           mov ecx, 0xe359c0
// 00b18415  e9d69aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18410 { void m(); };
extern T_func_00b18410 G1_func_00b18410;
void func_00b18410()
{
    G1_func_00b18410.m();
}
