// roc 2012-06 00b14860  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14860
//
// 00b14860  b9a44ee200           mov ecx, 0xe24ea4
// 00b14865  e96682a6ff           jmp 0x57cad0
// auto-matched from its assembly shape

struct T_func_00b14860 { void m(); };
extern T_func_00b14860 G1_func_00b14860;
void func_00b14860()
{
    G1_func_00b14860.m();
}
