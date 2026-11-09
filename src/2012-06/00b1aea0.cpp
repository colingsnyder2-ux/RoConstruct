// roc 2012-06 00b1aea0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aea0
//
// 00b1aea0  b9d82de400           mov ecx, 0xe42dd8
// 00b1aea5  e9c64a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aea0 { void m(); };
extern T_func_00b1aea0 G1_func_00b1aea0;
void func_00b1aea0()
{
    G1_func_00b1aea0.m();
}
