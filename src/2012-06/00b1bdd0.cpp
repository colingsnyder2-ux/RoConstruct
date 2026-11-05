// roc 2012-06 00b1bdd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bdd0
//
// 00b1bdd0  b9d09ae400           mov ecx, 0xe49ad0
// 00b1bdd5  e976abc7ff           jmp 0x796950
// auto-matched from its assembly shape

struct T_func_00b1bdd0 { void m(); };
extern T_func_00b1bdd0 G1_func_00b1bdd0;
void func_00b1bdd0()
{
    G1_func_00b1bdd0.m();
}
