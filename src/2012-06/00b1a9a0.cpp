// roc 2012-06 00b1a9a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a9a0
//
// 00b1a9a0  b97094e300           mov ecx, 0xe39470
// 00b1a9a5  e9663dc5ff           jmp 0x76e710
// auto-matched from its assembly shape

struct T_func_00b1a9a0 { void m(); };
extern T_func_00b1a9a0 G1_func_00b1a9a0;
void func_00b1a9a0()
{
    G1_func_00b1a9a0.m();
}
