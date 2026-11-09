// roc 2012-06 00b1ada0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ada0
//
// 00b1ada0  b9584ce400           mov ecx, 0xe44c58
// 00b1ada5  e9c64b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ada0 { void m(); };
extern T_func_00b1ada0 G1_func_00b1ada0;
void func_00b1ada0()
{
    G1_func_00b1ada0.m();
}
