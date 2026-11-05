// roc 2012-06 00b15910  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15910
//
// 00b15910  b900a8e200           mov ecx, 0xe2a800
// 00b15915  e926a1d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b15910 { void m(); };
extern T_func_00b15910 G1_func_00b15910;
void func_00b15910()
{
    G1_func_00b15910.m();
}
