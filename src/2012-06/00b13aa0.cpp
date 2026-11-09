// roc 2012-06 00b13aa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13aa0
//
// 00b13aa0  b9d81ee200           mov ecx, 0xe21ed8
// 00b13aa5  e996bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13aa0 { void m(); };
extern T_func_00b13aa0 G1_func_00b13aa0;
void func_00b13aa0()
{
    G1_func_00b13aa0.m();
}
