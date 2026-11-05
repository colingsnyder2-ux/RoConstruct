// roc 2012-06 00b16d20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16d20
//
// 00b16d20  b900ffe200           mov ecx, 0xe2ff00
// 00b16d25  e9468c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b16d20 { void m(); };
extern T_func_00b16d20 G1_func_00b16d20;
void func_00b16d20()
{
    G1_func_00b16d20.m();
}
