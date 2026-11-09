// roc 2012-06 00b15b10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15b10
//
// 00b15b10  b908aee200           mov ecx, 0xe2ae08
// 00b15b15  e9569e8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15b10 { void m(); };
extern T_func_00b15b10 G1_func_00b15b10;
void func_00b15b10()
{
    G1_func_00b15b10.m();
}
