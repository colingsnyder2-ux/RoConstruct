// roc 2012-06 00b14840  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14840
//
// 00b14840  b98c4ee200           mov ecx, 0xe24e8c
// 00b14845  e9268ca6ff           jmp 0x57d470
// auto-matched from its assembly shape

struct T_func_00b14840 { void m(); };
extern T_func_00b14840 G1_func_00b14840;
void func_00b14840()
{
    G1_func_00b14840.m();
}
