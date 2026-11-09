// roc 2012-06 00aefd80  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aefd80
//
// 00aefd80  b99045e200           mov ecx, 0xe24590
// 00aefd85  e9a61ca7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aefd80 { void m(); };
extern T_func_00aefd80 G1_func_00aefd80;
void func_00aefd80()
{
    G1_func_00aefd80.m();
}
