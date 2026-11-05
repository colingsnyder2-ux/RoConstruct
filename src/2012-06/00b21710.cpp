// roc 2012-06 00b21710  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21710
//
// 00b21710  b9a899e500           mov ecx, 0xe599a8
// 00b21715  e9b68aeaff           jmp 0x9ca1d0
// auto-matched from its assembly shape

struct T_func_00b21710 { void m(); };
extern T_func_00b21710 G1_func_00b21710;
void func_00b21710()
{
    G1_func_00b21710.m();
}
