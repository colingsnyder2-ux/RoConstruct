// roc 2012-06 00aeea40  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeea40
//
// 00aeea40  b91826e200           mov ecx, 0xe22618
// 00aeea45  e9e62fa7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aeea40 { void m(); };
extern T_func_00aeea40 G1_func_00aeea40;
void func_00aeea40()
{
    G1_func_00aeea40.m();
}
