// roc 2012-06 00b13ac0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13ac0
//
// 00b13ac0  b9581fe200           mov ecx, 0xe21f58
// 00b13ac5  e976bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13ac0 { void m(); };
extern T_func_00b13ac0 G1_func_00b13ac0;
void func_00b13ac0()
{
    G1_func_00b13ac0.m();
}
