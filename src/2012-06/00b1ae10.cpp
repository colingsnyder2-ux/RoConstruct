// roc 2012-06 00b1ae10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae10
//
// 00b1ae10  b9003fe400           mov ecx, 0xe43f00
// 00b1ae15  e9564b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae10 { void m(); };
extern T_func_00b1ae10 G1_func_00b1ae10;
void func_00b1ae10()
{
    G1_func_00b1ae10.m();
}
