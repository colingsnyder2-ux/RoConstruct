// roc 2012-06 00b1ab10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab10
//
// 00b1ab10  b9a084e300           mov ecx, 0xe384a0
// 00b1ab15  e9f604c5ff           jmp 0x76b010
// auto-matched from its assembly shape

struct T_func_00b1ab10 { void m(); };
extern T_func_00b1ab10 G1_func_00b1ab10;
void func_00b1ab10()
{
    G1_func_00b1ab10.m();
}
